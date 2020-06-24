# CROPS UN  - Optimización del agua en la agricultura


## El problema 
Según cifras del  banco  mundial,  cerca del  70% del  agua extraída en  el  mundo  es   consumida por la agricultura,  por esta rezón se requiere de métodos eficientes al respecto y más sabiendo  que   para el  2100 crecerá la población en un 70%  aproximadamente y el cambio climático a aumentado la temperatura 1.1°C , según greenpeace (ONG). Por esta situación,  es necesaria la implemenntación de un sistema que enfrente la problemática de la mala gestión del agua enfocada a la agricultura. 

## La solución

 La solución planteada en Crops  UN consiste en un sistema basado en  el internet de las  cosas   que tiene   como  objetivo  el   control  y el monitoreo de los cultivos :
 
### Tarjeta ESP32:  
Tarjeta encargada de medir las variables de temperatura, humedad del  suelo  y de la humedad relativa.
### Sensor DHT11: 
Sensores encargados de medir la temperatura y la humedad relativa. 
### Sensor FC-28: 
Sensores encargados de medir la humedad relativa del  suelo. 
### Aplicación de monitoreo para Android:  
Elaborada en appInventor,  con el  fin de realizar un monitoreo preliminar (iot.apk). 
### Electroválvula 12VDC: 
actuardor controlado por relé de 5 voltios,  con el fin de suministrar el agua.
### Etapa de potencia: 
Conformada por un transistor en modo de interruptor con el fin de activar el actuador,  su implementación está con el fin de limitar el consumo eléctrico del sistema. 
### Página WEB relacionada con el monitoreo: 
Elaborada en React,  tiene el proposito de realizar el monitoreo y realizar un estudio de las distintas estrategias de riego (Versión incompleta CROPS-UN-master.zip).

## Prototipo
El esquema del prototipo actual viene dado por: 
![prototipo](https://user-images.githubusercontent.com/64376744/85492857-7a061a00-b59b-11ea-87c5-875c964ee0e2.PNG)


### Esquema de app móvil: 

