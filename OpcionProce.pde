//Código creado por José Manuel Fresno, para uso libre.
//Importar las librerías correspondientes
import processing.serial.*;
import ddf.minim.*;
import cc.arduino.*;

//Asignar nombres a las clases para los posteriores comandos
Arduino arduino;
Minim minim;
//Agregar las variables que usarás para los samples (AudioSample es una clase de MINIM)
AudioPlayer bombo;
AudioPlayer caja;
AudioPlayer efecto1;
AudioPlayer efecto2;

//Agrega las variables de lectura de Arduino, la "d" fue agregada para diferenciarlo 
//de los samples. Estas serán las variables que se comunicarán a través de Firmata.
int dbombo;
int dcaja;
int defecto1;
int defecto2;


void setup() {
//Tamaño del lienzo y color de fondo 
  size(1080, 720);
  background(0);
  
//imprime los dispositivos conectados al puerto serial (serial port)
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600);

//Igualamos lo siguiente a minim para que luego éste pueda cargar archivos
minim = new Minim(this);
//Carga los archivos usando loadSample para que se rebobine automáticamente
bombo = minim.loadFile("bombo.mp3");
caja = minim.loadFile("caja.mp3");
efecto1 = minim.loadFile("efecto1.mp3");
efecto2 = minim.loadFile("efecto2.mp3");

}

void draw() {
 
  fill(0,0,0,5);
  rect(0,0,width,height);

//lee los valores del sensor capacitivo. Aquí igualamos 
//a las varibles que incluímos anteriormente, asignando 
//la lectura del pin correspondiente.
  dbombo=arduino.analogRead(10) ;
  dcaja=arduino.analogRead(11) ;
  defecto1=arduino.analogRead(12) ;
  defecto2=arduino.analogRead(13);


//En esta sección mandamos a imprimir los valores 
//de aruino a la consola.
 print("bombo : ");
 print(dbombo);
 print(" caja : ");
 print(dcaja);
 print(" efecto 1 : ");
 print(defecto1);
 print(" efecto 2 : ");
 print(defecto2);
 println();

//En esta sección creamos las gráficas que dependerán 
//de nuestros valores del sesor capacitivo.
 fill(255,255,255,50);
 noStroke();
 smooth();
 ellipse(width/2, height/2, dbombo, dbombo );

 fill(255,255,100,100);
 noStroke();
 smooth();
 ellipse(width/2, height/2, dcaja, dcaja);

 fill(255,0,15,100);
 noStroke();
 smooth();
 ellipse(width/2, height/2, defecto1, dbombo);
 
 fill(255,0,15,255);
 noStroke();
 smooth();
 ellipse(width/2, height/2, dcaja, defecto2);
 
//Esta es la sección que activará los sonidos según 
//el sensor que se toque. El valor de (dbombo > 400)
//puede variar según las resistencias que uses, eso
//lo manejarás tu según los valores que veas en la consola.

if (dbombo == 1) 
 bombo.play(-192);
if (dcaja == 1) 
 caja.play(5);
if (defecto1 == 1) 
 efecto1.play(5);
if (defecto2 == 1) 
 efecto2.play(5); 

 //bombo.rewind();



}