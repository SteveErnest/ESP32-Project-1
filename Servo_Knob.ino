//If you like this project, consider starring on GitHub! ⭐

#include <ESP32Servo.h> 

Servo myservo;  // create servo object to control a servo

int servoPin = 12;      // GPIO pin used to connect the servo control (digital out)

#if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
int potPin = 27;        // GPIO pin used to connect the potentiometer (analog in)
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
int potPin = 27;         // GPIO pin used to connect the potentiometer (analog in)
#else
int potPin = 27;        // GPIO pin used to connect the potentiometer (analog in)
#endif
int ADC_Max = 4096;     // a range of max values of 512-4096
  
int val;    // variable to read the value from the analog pin

void setup()
{
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);// Standard 50hz servo
  myservo.attach(servoPin, 500, 2400);   
}

void loop() {
  val = analogRead(potPin);            // read the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, ADC_Max, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  
  delay(200);                          
}

