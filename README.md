# TFG-Mano-amiga
Propuesta de TFG en la ETSIDI (UPM) de un exoesqueleto para la asistencia del agarre en el día a día

Actualmente, se parte de un prototipo de actuador basado en mecanismo biela-manivela con raíl curvo para un solo dedo. Se ha probado la sensorización de fuerza ejercida mediante galgas extensiométricas.

Pasos TFG:

1. Estudiar el estado del arte para revisar otras soluciones de exoesqueletos de mano completa. Hasta ahora lo mirado queda dividido en 4 temas:

    - Sistemas hápticos: muy toscos y voluminosos y poco útiles para este trabajo.
    - Sistemas de asistencia agarre: sobre todo con tendones y sistemas bowden
    - Soft Robotics: muy complejos para empezar con ellos.
    - Sistemas de rehabilitación: lo más habitual que ha en la literatura por la facilidad de diseñar para un sistema no portátil.
 
<del>TODO1: incluir la nueva documentación encontrada por Simón y clasificarla.</del>
 
**TODO2**: hacer el repo privado (es posible que tengas que hacer uno nuevo).

2. Buscar estudios biomecánicos de la mano humana que expliquen qué movimientos son más útiles en el día a día de una persona.

3. Proponer un nuevo mecanismo, seguramente movido por motores lineales, que diminuya el tamaño del prototipo de un dedo.

    - Se propone un diseño con un mecanismo de 4 barras como el de (<https://github.com/SimonMatdp/TFG-Mano-amiga/blob/documentacion/Opciones-utilizables/Bobby%20L.%20Shields%2C%20John%20A.%20Main.pdf>) + un sistema viela-manivela que lo mueva desde el motor lineal.
    
    - Se han buscado algunos motores lineales en Aliexpress que dan las siguientes posibilidades:
        - Servo con engranajes plástico
        - Motor paso a paso que parece más robusto + driver + placa control

TODO3 <del>diseñar y fabricar un prototipo del mecanismo de 4 barras para empezar a comprender su funcionamiento.</del>

- Simón ha hecho una simulación del RCM (Remote Center Mechanism) basado en una configuración de doble paralelogramo. En algunos sitios lo llaman simplemente mecanismo de cuatro barras y en otros de seis barras. De acuerdo a la simulación, este mecanismo nos permite tener un movimiento igual en la entrada y en la salida y, además, el mismo par de entrada produciría la misma fuerza de salida sobre el eslabón que mueve el dedo para todo el rango de movimiento en el que estamos interesado. Esto se observa en la siguiente imagen. ![imagen](https://github.com/SimonMatdp/TFG-Mano-amiga/blob/simulaciones/imagenes/simulacion_RCM%20doble_paral.PNG)
  
- Se ha fabricado un prototipo que demuestra que hace lo que se espera, al menos cinemáticamente. El único problema encontrado es que no es fácil de actuar. 
  
    Respecto a los motores a usar:<br />
    - Este mecanismo no es fácil de usar con motores lineales.<br />
    - Los motores rotativos ensachan el diseño sobre el dorso de la mano, lo que es indeseado.
    - Se podría usar una transmisión a 90º, aunque impresas probablemente den problemas.

- Motores encontrados:<br />
    - [motores compactos](https://es.aliexpress.com/item/32751400777.html?gatewayAdapt=glo2esp&spm=a2g0o.detail.0.0.750213e4TaByQ6&gps-id=pcDetailBottomMoreThisSeller&scm=1007.13339.169870.0&scm_id=1007.13339.169870.0&scm-url=1007.13339.169870.0&pvid=7940dc98-198f-48d1-a907-0b5f0a984055&_t=gps-id:pcDetailBottomMoreThisSeller,scm-url:1007.13339.169870.0,pvid:7940dc98-198f-48d1-a907-0b5f0a984055,tpp_buckets:668%232846%238112%231997&pdp_ext_f=%257B%2522sku_id%2522%253A%252265053218981%2522%252C%2522sceneId%2522%253A%25223339%2522%257D&pdp_pi=-1%253B3.29%253B-1%253B-1%2540salePrice%253BEUR%253Brecommend-recommend)<br />
    - [motores con engranaje a 90](https://es.aliexpress.com/item/10000008795281.html?gatewayAdapt=glo2esp&spm=a2g0o.detail.1000014.3.76e73106pIVeyz&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.40050.266918.0&scm_id=1007.40050.266918.0&scm-url=1007.40050.266918.0&pvid=d87ed6d9-bc20-4350-a733-a31c5c7edc4f&_t=gps-id:pcDetailBottomMoreOtherSeller,scm-url:1007.40050.266918.0,pvid:d87ed6d9-bc20-4350-a733-a31c5c7edc4f,tpp_buckets:668%232846%238112%231997&pdp_ext_f=%257B%2522sku_id%2522%253A%252212000018533583097%2522%252C%2522sceneId%2522%253A%252230050%2522%257D&pdp_pi=-1%253B6.49%253B-1%253B163%2540salePrice%253BEUR%253Brecommend-recommend)<br />
    - [motores paso a paso planos](https://www.casunsteppermotor.com/product/china-electronic-micro-flat-stepper-motor-smt-dc-motor-thiny-with-printing-machinery-for-feeder/)<br />
                
**TODO4**: revisar el estado del arte para tratar de estimar la fuerza que debemos ejercer y así poder elegir motor. 
                
    Sobre los motores: de momento, parece que la mejor opción sería el motor a 90, tanto por tamaño como por modo de etrada de la actiación al mecanismo.                 
                
4. Pensar en la actuación del pulgar.

5. Pensar en el anclaje del exoesqueleto en la mano.

6. Sistemas de sensado que permitan la realimentación para el control en fuerza:
    - Sistema mioeléctrco: interesante y con futuro pero parece caro. Preguntar a Dorin por el uso de la banda Myo.
    - Sistema de medición de corriente de motor + ¿galga? para detectar dirección.
        - Para medir intencionalidad, ¿galga extensiométrica longitudinal en el eslabón de apriete? ¿Se podrá discerneir la fuerza que ejercemos de la del usuario? Si se engancha eslabón a dedo en los extramos, y se aprieta el mecanismo por el medio, 3 galgas podrían hace la distinción
    - Algún otro sensor de fuerza que encontremos.<br />

    Sensores encontrados: <br />
    - [resistivos](https://www.electronicoscaldas.com/datasheet/FSR400Series_Interlink.pdf)<br />
    - [ piezo-element](https://www.farnell.com/datasheets/2861153.pdf)<br />    

**TODO5**: revisar el tema de la medición de la potencia consumida por el motor. Asegurarse de que no sea una tontería. 

    
    
