#include <Servo.h> 
String val;
char separator = '_';
// Пин для сервопривода
int miniServPin = 11;
int bigServPin = 11;
// Создаем объект
Servo MiniServ, BigServ;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  // Нам нужно подключить сервопривод к используемому номеру пина
  MiniServ.attach(miniServPin);
  BigServ.attach(bigServPin);
}

void loop(){
  val = Serial.read();
  if(val != "-1"){
    Serial.println(val + " --- val");
  int ind = val.indexOf(separator);
  
  int value = val.substring(0, ind).toInt();
  Serial.println(value+ " --- value");
  String token = val.substring(ind+1, val.length()-1);
  Serial.println(token+ " --- token");

  //if(token == "miniserv"){
  //if(value != 0)
   // MiniServ.write(value);
  /*}
  else if(token == "bigserv"){
    BigServ.write(value);
  }*/
  }
}
