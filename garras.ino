#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;


void setup() {
  Serial.begin(115200);
  
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);
  
  // Inicializamos al ángulo 0 el servomotor
  servoMotor.write(135);
}

void loop() {
  if (Serial.available()>0){
    char GARRA; //Se establece variable de la comunicacion serial.
    GARRA = Serial.read(); //Se recibe el dato que es enviado desde MATLAB.
    if (GARRA == '1'){
      Serial.println("Garras guardadas");
      servoMotor.write(135);
      }  // Condicional para mover el servo y guarde las garras.
    if (GARRA == '2'){
      Serial.println("Garras desplegadas");
      servoMotor.write(0);
      } // Condicional para mover el servo y despliegue las garras.
  }
}
