# PRIMER PARCIAL DE SPD
![](img/intro.jpg)
## INTEGRANTES
- Mauricio Gabriel Harriet Thery
- Belkis Yolanda Guanipa Lopez
- Cheimienst Hernández Gómez

## Primera parte: Controlar un contador con botones en un programa que utiliza 2 displays de 7 segmentos en multiplexación
![](img/parte1.png)
## 1) Descripción
Este proyecto involucra la implementación de un contador de dos dígitos utilizando dos visualizadores de siete segmentos. El control del contador se realiza mediante tres botones: uno para incrementar el contador, otro para disminuirlo y un tercero para restablecerlo. La estructura fundamental del código comprende los siguientes elementos:

1. Definición de nombres significativos para diversos valores, lo cual no solo mejora la legibilidad del código, sino también optimiza el uso de memoria.
2. Declaración de las variables necesarias para el desarrollo adecuado del programa.
3. Una función `setup()` que configura los pines de entrada para los botones.
4. Una función `loop()` que contiene la lógica principal del programa y se ejecuta continuamente mientras Arduino esté encendido.
5. Una función llamada `mostrarNumero()` que se encarga de activar los segmentos correspondientes en el visualizador
6. Una función `presionarPulsador()` que detecta si los botones se han presionado o no.
7. Una función `prendeDigito()` que permite activar los dígitos de unidades o decenas en los visualizadores.
8. Por último, una función `mostrarContador()` se encarga de presentar los valores de unidades y decenas en los visualizadores.

Además, en términos de la electrónica utilizada, se emplea la [multiplexación](https://www.uazuay.edu.ec/sistemas/teleprocesos/multiplexacion)  y evita problemas de ruido de señal, como el fenómeno conocido como ["debounce"](https://www.murkyrobot.com/guias/arduino/debounce) o ["efecto rebote"](https://www.murkyrobot.com/guias/arduino/debounce).

## 2) Enlace del proyecto
[SPD - Primer parcial - Parte 1](https://www.tinkercad.com/things/c6Y9zx44Fnb-copy-of-primera-parte-del-examen-de-spd/editel?sharecode=_g-j-M7_DWu3wRsHQ90MPSgqWQZF7gK58weqZ-hQx6w)
