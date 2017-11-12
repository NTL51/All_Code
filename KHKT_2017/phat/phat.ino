#include <SPI.h>
#include "RF24.h"
 
const uint64_t pipe = 0xE9EC08DF41LL; // địa chỉ để phát
RF24 radio(9,10); //thay 10 thành 53 với mega
char msg[] = "zz12123z";
const int sensor = A0;
int value = 0;
 
void setup(){ 
  //============================================================Module NRF24
  radio.begin();      
  Serial.begin(9600);  
  radio.setAutoAck(1);               
  radio.setRetries(1,1);             
  radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  radio.setPALevel(RF24_PA_MAX);      // Dung lượng tối đa
  radio.setChannel(8);               // Đặt kênh
  radio.openWritingPipe(pipe);        // mở kênh
  pinMode(sensor, INPUT);
}
 
void loop(){
  value = analogRead(sensor);
//  msg[0] = value / 4;
  radio.write(&msg, strlen(msg));
  Serial.println(msg);
  //radio.write(&msg,'4');
  delay(200);
}
