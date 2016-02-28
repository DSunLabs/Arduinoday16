/*
 * Práctica "Bulbo vela" del mini taller Mix ´n´ Match de 
 * Arduino Day 2016, creado por Alexander Höfflich para
 * D´Sun Labs.
 * 
 * El objetivo del codigo es soplar al sensor de sonido
 * para encender la lampara
 * 
 * 
 * Conexion del modulo de sonido (el rojo con bocina grande)
 * 
 * A0  -> Se conecta en caso de querer usarse para detectar la cantidad de sonido. En este ejemplo no se usa
 * G   -> Este pin es tierra y se conecta al pin GND de Arduino.
 * +   -> Este pin es voltaje y se conecta al pin 5V de Arduino
 * D0  -> Este pin se conecta al pin digital 3 de tu Arduino
 * 
 * Conexion del modulo relay (el que tiene una cajita azul grande)
 * 
 * - -> Este es tierra y va conectado al pin GND de Arduino
 * + -> Este es voltaje y va conectado al pin 5V de Arduino
 * s -> Este es señal y va conectado al digital pin 7 de Arduino
 * 
 * Guaymas, Sonora a 27 de Febrero 2016.
 */


int relay = 7 ;// pin del modulo relay
int vela = 3; // pin del sensor de sonido
int val = 0;// valor del sensor de sonido
int estadoBoton; // estado de la lampara

void setup ()
{
  pinMode (relay, OUTPUT) ;// se define que el relay es una salida, ya que esta conectada la lampara
  pinMode (vela, INPUT) ;// es el pin del sensor de sonido y es una entrada

}
 
void loop ()
{
  
  val = digitalRead(vela);// variable donde se guarda el valor del sensor de sonido
  if (val == HIGH) // Si soplamos con la suficiente fuerza, el sensor se aciva
  {
   estadoBoton++; //Si se activa, le sumamos uno al estado del boton
   delay(500); // Nos esperamos medio segundo para eliminar ruido
  }

  if (estadoBoton > 1) {  // Si el estadoBoton es mayor a 1 reseteamos la variable
    estadoBoton = 0;
  }
  switch (estadoBoton) { //Aquí seleccionamos el estado de la lámpara

    case 0 :  //Si estado botón es cero, entonces mantenemos la lámpara apagada
     digitalWrite(relay, LOW); 
     break;
    case 1 :  // Si el estado botón es 1, prendemos la lámpara
     digitalWrite(relay,HIGH);
     break;
    case 2 :  // Este caso se agrego para evitar mal funcionamiento
     digitalWrite(relay, LOW);
  }
  delay(100); //Nos esperamos un poco para evitar ruido ambiental

}
