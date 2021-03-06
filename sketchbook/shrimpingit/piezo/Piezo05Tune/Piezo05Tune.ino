
/* Tune has a sequence of steps using the tone() function which result in the playback of a tune.
* See https://github.com/ShrimpingIt/projects/tree/master/sketchbook/shrimpingit/piezo for the other examples in this series
*/

// Pin 6 (see https://www.arduino.cc/en/Hacking/PinMapping168 ) should have a piezoPin
// attached through a series resistor to ground in order to make this work.

int noteLength = 200;
int pauseLength = 1;

void setup(){
  pinMode(6,OUTPUT);
}

void loop(){

  tone(6, 523); //lower c
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 493); //b
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 392); //g
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 493); //lower c
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 493); //b
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 329); //b
  delay(noteLength);
  noTone(6);
  delay(pauseLength + noteLength); //a rest is added here

  tone(6, 493); //lower c
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 261); //upper c
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 392); //g
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 440); //a
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  tone(6, 493); //lower c
  delay(noteLength);
  noTone(6);
  delay(pauseLength);

  while(millis() > 10000){ //after 10 seconds, stays in this loop, silenced
      //do nothing
  }

}
