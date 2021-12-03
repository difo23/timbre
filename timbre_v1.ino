

 #include "pitches.h"
// Proyecto tiembre 

int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };
  
// Entradas:
int button= 2;
int button_value = 0;

// Estado del timbre 
boolean running = true;

// Salidas:
int timbre= 13;
int buzz = 8;
// Horas de clase tiempo en minutos
int times = 10;
int minutos[] = {55, 50, 50 , 20, 50,  50, 40, 40, 50, 50};

int segundos = 60;
unsigned long mult = 1000UL;
int timbre_on_time = 8 * mult;



void setup(){

  pinMode(button, INPUT);
  pinMode(timbre, OUTPUT);
  digitalWrite(button, HIGH);
  Serial.begin(9600);

}


void loop() {


  button_value = digitalRead(button);

  if(button_value && running ) {
    // Boton presionado


    for(int i = 0; (i < times) && button_value ; i++ ) {

      digitalWrite(timbre, HIGH);
      for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second 
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(buzz, melody[thisNote],noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(buzz);
      }
      digitalWrite(timbre, LOW);
      
      unsigned long  wait = minutos[i] * segundos * mult;
      Serial.println(wait);
      Serial.println(minutos[i]);
      Serial.println(segundos);
      Serial.println(mult);
      // Delay hasta el siguiente periodo
      delay( wait );
      button_value = digitalRead(button);
    }

    running = false;


  } 
  else if(button_value == false){

    running = true;
    digitalWrite(timbre, LOW);


  } 
  else if (running == false) {

    digitalWrite(timbre, LOW);

  } 
  else {

    digitalWrite(timbre, LOW);
  }


}

