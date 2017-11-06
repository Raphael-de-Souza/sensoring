/*
 * This code receive a analog input with 10 bits (variating between 0 and 1023) and shows one range between -40 to 80.
 * 
 * By Raphael S de Souza
 * 
 * November 6, 2017
 * 
 * https://github.com/raphaelsantanasouza
 */

float readed = 0.0;

void setup() {
  Serial.begin(9600); //Starts a Serial Monitor with 9600 baud rate
}

void loop() {
  return inputNorm(analogRead(A0));
}

void inputNorm(int in){
  float inf = 0.0;
  
  if(in < 341){
    inf = (float)in*(40.0/341.0)-40.1;
  }else{
    inf = (79.9/682.0)*((float)in-341.0);
  }

  if(readed != inf){
    Serial.println(inf); //Displays the inf variable on the serial monitor 
    readed = inf;
  } 
}

