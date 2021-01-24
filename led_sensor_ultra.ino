const int TRIG_PIN = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 7; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int YELLOW_PIN  = 10; // Arduino pin connected to LED's pin
const int BLUE_PIN = 11;
const int RED_PIN = 12;
const int DISTANCE_THRESHOLD = 50; // centimeters

// variables will change:
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(YELLOW_PIN, OUTPUT);  // set arduino pin to output mode
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    digitalWrite(YELLOW_PIN, HIGH); // turn on LED
  else
    digitalWrite(YELLOW_PIN, LOW);  // turn off LED


   if ((distance_cm > DISTANCE_THRESHOLD) && (distance_cm < 80))
    digitalWrite(BLUE_PIN, HIGH); // turn on LED
  else
    digitalWrite(BLUE_PIN, LOW);  // turn off LED

   if((distance_cm < 100) && (distance_cm > 80))
    digitalWrite(RED_PIN, HIGH); // turn on LED
  else
    digitalWrite(RED_PIN, LOW);  // turn off LED

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
