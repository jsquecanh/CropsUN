![Logo CROPS UN](https://user-images.githubusercontent.com/64376744/85499593-86906f80-b5a7-11ea-8ed8-07a4f59d4c05.png) ![ods](https://user-images.githubusercontent.com/64376744/85499607-8abc8d00-b5a7-11ea-9c83-a33790140582.PNG)
# CROPS UN  - Optimización del agua en la agricultura

  

- Juan Sebastián Quecán Herrera 
- Nicolás Andrés Rubiano Méndez  
- Johnathan Andrés León Rodríguez
- Germán Steven Fernández Garzón

Rigoberto Sáenz Imbacuán - tutor

Taller de proyectos interdisciplinarios -  TPI 
Universidad Nacional de Colombia. 


## El problema 
Según cifras del  banco  mundial,  cerca del  70% del  agua extraída en  el  mundo  es   consumida por la agricultura,  por esta rezón se requiere de métodos eficientes al respecto y más sabiendo  que   para el  2100 crecerá la población en un 70%  aproximadamente y el cambio climático a aumentado la temperatura 1.1°C , según greenpeace (ONG). Por esta situación,  es necesaria la implemenntación de un sistema que enfrente la problemática de la mala gestión del agua enfocada a la agricultura. 

![Arbol de problemas](https://user-images.githubusercontent.com/64376744/85499714-bb042b80-b5a7-11ea-83d8-c1e72e81610b.png)

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
El modelo preliminar de la app móvil se da por: 

![esquemamovil](https://user-images.githubusercontent.com/64376744/85495201-b176c580-b59f-11ea-90f4-5262b874f654.PNG)

### Resultado app movil: 
El resultado de la app móvil,  viene dado por: 
![app](https://user-images.githubusercontent.com/64376744/85499706-b93a6800-b5a7-11ea-9a4a-658eb47b13a5.png)


## Modelo web: 
### Modelo web (Se puede encontrar en el repositorio ): 
El modelo de datos viene dado por: 

![modelodedatos](https://user-images.githubusercontent.com/64376744/85495185-ad4aa800-b59f-11ea-9f1a-039253a921d1.PNG)

#### Resultado  web 

El resultado preliminar de la app web viene dada por: 

![appweb1](https://user-images.githubusercontent.com/64376744/85495211-b76ca680-b59f-11ea-9a1a-e416756f8d12.PNG)
![appweb](https://user-images.githubusercontent.com/64376744/85495218-b9cf0080-b59f-11ea-9786-12aa18da1816.PNG)

### Esquema circuital

El esquema básico de montaje del monitoreo viene dado por: 

![circuito](https://user-images.githubusercontent.com/64376744/85495207-b50a4c80-b59f-11ea-98ba-b2af0f2ae59a.PNG)


El sistema implementado dado por el esquema anterior viene dado por: 

![sistema](https://user-images.githubusercontent.com/64376744/85499563-77112680-b5a7-11ea-871d-687f7a6afd63.png)

## Resultado físico
El resultado físico actual se puede ver dado por: 

![prot](https://user-images.githubusercontent.com/64376744/85500686-a032b680-b5a9-11ea-9b6e-89438a02fee5.jpg)

## Justificación de prototipo: 



![jsutificacionproto](https://user-images.githubusercontent.com/64376744/85501084-45e62580-b5aa-11ea-93c4-6fde77e8bf59.PNG)



# Contacto 

## cropsun2020@gmail.com

