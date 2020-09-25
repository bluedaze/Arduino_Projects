#define SWITCH 6
int signal_time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  Serial.println("Starting...");
}

void syncronous_flashing(int signal_time){
    for (int i = 12; i > 7; i--) {
      int j = i -1;
      digitalWrite(i,HIGH);
      delay(signal_time / 2);
      digitalWrite(j,HIGH);
      delay(signal_time);
      digitalWrite(i,LOW);
      delay(signal_time);
    }
     for (int i = 6; i < 14; i++) {
      int j = i +1;
      digitalWrite(i,HIGH);
      delay(signal_time / 2);
      digitalWrite(j,HIGH);
      delay(signal_time);
      digitalWrite(i,LOW);
      delay(signal_time);
    }
  }


void outside_in(int signal_time){
    int i = 13;
    int j = i -6;
    Serial.print("i:" );
    Serial.print(i);
    Serial.println("\n");
    Serial.print("j: ");
    Serial.print(j);
    Serial.println("\n");
    for (i; i > 10; i--) {
      int k = i -1;
      int l = j +1;
      digitalWrite(i,HIGH);
      digitalWrite(j,HIGH);
      delay(signal_time);
      digitalWrite(k,HIGH);
      digitalWrite(l,HIGH);
      digitalWrite(i,LOW);
      digitalWrite(j,LOW);
      j++;
      digitalWrite(10,LOW);
    }
    i = 11;
    j = 9;
    digitalWrite(10, HIGH);
    delay(signal_time * 2);
    digitalWrite(10, LOW);
    for (i; i < 14; i++) {
      int k = i +1;
      int l = j -1;
      Serial.print("i:" );
      Serial.print(i);
      Serial.println("\n");
      Serial.print("j: ");
      Serial.print(j);
      Serial.println("\n");
      digitalWrite(i,HIGH);
      digitalWrite(j,HIGH);
      delay(signal_time);
      digitalWrite(k,HIGH);
      digitalWrite(l,HIGH);
      digitalWrite(i,LOW);
      digitalWrite(j,LOW);
      j--;
    }
}

void loop() {
 //put your main code here, to run repeatedly:
  if(digitalRead(SWITCH) == HIGH){
  outside_in(200);
  } else {
  syncronous_flashing(50);
  }
}
