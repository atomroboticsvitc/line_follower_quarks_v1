int sensor[6];
float Kp = 30, Ki = 0.3, Kd = 50;
float piderror = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
float initial_speed = 70;
int thres;
int b[6];
int onoff;
void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  delay(2000);
  thres=calibrate();
  //Serial.println(thres);
}

void loop() {
  for (int i=0;i<=5;i++){
  sensor[5-i]=analogRead(i);
  if(sensor[i]<thres){
      b[i]=0;
    }
  else{
      b[i]=1;
    }
  } 
  
  piderror = error2(b[0],b[1],b[2],b[3],b[4],b[5]);
  // Serial.print("ERROR VALUE:  ");
  // Serial.println(piderror);
  //right motor backward-5
  //right motor forward-6
  //left motor backward-9
  //left motor backward-10
  calculate_pid();
  Serial.println(PID_value);
  // Serial.print("PID VALUE: ");
  // Serial.println(PID_value);
  // Serial.println(piderror);

  int right_speed = initial_speed + PID_value;
  int left_speed = initial_speed - PID_value;
  // Serial.print(right_speed);
  // Serial.print(" ");
  // Serial.print(left_speed);
  //   Serial.print(" ");
  // Serial.println(PID_value);
  if(right_speed>255&&left_speed<=0){
    right_speed = 255;
    left_speed = 0;
  }
  if(left_speed>255&&right_speed<=0){
    left_speed = 255;
    right_speed = 0;
    }

  analogWrite(6,right_speed);
  analogWrite(10,left_speed);
  
 

  }