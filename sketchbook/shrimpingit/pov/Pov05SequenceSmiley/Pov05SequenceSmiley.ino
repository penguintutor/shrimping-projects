/** This sequence should paint a smiley face in the air. */

byte patternSequence[] = {
  0b00111100,
  0b01001110,
  0b11011011,
  0b11011111,
  0b11011111,
  0b11011011,
  0b01001110,
  0b00111100   
};
byte allZeroes = 0x00000000;

int totalPatterns = sizeof(patternSequence);
int patternCounter;

int bitCounter;
int bitValue;

int pinNumbers[] = { 9,10,11,12,A1,A2,A3,A4 };

// this sequence of steps is triggered when you reboot the microcontroller:
void setup() {

  bitCounter = 0;
  
  while(bitCounter < 8){
    pinMode(pinNumbers[bitCounter], OUTPUT); // initialize a pin as output
    bitCounter = bitCounter + 1;
  }
}

// the loop routine runs over and over again forever:
void loop() {

  patternCounter = 0;
  
  while(patternCounter < totalPatterns){
    setLights(patternSequence[patternCounter]);
    delay(2);
    patternCounter = patternCounter + 1;
  }
  
  setLights(allZeroes);
  delay(4);
  
}

void setLights(byte pattern){
  
  bitCounter = 0;
  bitValue = 0b00000001;
  
  while(bitCounter < 8){
    digitalWrite(pinNumbers[bitCounter], (pattern & bitValue) != 0); //turn on the LED if the 'pattern' value has that bit set  
    bitCounter = bitCounter + 1;
    bitValue = bitValue * 2;
  }

}
