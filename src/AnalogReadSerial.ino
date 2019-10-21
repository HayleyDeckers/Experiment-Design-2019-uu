//used for handshaking
String inputString = "";         // a String to hold incoming data
bool handshakeComplete = false;  // whether the string is complete

//A
typedef struct DataPacket{
  uint16_t photosensor;
  uint16_t thermocouple;
  uint32_t timestamp_in_ms;
}DataPacket_t;

#define BUFFER_SIZE 4096/sizeof(DataPacket)
DataPacket_t buffer[BUFFER_SIZE];
uint16_t buffer_head = 0;

// the setup routine runs once when you press reset:
void setup() {
  //reserve some space for our string.
  inputString.reserve(200);
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  //Wait on the serial interface to be connected
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  while(!handshakeComplete){
    while (Serial.available()) {
      // get the new byte:
      char inChar = (char)Serial.read();
      //TODO: check that string doesn't grow beyond 200 bytes
      // add it to the inputString:
      inputString += inChar;
      //TODO: use a commands enum instead
      // a newline character '\n' is used as a command delimiter
      if (inChar == '\n') {
        if(inputString.equals("THERMITE\n")){
          //Write "ACKN" so that the other end knows that we are ready to start sending data.
          // sometimes a serial buffer might still contain some random noise, this also helps get rid of that.
          Serial.write("ACKN");
          handshakeComplete = true;
        }else{
          //if we didn't get any commands, clear the buffer.
          inputString = "";
        }
      }
    }
  }
}

DataPacket_t measurement;
// the loop routine runs over and over again forever:
void loop() {
  measurement.photosensor = analogRead(A0);
  measurement.timestamp_in_ms = millis();
  measurement.thermocouple = analogRead(A1);

  buffer[buffer_head] = measurement;
  buffer_head += 1;
  //if the buffer is now full
  if(buffer_head >= BUFFER_SIZE){
    //flush the buffer
    Serial.write((const char*)buffer, sizeof(measurement)*BUFFER_SIZE);
    //and reset the head
    buffer_head = 0;
  }
  delay(1); // delay in between reads for stability.
  //n.b. for an iron sample, of around 10cm, a 10ms delay between
  // the coefficient of expansion of iron is around 15e-6 per Kelvin.
  // for a 10cm rod of iron that mean an expansion of 15e-7 m/K
  // we can measure half-wavelengths with our setup, if we measure once per 100ms (= 10Hz = much slower than our electronics)
  // that means the maximum expansion we can measure is 3.25e-6 m/s
  // Combining this we get that the maximum change in temprature per time we could measure is 2.16 K/s.
  // so a delay of 1ms will be more than short enough to get useful data.
}
