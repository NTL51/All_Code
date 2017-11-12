#define IN1	7
#define IN2	6
#define IN3	5
#define IN4	4
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
void setup()
{
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
}

void motor_2_Dung() {
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}
 

 
void motor_2_Tien() { //speed: từ 0 - MAX_SPEED
	//digitalWrite(IN3, HIGH);
        analogWrite(IN3, 10);
	digitalWrite(IN4, LOW);
}
 
void motor_2_Lui() {
	//digitalWrite(IN3, LOW);
        analogWrite(IN3, 255);
	digitalWrite(IN4, LOW);
}
 
void loop()
{
	
	motor_2_Lui(); //motor 2 lùi
	// motor 1 vẫn tiến
	delay(2000);//tiến 2 s
        motor_2_Dung();
	delay(400);//dừng 10s
        motor_2_Tien(); //motor 2 lùi
	// motor 1 vẫn tiến
	delay(2000);//tiến 2 s
	motor_2_Dung();
	delay(400);//dừng 10s
}
