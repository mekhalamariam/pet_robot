 int IN1 = 2;
 int IN2 = 3;
 int IN3 = 5;
 int IN4 = 4;

 int ldr=A0;
 
 
 int trg =12;
 int ech =13;
 long du;
 int dis;

// int ENA = 9;
// int ENB = 8;


void setup() {
  pinMode(ldr,INPUT);
  
  pinMode(trg,OUTPUT);
  pinMode(ech,INPUT);
  Serial.begin(9600);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  //pinMode (ENA, OUTPUT);
  //pinMode (ENB, OUTPUT);

  
  

}

void loop() {

  //analogWrite(ENA, 255);
  //analogWrite(ENB, 255); 

  int value =analogRead(ldr);
  
  digitalWrite(trg,LOW);
  delayMicroseconds(2);
  digitalWrite(trg,HIGH);
  delayMicroseconds(10);
  digitalWrite(trg,LOW);
  du =pulseIn(ech,HIGH);
  dis = du*0.0332/2;
  Serial.print("Durotto : ");
  Serial.println(value);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  if(value<=10){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
    }
  

  if(dis<30)
  {digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  }
  else
  { delay(30);
    digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);}
 
}


