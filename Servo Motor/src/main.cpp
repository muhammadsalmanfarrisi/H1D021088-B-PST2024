#include <Arduino.h>
#include <Servo.h>

Servo myservo;

// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  myservo.attach(D4);
}

void loop()
{
  myservo.write(90);

  for (int pos = 0; pos <= 180; pos += 1)
  {
    myservo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1)
  {
    myservo.write(pos);
    delay(15);
  }

  // jika kita membuat jam
  //  for (int pos = 0; pos <= 180; pos += 6)
  //    {
  //      myservo.write(pos);
  //      delay(1000);
  //    }
  //    for (int pos = 180; pos >= 0; pos -= 6)
  //    {
  //      myservo.write(pos);
  //      delay(1000);
  //    }
  //  put your main code here, to run repeatedly:
}
