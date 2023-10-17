//C++
//Mauricio Gabriel Harriet Thery
//SPD - Primer parcial - Parte 1

//------------------------------------
//reemplazo valores por nombres especificos sin usar espacio de memoria
#define PULSADOR_RESTA 2
#define PULSADOR_SUMA 3
#define PULSADOR_REINICIAR 4

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

//------------------------------------
//Defino variables

int contador = 0;

// flags para cada estado. 1 seria "no presionado" y 0 "seria presionado"

int suma = 1;
int resta = 1;
int reset = 1;

/* flags que guardan el estado anterior de los botones
para comparar y determinar si se presionó el botón*/

int suma_anterior = 1;
int resta_anterior = 1;
int reset_anterior = 1;

//------------------------------------
//Establezco la configuración principal
void setup()
{ 
  pinMode(PULSADOR_RESTA, INPUT_PULLUP);
  pinMode(PULSADOR_SUMA, INPUT_PULLUP);
  pinMode(PULSADOR_REINICIAR, INPUT_PULLUP);

  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  Serial.begin(9600);
}

//------------------------------------
//declaro la función bucle principal
void loop()
{
  /*declaro la variable pulsador_presionado que guarda 
  lo que me devuelva la función presionarPulsador()*/
  int pulsador_presionado = presionarPulsador();
  
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
  else if(pulsador_presionado == PULSADOR_REINICIAR)//Si el PULSADOR_REINICIAR fue presionado
  {
    contador = 0;//Seteo el valor del contador a 0 para "reiniciarlo".
  }
  mostrarContador(contador);
}

//------------------Funciones------------------
/*claro una función para ver si se pulsaron los pulsadores (esto es con el
fin de evitar que al mantener el botón se modifique infinitamente el contador)*/

int presionarPulsador()
{
  // el valor del pulsador se establece según las variables:
  suma = digitalRead(PULSADOR_SUMA);
  resta = digitalRead(PULSADOR_RESTA);
  reset = digitalRead(PULSADOR_REINICIAR);	


  if (suma == 1)//Si PULSADOR_SUMA no se presionó
  {
    suma_anterior = 1;//suma_anterior guarda el estado del pulsador para ser comparado
  }

  if (resta)//Si PULSADOR_RESTA no se presionó
  {
    resta_anterior = 1;//resta_anterior guarda el estado del pulsador para ser comparado
  }

  if (reset)//Si PULSADOR_REINICIAR no se presionó
  {
    reset_anterior = 1;//reset_anterior guarda el estado del pulsador para ser comparado
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

  //Si PULSADOR_REINICIAR se presionó y su valor es distinto a suma_anterior
  if(reset == 0 && reset != reset_anterior)
  {
    reset_anterior = reset;//reset_anterior almacena el valor 0 de reset
    return PULSADOR_REINICIAR;
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
//declaro una función para poder controlar la activación de los visualizadores
void prendeDigito(int digito)
{

	if (digito == UNIDAD)//Si el valor del argumento es "UNIDAD"
    {
    	digitalWrite(UNIDAD, LOW);//prendo el visualizador de la unidad
        digitalWrite(DECENA, HIGH);//apago el visualizador de la decena
      	delay(ANTIREBOTE);
    }
  	else if (digito == DECENA)//Si el valor del argumento es "DECENA"
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
void mostrarContador(int count)
{
	prendeDigito(APAGADOS);// apago los visualizadores
  	mostrarNumero(count/10);//obtengo el valor de la decena
  	prendeDigito(DECENA);//prendo el visualizador de la decena
  	prendeDigito(APAGADOS);//apago los visualizadores
  	mostrarNumero(count - 10*((int)count/10));//obtengo el valor de la unidad
  	prendeDigito(UNIDAD);//prendo el visualizador de la unidad    
}