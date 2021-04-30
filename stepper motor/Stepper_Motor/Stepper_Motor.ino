#include <Stepper.h>

const int steps_per_revolution = 36;

Stepper motor(steps_per_revolution,10,11,12,13);

const int anticlockwise_pin = 0;
const int clockwise_pin = 1;
const int stop_pin = 2; 

int clockwise_state = 0;
int anticlockwise_state = 0;
int stop_state = 0;
int Direction = +1;
bool start = true;

void setup() {
  pinMode(clockwise_pin, INPUT_PULLUP);
  pinMode(anticlockwise_pin, INPUT_PULLUP);
  pinMode(stop_pin, INPUT_PULLUP);
}

void loop() {
  if(start){
    motor.setSpeed(75);
    motor.step(Direction);
  }
  
  clockwise_state = digitalRead(clockwise_pin);
  anticlockwise_state = digitalRead(anticlockwise_pin);
  stop_state = digitalRead(stop_pin);

  if (clockwise_state == 0) {
    while(digitalRead(clockwise_pin) == 0){}
    Direction = +1;
    start = true;
  }
  if (anticlockwise_state == 0) {
    while(digitalRead(anticlockwise_pin) == 0){}
    Direction = -1;
    start = true;
  }
  if (stop_state == 0) {
    while(digitalRead(stop_pin) == 0){}
    start = false;
  }
}
