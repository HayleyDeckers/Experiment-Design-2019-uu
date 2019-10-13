/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/


//used for handshaking
String inputString = "";         // a String to hold incoming data
bool handshakeComplete = false;  // whether the string is complete
bool realtime = false;

#define BUFFER_SIZE 2048
uint16_t buffer[BUFFER_SIZE];
uint16_t buffer_head = 0;

// the setup routine runs once when you press reset:
void setup() {
  //reserve some space for our string.
  inputString.reserve(200);
  //increase the analogread resolution because we use a Due
  //analogReadResolution(12);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  //Wait on the serial interface to be connected
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

uint16_t output = 0;
// the loop routine runs over and over again forever:
void loop() {
  if(handshakeComplete){
    // read the input on analog pin 0:
    uint16_t sensorValue = analogRead(A0);
    //put the result into a buffer
    if(!realtime){
      buffer[buffer_head++] = (output/4)*3 +sensorValue/4;
      if(buffer_head >= BUFFER_SIZE){
        Serial.write((const char*)buffer, sizeof(buffer[0])*BUFFER_SIZE);
        buffer_head = 0;
      }
    }else{
      uint16_t write_val[] = {sensorValue, 0xffff};
      Serial.write((const char*)&write_val,4);
    }
    delay(1); // delay in between reads for stability.
    //n.b. for an iron sample, of around 10cm, a 10ms delay between
    // the coefficient of expansion of iron is around 15e-6 per Kelvin.
    // for a 10cm rod of iron that mean an expansion of 15e-7 m/K
    // we can measure half-wavelengths with our setup, if we measure once per 100ms (= 10Hz = much slower than our electronics)
    // that means the maximum expansion we can measure is 3.25e-6 m/s
    // Combining this we get that the maximum change in temprature per time we could measure is 2.16 K/s.
    // so a delay of 10ms will be more than short enough to get useful data.
  } else {
    while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();

    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    //Serial.println(inputString);
    //TODO: use a commands enum.
    if (inChar == '\n') {
      if(inputString.equals("REALTIME\n")){
        Serial.write("ACKN");
        realtime = true;
        handshakeComplete = true;
      }else if(inputString.equals("BATCH\n")){
        Serial.write("ACKN");
        realtime = false;
        handshakeComplete = true;
      }else{
        inputString = "";
      }
    }
  }
  }

}
