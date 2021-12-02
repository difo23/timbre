
// Proyecto tiembre 

// Entradas:
int button= 2;
int button_value = 0;

// Estado del timbre 
boolean running = true;

// Salidas:
int timbre= 13;

// Horas de clase tiempo en minutos
 const int times = 10;
int minutos[times] = {
  55, 50, 50 , 20, 50,  50, 40, 40, 50, 50};

int segundos = 60;
int mult = 1000;
int timbre_on_time = 8 * mult;



void setup(){

  pinMode(button, INPUT);
  pinMode(timbre, OUTPUT);
  digitalWrite(button, HIGH);

}


void loop() {


  button_value = digitalRead(button);

  if(button_value && running ) {
    // Boton presionado


    for(int i = 0; (i < times) && button_value ; i++ ) {

      digitalWrite(timbre, HIGH);
      delay(timbre_on_time);
      digitalWrite(timbre, LOW);

      // Delay hasta el siguiente periodo
      delay( times[i] * segundos * mult - timbre_on_time );
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

