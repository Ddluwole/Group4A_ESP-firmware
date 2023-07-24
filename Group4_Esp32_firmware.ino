const int analogOutputPin = 9; // The analog output pin on the esp

void setup() {
  pinMode(analogOutputPin, OUTPUT); // Set the analog output pin as an output
  Serial.begin(9600); // Initialize Serial communication for debugging (optional)
}

void loop() {
  if (Serial.available() > 0) {
    // Read the value received from Python (0-255)
    int inputValue = Serial.parseInt();
    // Map the input value to the voltage range (0-3.3V)
    float outputVoltage = map(inputValue, 0, 255, 0, 3.3); // re-maps inputValue from a range of 0-255 to a range 0-3300  
    // float outputVoltage = outputValue/1000 // Divide by 1000 to convert the millivolvoltage in volts
    
    // Output the value in the serial monitor (optional)
    Serial.print("Received input value: ");
    Serial.print(inputValue);
    Serial.print(", Output voltage: ");
    Serial.print(outputVoltage, 2); // Print the voltage with 2 decimal places
    Serial.println(" V");
    
    // Output the voltage signal to the analog pin
    analogWrite(analogOutputPin, inputValue);
  }
}