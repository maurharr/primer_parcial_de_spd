//C++
//Mauricio Gabriel Harriet Thery
//SPD - Primer parcial - Parte 3

//------------------------------------
//reemplazo valores por nombres especificos sin usar espacio de memoria
#define PULSADOR_RESTA 2
#define PULSADOR_SUMA 3
#define INTERRUPTOR 4

#define DECENA A5
#define UNIDAD A4

#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8

#define APAGADOS 0
#define ANTIREBOTE 10

#define SENSOR_FLEXION A0
#define FOTODIODO A3

//------------------------------------
//Defino variables
int contador = 0;
int primo = 0;
int timer = 0;

// flags para cada estado. 1 seria "no presionado" y 0 "seria presionado"

int suma = 1;
int resta = 1;

/* flags que guardan el estado anterior de los botones
para comparar y determinar si se presionó el botón*/

int suma_anterior = 1;
int resta_anterior = 1;

//Sensor de flexión
int lectura_flexion;
int angulo;
int angulo_anterior = -1; //flag que guarda el estado anterior

//Fotodiodo
int lectura_luz;
int luz;
int luz_anterior = -1; //flag que guarda el estado anterior

//------------------------------------
//Establezco la configuración principal
void setup()
{
  pinMode(PULSADOR_RESTA, INPUT_PULLUP);
  pinMode(PULSADOR_SUMA, INPUT_PULLUP);
  pinMode(INTERRUPTOR, INPUT_PULLUP);

  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
 
  pinMode(A0, INPUT);
  pinMode(A3, INPUT);  
  Serial.begin(9600);
}

//------------------------------------
//declaro la función bucle principal
void loop()
{
  controlarLuz();//llamo a la función controlarLuz(); para que entre en funcionamiento el fotodiodo
  mostrarAngulo();//llamo a la función mostrarAngulo() para que entre en funcionamiento el sensor de flexión

  /*declaro la variable valorLectura que guarda el valor del INTERRUPTOR*/  
  int valorLectura = digitalRead(INTERRUPTOR);

  if(!valorLectura)//Si el interruptor retorna el valor "0"...
  {
    /*declaro la variable pulsador_presionado que guarda 
    lo que me devuelva la función presionarPulsador()*/
    int pulsador_presionado = teclaPresionada();

    if(pulsador_presionado == PULSADOR_SUMA)//Si el PULSADOR_SUMA fue presionado
    {
      contador++;//aumento el valor del contador sumando +1.
      if(contador > 99)//si el contador se vuelve mayor a 99, seteo el valor del cont. a 0
      contador = 0;
    }
    else if(pulsador_presionado == PULSADOR_RESTA)//Si el PULSADOR_RESTA fue presionado
    {
      contador--;//disminuyo el valor del contador restando -1.
      if(contador < 0)//si el contador se vuelve menor a 0, seteo el valor del cont. a 99
      contador = 99;
    }
    mostrarContador(contador);
  }
  if (valorLectura)//Si el interruptor retorna el valor "1"...
  {
    /*Al usar un delay, los visualizadores empiezan a funcionar de manera defectuosa,
    por lo que la solución que le encontré es crear un contador (timer) para que no afecte
    el funcionamiento de la función mostrarContador(primo)*/

    timer++;//aumento el timer
    if(timer==20)//si el timer llega al valor "20", entra el if...
    {
      timer=0;//el timer se reinicia
      contador++;//incrementa el valor del contador (actuando así de manera automatica)
      if(detectarPrimo(contador))//Si el valor del contador es primo...
      {
        primo = contador;//la variable primo guarda el número del contador
      }
      if(contador>99)//Si el contador es mayor a 99...
      {
        contador=0;//el contador se reinicia
      }
    }
    mostrarContador(primo);//Muestra en los visualizadores, el número guardado por la variable primo 
  }
}

//------------------Funciones------------------
/*claro una función para ver si se pulsaron los pulsadores (esto es con el
fin de evitar que al mantener el botón se modifique infinitamente el contador)*/

int teclaPresionada(void)
{  
  // el valor del pulsador se establece según las variables:
  suma = digitalRead(PULSADOR_SUMA);
  resta = digitalRead(PULSADOR_RESTA);
  
  if (suma == 1)//Si PULSADOR_SUMA no se presionó
  {
    suma_anterior = 1;//suma_anterior guarda el estado del pulsador para ser comparado
  }

  if (resta)//Si PULSADOR_RESTA no se presionó
  {
    resta_anterior = 1;//resta_anterior guarda el estado del pulsador para ser comparado
  }

  //Si PULSADOR_SUMA se presionó y su valor es distinto a suma_anterior
  if(suma == 0 && suma != suma_anterior)
  {
    suma_anterior = suma;//suma_anterior almacena el valor 0 de suma
    return PULSADOR_SUMA;
  }

  //Si PULSADOR_RESTA se presionó y su valor es distinto a suma_anterior
  if(resta == 0 && resta != resta_anterior)
  {
    resta_anterior = resta;//resta_anterior almacena el valor 0 de resta
    return PULSADOR_RESTA;
  }
  return 0;//devuelve 0 si no se presiona nada
}

//------------------------------------
//declaro una función para apagar todos los leds de los visualizadores
void apagarDisplay()
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}

//------------------------------------
//declaro una función para apagar y prender los leds internos de los visualizadores
void mostrarNumero(int numero)
{
  apagarDisplay(); //Apago los leds llamando a la función apagarDisplay()
  switch (numero)//Segun el número, prenderán determinados leds
  {
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
        
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;

    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 4:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;

    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
}

//------------------------------------
//declaro una función para determinar primos
bool detectarPrimo(int numero)
{
    bool esPrimo = true;
    for (int i = 2; i < numero; i++) 
    {
      if (numero % i == 0)
      {
        return false;
        break;//como encontró un divisor adicional, el número no es un número primo
      } 
    }
  return esPrimo;//si retorna, el número si es un número primo
}

//------------------------------------
//declaro una función para poder controlar la activación de los visualizadores
void prendeDigito(int digito)
{
	if (digito == UNIDAD)//Si el valor del argumento es "UNIDAD"
    {
    	digitalWrite(UNIDAD, LOW);//prendo el visualizador de la unidad
        digitalWrite(DECENA, HIGH);//apago el visualizador de la decena
      	delay(ANTIREBOTE);
    }
  	else if(digito == DECENA)//Si el valor del argumento es "DECENA"
    {
    	digitalWrite(UNIDAD, HIGH);//apago el visualizador de la unidad
        digitalWrite(DECENA, LOW);//prendo el visualizador de la decena
      	delay(ANTIREBOTE);
    }
  	else//Si el valor del argumento es "APAGADOS"
    {
    	digitalWrite(UNIDAD, HIGH);//apago los 2
        digitalWrite(DECENA, HIGH); 
    }
}

//------------------------------------
//declaro una función para mostrar el contador en los visualizadores secuencialmente
void mostrarContador(int contador)
{
  prendeDigito(APAGADOS);//apago los visualizadores 
  mostrarNumero(contador/10);//obtengo el valor de la decena
  prendeDigito(DECENA);//prendo el visualizador de la decena
  prendeDigito(APAGADOS);//apago los visualizadores  
  mostrarNumero(contador - 10*((int)contador/10));//obtengo el valor de la unidad 
  prendeDigito(UNIDAD);//prendo el visualizador de la unidad   
}

//------------------------------------
//declaro una función para mostrar los valores del sensor de flexión
void mostrarAngulo()
{
  lectura_flexion = analogRead(SENSOR_FLEXION);//guarda los valores analogicos del sensor
  angulo = map(lectura_flexion, 236, 634, 0, 180);//configuro los valores analogicos minimos y maximos para crear un rango de 0 a 180.

  /*Como el sensor de flexión no es lineal, tiene variaciones a medida que se le incrementa
  su alguno de inclinación, por lo que mientras sigamos inclinando/doblando el sensor, tenemos
  que ir ajustando/calibrando este mismo para que tome la medida correcta */

  if(lectura_flexion>=309 && lectura_flexion<634)//39° a 180°
  {
    angulo=angulo+7;  
  }
  if(lectura_flexion==236)//0°
  {
  	angulo=0-2;
  }
  if(lectura_flexion>238 && lectura_flexion<244)//5°
  {
    angulo=angulo-1;
  }
  if(lectura_flexion<=254)//11°
  {
    angulo=angulo-1;
  }
  if(lectura_flexion<=263)//16°
  {
    angulo=angulo-1;
  }
  if(lectura_flexion<=276)//22°
  {
    angulo=angulo-1;
  }
  if(lectura_flexion<=287)//28°
  {
    angulo=angulo-1;
  }
  if(lectura_flexion<309)//39°
  {
    angulo=angulo+6;
  }
  if(lectura_flexion>433)//95°
  {
    angulo=angulo-1;   
  }
  if(lectura_flexion>463)//108°
  {
    angulo=angulo+1;
  }
  if(lectura_flexion>=466)//109°
  {
    angulo=angulo-2;  
  }
  if(lectura_flexion>=502)//124°
  {
    angulo=angulo-1;  
  }
  if(lectura_flexion>=526)//135°
  {
    angulo=angulo-1;  
  }
  if(lectura_flexion>=550)//145°
  {
    angulo=angulo-1;  
  }  
  if(lectura_flexion>=581)//157°
  {
    angulo=angulo-1;  
  }  
  if(lectura_flexion>=623)//175°
  {
    angulo=angulo-1;  
  }  
  if(lectura_flexion>=625)//176°
  {
    angulo=angulo+1;  
  }  
  if(lectura_flexion>=632)//179°
  {
    angulo=angulo-1;  
  } 
  if(lectura_flexion==634)//180°
  {
    angulo=angulo+7;
  }
  if (angulo != angulo_anterior)//Si el valor del angulo es distinto de angulo_anterior...
  {
    //Se imprimen los datos. Esto se hace para que no este repitiendo constantemente el mismo valor cuando no varia.
    Serial.print("Medida del angulo: ");
    Serial.print(angulo);
    Serial.print(" grados");
    Serial.println();  
	angulo_anterior = angulo;// angulo_anterior guarda el ultimo valor del angulo    
  }
}

void controlarLuz()
{
  lectura_luz = analogRead(FOTODIODO);//guarda los valores analogicos del fotodiodo
  luz = map(lectura_luz, 49, 1023, 0, 100);//configuro los valores analogicos minimos y maximos para crear un rango de 0 a 100.
  if(luz != luz_anterior)///Si el valor de luz es distinto de luz_anterior...
  {
    //Se imprimen los datos. Esto se hace para que no este repitiendo constantemente el mismo valor cuando no varia.
    Serial.print("Medidor de luz: ");
    Serial.print(luz);
    Serial.print("%");
    Serial.println();
    luz_anterior = luz;// luz_anterior guarda el ultimo valor de luz    
  }
}
