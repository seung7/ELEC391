/*  Arduino DC Motor Control - PWM | H-Bridge | L298N  -  Example 01
    by Dejan Nedelkovski, www.HowToMechatronics.com
*/
#define enA 9 //Enabling pin for the motor
#define in1 6 //Digital output1
#define in2 7 //Digital output2
#define button 4 //This button will change the direction of the motor
int rotDirection = 0;
int pressed = 0;
int pwmPercentage = 100;
float pwmValue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT);
  // Set initial rotation direction: Clockwise
  digitalWrite(button, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(enA, HIGH); // Enable is always on
}
void loop() {
  //int potValue = analogRead(A0); // Read potentiometer value
  //int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  //analogWrite(enA, pwmOutput); // Send PWM signal to L298N Enable pin
  // Read button - Debounce

  
  pwmPercentage=100; // Set the power input in percentage for the motor
  pwmValue= pwmPercentage * (255/100); 
  analogWrite(enA,pwmValue); // Send PWM to L298N Enable pin
  
  if (digitalRead(button) == true) {
  pressed = !pressed;
  }
  //while (digitalRead(button) == true);
  //delay(20);
  // If button is pressed - change rotation direction
  while (pressed == true) {
    digitalWrite(in1, HIGH);
    Serial.print(in1);
    digitalWrite(in2, LOW);
    Serial.println(in2);
  }
  // If button is pressed - change rotation direction
  while (pressed == false) {
    digitalWrite(in1, LOW);
    Serial.print(in1);
    digitalWrite(in2, HIGH);
    Serial.println(in2);
  }
  
}
