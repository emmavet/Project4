

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  
  pinMode(7, INPUT);
}

 const int LOCKED = 0; 
 const int WAIT1 = 1;
 const int WAIT2 = 2;
 const int CHECKING = 3;
 const int UNLOCKED = 4; 

 int push1 = 0; 
 int push2 = 0; 

int code[]= {1,2};

int state = LOCKED;
int start = 0;

void loop()
{
  int sensor = digitalRead(7); 
  int b1 = digitalRead(4);
  int b2 = digitalRead(3);
  
    if (b1 == LOW){
      push1 = 0;
    }
  
  if (b2 == LOW) {
    push2 = 0;
  }
  
  switch (state){
    
    case LOCKED:
    
    digitalWrite(13, HIGH);
    if (sensor == HIGH){
       digitalWrite(13, LOW);
  state = WAIT1;
           start = millis();
    }
    break;
    
    case WAIT1:
   
    digitalWrite(12,HIGH);
    if ((b1 == HIGH) || (b2 == HIGH)){
      digitalWrite(12,HIGH);
      
      if (b1 == HIGH) {
        push1 = 1;
      }
      if (b2 == HIGH){
        push1 = 2;
      }
       state = WAIT2;
    }
   
    if(millis() - start > 10000) {
         digitalWrite(12, LOW);
         state = LOCKED;
    }
    break;
    
    case WAIT2:
    digitalWrite(12,HIGH);
      if ((b1 == HIGH) || (b2 == HIGH)){
      digitalWrite(12,HIGH);
      if (b1 == HIGH) {
        push2 = 1;
      }
      if (b2 == HIGH){
        push2 = 2;
      }
      state = CHECKING;
    }
      if(millis() - start > 10000) {
         digitalWrite(12, LOW);
         state = LOCKED;
      }
    break;
    
    case CHECKING:
    if ((push1 == code [0]) && (push2 == code[1])) {
      digitalWrite(11,HIGH);
      state = UNLOCKED;
    }else { 
      digitalWrite(13, HIGH);
      delay(200);
      digitalWrite(13, LOW);
      state = LOCKED;
    }
    push1 = 0;
    push2 = 0;
    break;
    
    case UNLOCKED:
    delay (4000);
    digitalWrite (11, LOW);
      state = LOCKED;
    break;
  }
 
    }
  
    
     
      
      
      
         
      

