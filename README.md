# TFG-Mano-amiga
Propuesta de TFG en la ETSIDI (UPM) de un exoesqueleto para la asistencia del agarre en el día a día

Actualmente, se parte de un prototipo de actuador basado en mecanismo biela-manivela con raíl curvo para un solo dedo. Se ha probado la sensorización de fuerza ejercida mediante galgas extensiométricas.

Pasos TFG:

1. Estudiar el estado del arte para revisar otras soluciones de exoesqueletos de mano completa. Hasta ahora lo mirado queda dividido en 4 temas:

    - Sistemas hápticos: muy toscos y voluminosos y poco útiles para este trabajo.
    - Sistemas de asistencia agarre: sobre todo con tendones y sistemas bowden
    - Soft Robotics: muy complejos para empezar con ellos.
    - Sistemas de rehabilitación: lo más habitual que ha en la literatura por la facilidad de diseñar para un sistema no portátil. 
  
TODO1: incluir la nueva documentación encontrada por Simón y clasificarla. 
TODO2: hacer el repo privado (es posible que tengas que hacer uno nuevo)

2. Buscar estudios biomecánicos de la mano humana que expliquen qué movimientos son más útiles en el día a día de una persona. 

3. Proponer un nuevo mecanismo, seguramente movido por motores lineales, que diminuya el tamaño del prototipo de un dedo. 

    - Se propone un diseño con un mecanismo de 4 barras como el de (##PEGAR ENLACE##) + un sistema viela-manivela que lo mueva desde el motor lineal. 
    
    - Se han buscado algunos motores lineales en Aliexpress que dan las siguientes posibilidades: 
        - Servo con engranajes plástico
        - Motor paso a paso que parece más robusto + driver + placa control

TODO3: diseñar y fabricar un prototipo del mecanismo de 4 barras para empezar a comprender su funcionamiento. 

4. Pensar en la actuación del pulgar. 

5. Pensar en el anclaje del exoesqueleto en la mano. 

6. Sistemas de sensado que permitan la realimentación para el control en fuerza:
    - Sistema mioeléctrco: interesante y con futuro pero parece caro. Preguntar a Dorin por el uso de la banda Myo. 
    - Sistema de medición de corriente de motor + ¿galga? para detectar dirección. 
    - Algún otro sensor de fuerza que encontremos. 

