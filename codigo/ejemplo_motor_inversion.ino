//C++
//Mauricio Gabriel Harriet Thery
//SPD - Primer parcial - Parte adicional

//------------------------------------
//reemplazo valores por nombres especificos sin usar espacio de memoria
#define ACTIVAR 13
#define ENTRADA_UNO 9 
#define ENTRADA_DOS 8

//------------------------------------
//Establezco la configuración principal
void setup()
{
  pinMode(13, OUTPUT);//Activa el controlador del motor
  pinMode(9, OUTPUT);//Entrada 1 del controlador del motor
  pinMode(8, OUTPUT);//Entrada 2 del controlador del motor
  
  //Con esto nos encargamos que le entre 5V constantemente
  digitalWrite(13, HIGH);
  
  Serial.begin(9600);
}

//------------------------------------
//declaro la función bucle principal
void loop()
{
  //Aca nos encargamos que el motor gire en sentido horario
  digitalWrite(9, HIGH); 
  digitalWrite(8, LOW);
  delay(5000);//Tiempo de 5seg en marcha en sentido horario
  
  /*Aca apagamos el motor ya que no podemos 
  hacer un cambio de marcha directo*/
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(1000);//Tiempo de 1seg en reposo
  
  //Aca nos encargamos que el motor gire en sentido antihorario
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(5000);//Tiempo de 5seg en marcha en sentido antihorario
  
  /*Aca apagamos el motor nuevamente para 
  que realice su cambio de marcha*/
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(1000); //Tiempo de 1seg en reposo
}