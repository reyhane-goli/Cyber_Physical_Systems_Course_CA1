const int stop_pin = 4;
const int speedup_pin = 5;
const int speeddown_pin = 6;
const int direction_pin = 7;
const int motor_pin1 = 8;
const int motor_pin2 = 9;

void setup() {
  pinMode(motor_pin1, OUTPUT);
  pinMode(motor_pin2, OUTPUT);
  pinMode(stop_pin, INPUT_PULLUP);
  pinMode(speedup_pin, INPUT_PULLUP);
  pinMode(speeddown_pin, INPUT_PULLUP);
  pinMode(direction_pin, INPUT_PULLUP);
}

int pwm = 255;
int counter = 0;
const int pwm_max = 255;
bool clockwise = true;
int stop_state = 0;
int speedup_state = 0;
int speeddown_state = 0;
int direction_state = 0;
  
void loop() {
  counter = (counter + 1) % pwm_max;

  stop_state = digitalRead(stop_pin);
  speedup_state = digitalRead(speedup_pin);
  speeddown_state = digitalRead(speeddown_pin);
  direction_state = digitalRead(direction_pin);

  if (stop_state == LOW) {
    if (counter < pwm) {
      if(clockwise){
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
      }else{
        digitalWrite(motor_pin1, LOW);
        digitalWrite(motor_pin2, HIGH);
      }
    } else {
      digitalWrite(motor_pin1, LOW);
      digitalWrite(motor_pin2, LOW);
    }
  } else {
    digitalWrite(motor_pin1, LOW);
    digitalWrite(motor_pin2, LOW);
  }

  if (speedup_state == LOW) {
    while(digitalRead(speedup_pin) == LOW){}
    pwm += 10;
    if(pwm > pwm_max)
      pwm = pwm_max;
  }
  if (speeddown_state == LOW) {
    while(digitalRead(speeddown_pin) == LOW){}
    pwm -= 10;
    if(pwm < 0)
      pwm = 0;
  }
  if (direction_state == LOW) {
    while(digitalRead(direction_pin) == LOW){}
    clockwise = !clockwise;
  }
}
