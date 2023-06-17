#define trigPin 12     //trig pin is connected on 12th I/O pin on the motherboard
#define echoPin 11    // echo pin is connected on 11th I/O pin on the motherboard
#define motor 13     // motor pin is connected on 13th I/O pin on the motherboard

void setup()
{
pinMode(trigPin, OUTPUT);// defines the trig pin as output pin

pinMode(echoPin, INPUT);// defines the echo pin as input pin

pinMode(motor, OUTPUT);// defines the motor pin as output pin
}
void loop()
{
  long duration, distance;
  digitalWrite(trigPin, LOW); //First the trig pin is off so no ultrasound is sent
  delayMicroseconds(2);   // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH);  //Then turn on the output that is send out Ultrasound
  delayMicroseconds(10);  // Keep the sound on for 10 microseconds
  digitalWrite(trigPin, LOW); // Then turn it off
  duration = pulseIn(echoPin, HIGH); // The reciever is always on

  distance= duration*0.034/2; // This is the formulae to calculate the distance                                   by
                              // multiplying the speed X time 
                              
if (distance < 100)// This is the inequality where the maximum distance is input and 
                  //  if the distance is less than this number the loop will be run 
{ 
  digitalWrite (motor,HIGH); // When the calculated distance is less than 100 cm the motor is turned on
} else
{
digitalWrite(motor,LOW);// When calculated length is greater than 100cm the vibration motor is turned off
} delay(10); // The delay between calculation of distance in miliseconds.
}