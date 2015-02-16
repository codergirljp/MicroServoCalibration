// Use this code to test the sweep on the micro servo
// and determine the correct postion for the servo mounting attachment
// watch the mount position as the servo goes to the specified angles 
// position the mount so that looking to the right is closest to 0 degrees
// tweak the servo angles to get the positioning where you need it

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

// servo angles
const int rightPos = 30;
const int centerPos = 97;
const int leftPos = 175;

int currentPos = centerPos;
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  delay(300);
  myservo.write(currentPos);  // center servo
  delay(300);
} 
 
 
void loop() 
{ 
  // go to the right position
  currentPos = ServoToPosition(currentPos, rightPos);
  delay(300);
  
  // go to the center position
  currentPos = ServoToPosition(currentPos, centerPos);
  delay(300);
  
  // go to the left position
  currentPos = ServoToPosition(currentPos, leftPos);
  delay(300);

  // go to the center position
  currentPos = ServoToPosition(currentPos, centerPos);
  delay(300);
} 

// turn servo to specified postion smoothly
// returns the current position
int ServoToPosition(int currentPos, int nextPos)
{
  if(currentPos < nextPos)
  {
    // incremently increase the position from the current position to the next position
    for(int i=currentPos+1; i<nextPos+1; i++)
    {
      myservo.write(i);
      delay(15);
    }
  }
  else if(currentPos > nextPos)
  {
    // incremently decrease the position from the current position to the next position
    for(int i=currentPos-1; i>nextPos-1; i--)
    {
      myservo.write(i);
      delay(15);
    }
  }
  
  return nextPos;
}
