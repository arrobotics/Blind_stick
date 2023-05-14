const int triggerPin = 11; // Ultrasonic sensor trigger pin
const int echoPin = 12; // Ultrasonic sensor echo pin
const int buzzerPin = 6; // Buzzer pin
const int shortRangeThreshold = 20; // Short range threshold in centimeters

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send a pulse to the ultrasonic sensor to trigger a measurement
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the time it takes for the echo signal to return
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound (343 m/s)
  int distance = duration / 2 / 29.1;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn the buzzer on or off based on the distance
  if (distance < shortRangeThreshold) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Wait for a short time before taking the next measurement
  delay(100);
}
