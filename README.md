Prácticas elaboradas en el 2023/2 en la materia de Sistemas Embebidos, usando: 
- Quartus FPGA usanado tarjetas como DEO nano y DE1 ambas cyclone ii
- Arduino uno
- ESP8266
- Pantalla LCD 16x2 con módulo de interfaz I2C
- LCD 16x2 sin módulo I2C y usando arduino
- Matriz de leds 8x8
- Displays de 7 segmentos
- Usbusart usando los puertos de comunicación serial
- Teclado matricial
- Uso de SPIFFS para ESP8266
  
Se puede ver el código realizado y en algunos casos simulaciónes realizadas en modelsim y en Proteus 8.16
Dentro de la carpeta "reportes" viene de manera un poco detallada como fue la elaboración y explicación
del código realizado 

Dentro del proyecto de "Voltimetro" elaborada en arduino se usan dos displays de 7 segmentos donde sus
  segmentos estan multiplexados por lo que aunque el número sea estático en realidad el cambio de un
  digito a otro es muy rápido
  
Dentro del proyecto "teclado_usart_lcd" se usan los puertos de comunicación serial para el usbusart
  una pantalla LCD sin el módulo I2C y un teclado matricial, cada digito del teclado matricial generico
  de 4x4 escribe su respectivo id, como el botón 1 escribe 1 en el LCD y en el serial monitor de arduino
  se puede usar cualquier otra herramienta para usbusart y no solo el serial monitor de arduino, si se
  escribe dentro del serial monitor del arduino esto también se escribira en la LCD, además si dentro
  del teclado matricial si presionamos dos veces el mismo botón en un corto tiempo se escribira una
  letra después de la D ya que la D se encuentra de igual manera en el teclado matricial
  
Falta corregir :

  -Desde el teclado matricial al presionar dos veces hace que se imprima el número o letra
    correspondiente y después lo que se debería imprimir cuando se pulsa dos veces por ejemplo al
    presionar 1 dos veces debería aparecer únicamente la letra E, sin embargo, aparece E1 esto solo
    en la LCD
  
  -Cuando mandamos un mensaje desde el serial monitor el mensaje se escribe de manera correcta dentro
    de la LCD, sin embargo, si se sobrepasa de los 16 bits de espacio de la LCD los otros datos no se
    verán aunque si se crea o manda otro mensaje se recorrera dejando ver que si estan almacenadas
    todas las letras o símbolos que se mandaron desde el serial monitor
    
Dentro del proyecto "menu_leds" se requiere de 7 leds y 2 botones, de manera inicial se hará una
  animación cuando se presione alguno de los botones se procederá hacer otra animación así como si los
  dos son presionados al mismo se hará una nueva animación
  
  Falta corregir:
  
  - No se ejecuta de ninguna manera la animación cuando los dos bótones son pulsados simultaneamente
  - A veces no se capta bien cuando se busca cambiar de una animación a otra o regresar a la inicial
 
Dentro del proyecto "8x8" se hace una animación sencilla con una matriz de leds generica de 8x8

Si algo no se menciona con "Falta corregir" quiere decir que funciona de manera adecuada a como se
programo de manera inicial
