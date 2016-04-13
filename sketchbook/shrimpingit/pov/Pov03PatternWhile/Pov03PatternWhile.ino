/** Controls the lights with a pattern value just like before, but using a 
 *  'while loop' to visit a sequence of pins
*/

byte pattern = 0b10101010;

int pinNumbers[] = { 9,10,11,12,A1,A2,A3,A4 };

int totalBits = 8;
int bitCounter;
int bitValue;

// this sequence of steps is triggered when you reboot the microcontroller:
void setup() {

  bitCounter = 0;
  
  while(bitCounter < totalBits){
    pinMode(pinNumbers[bitCounter], OUTPUT); // initialize pin as output
    bitCounter = bitCounter + 1;
  }
}

// the loop routine runs over and over again forever:
void loop() {
  
  bitCounter = 0;
  bitValue = 0b00000001;
  
  while(bitCounter < totalBits){
    digitalWrite(pinNumbers[bitCounter], (pattern & bitValue) != 0); //turn on the LED if the 'pattern' value has that bit set  
    bitCounter = bitCounter + 1;
    bitValue = bitValue * 2;
  }
  
  delay(1);
  
  bitCounter = 0;
  
  //then turn the LEDs off for 2 milliseconds to let them cool down
  while(bitCounter < totalBits){
    digitalWrite(pinNumbers[bitCounter], false);
    bitCounter = bitCounter + 1;
  }
  
  delay(2);
  
}