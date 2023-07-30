const int dacPin1 = 25; // DAC output pin for set 1
const int dacPin2 = 26; // DAC output pin for set 2

void setup() {
  pinMode(dacPin1, INPUT);
  pinMode(dacPin2, INPUT);
  Serial.begin(9600); // Initialize Serial communication for debugging (optional)

}

void loop() {
  if (Serial.available() > 0) {
  // Receive two sets of input values (0-255) from Python code
  float inputValue1 = Serial.parseInt(); // Replace this with the actual value received for set 1 (0-255)
  float inputValue2 = Serial.parseInt(); // Replace this with the actual value received for set 2 (0-255)

  // Convert input values to a range of 0 to 3.3V 
  float outputVoltage1 = (inputValue1/255)*3.3;
  float outputVoltage2 = (inputValue2/255)*3.3;

  Serial.println("The input values are: ");
  Serial.println(outputVoltage1, outputVoltage2);
  Serial.println("The output voltages are: ");
  Serial.println(outputVoltage1, outputVoltage2);
  
  }
}
