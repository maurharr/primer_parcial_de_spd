// C++ code
#define ACTIVAR 13
#define ENTRADA_UNO 9
#define ENTRADA_DOS 8 

#define SENSOR_FLEXION A0

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
}

int umbral = 90;

void loop()
{
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  delay(5000);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(1000); 
  
  int lectura=analogRead(SENSOR_FLEXION);
  
}