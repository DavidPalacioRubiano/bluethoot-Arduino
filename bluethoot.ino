#include <SoftwareSerial.h>

SoftwareSerial blue(1,0); // Crea conexion al bluethoot - pin 1 a TX y Pin 0 a RX

char NOMBRE[21] = "HC-06"; 
char BPS = '4'; //1 = 1200, 2 = 2400, 3 = 4800, 4 = 9600, 5 = 19200, 6 = 38400, 7 = 57600, 8 = 115200
char PASS[5] = "1234"; // Pin clave de 4 caracteres numericos

void setup() {
  blue.begin(9600);

  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH); // Prende la luz led durante 4 s antes de configurar el bluethoot
  delay(4000);

  digitalWrite(13,LOW); // Apaga la luz led para iiciar la programación

  blue.print("AT"); //Inicializa comando AT
  delay(1000);

  blue.print("AT+NAME"); // Configura el nuevo nombre
  blue.print(NOMBRE);
  delay(1000);

  blue.print("AT+BAUD");
  blue.print(BPS);
  delay(1000);

  blue.print("AT+PIN");
  blue.print(PASS);
  delay(1000);


}

void loop() {


  delay(500);
  Serial.println(digitalRead(13));
  Serial.println("");
  

}
