#include <HardwareSerial.h>

// Configure DAC pins
const int dac1 = 25;
const int dac2 = 26;


void setup() {
  // Initialize baud rate for serial communication
  Serial.begin(9600);

  // Configure DAC pins
  pinMode(dac1, OUTPUT);
  pinMode(dac2, OUTPUT);
}

void loop() {
  // Wait for serial input
  while (Serial.available() < 1) {
    delay(500);
  }

  // Read serial input and remove leading/trailing whitespaces
  String input_values = Serial.readStringUntil('\n');
  input_values.trim();

  // Find the position of the comma in the input string
  int comma_index = input_values.indexOf(",");
  if (comma_index < 0) {
  // If no comma found, exit the loop and wait for the next input
    return; 
  }

  // Extract the substrings before and after the comma
  String digital_value1_ = input_values.substring(0, comma_index);
  String digital_value2_ = input_values.substring(comma_index + 1);

  // Convert the string values to float integer type

  float digital_value1 = digital_value1_.toFloat();
  float digital_value2 = digital_value2_.toFloat();

  // Convert the floating-point values to voltages
  float first_voltage = (digital_value1 / 255.0) * 3.3;
  float second_voltage = (digital_value2 / 255.0) * 3.3;

  // Output voltages to DAC pins (converting voltage to 8-bit DAC value)
  dacWrite(dac1, (int)((first_voltage / 3.3) * 255));
  dacWrite(dac2, (int)((second_voltage / 3.3) * 255));

}
