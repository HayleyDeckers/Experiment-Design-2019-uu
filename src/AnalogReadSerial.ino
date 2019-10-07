/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  //increase the analogread resolution because we use a Due
  analogReadResolution(12);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

uint16_t output = 0;

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  uint16_t sensorValue = analogRead(A0);
  output = 3*(output/4)+sensorValue/4;
  //uint16_t flush_val = 0xffff;
  //uint16_t write_val[] = {sensorValue, flush_val};
  //sensorValue++;
  // print out the value you read:
  //Serial.write((const char*)&write_val,sizeof(write_val));
  Serial.println(output);
  //Serial.flush();
  //Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
