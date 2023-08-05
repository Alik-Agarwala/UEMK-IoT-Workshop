// Define the pins for the sensor
const int triggerPin = 2;
const int echoPin = 3;

// Define the pin for the led
const int ledPin = 13;

// Variables to store the distance measurement
long duration;
int distance;

// Threshold distance for object detection in centimeters
const int detectionThreshold = 30;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the trigger pin as an output and echo pin as an input
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set the led pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Trigger the sonar sensor to send a pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Check if an object is within the threshold distance
  if (distance <= detectionThreshold) {
    Serial.println(distance);
    digitalWrite(ledPin, HIGH);
  } else {
    // No object detected, send binary LOW (0) to the Serial Monitor
    Serial.println("Object out of range");
    digitalWrite(ledPin, LOW);
  }

  // Wait for a short delay before taking the next measurement
  delay(200);
}