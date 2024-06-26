// Initialize right motors
int PWM_right = 10;
int motor_RB = 8;
int motor_RF = 9;

// Initialize left motors
int PWM_left = 5;
int motor_LB = 6;
int motor_LF = 7;

void setup() {
  Serial.begin(9600);

  // Set motor pins as OUTPUT
  pinMode(motor_RF, OUTPUT);
  pinMode(motor_RB, OUTPUT);
  pinMode(motor_LF, OUTPUT);
  pinMode(motor_LB, OUTPUT);
}

void loop() {
  // Read values from IR sensors
  int IR_L = digitalRead(A0);
  int IR_C = digitalRead(A1); 
  int IR_R = digitalRead(A2);

  // Line following logic
  // 1 = White; 0 = Black
  if (IR_C == 0) {
    forward(); 
  } else if (IR_L == 0 && IR_R == 1) {
    turnleft();
  } else if (IR_L == 1 && IR_R == 0) {
    turnright();
  } else if (IR_L == 1 && IR_C == 1 && IR_R == 1) {
    backward();
  }

  // Serial output for debugging
  // Serial.print("IR_L: ");
  // Serial.print(IR_L);
  // Serial.print(" IR_C: ");
  // Serial.print(IR_C);
  // Serial.print(" IR_R: ");
  // Serial.println(IR_R);
}

void stop() {
  // Stop all motors
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, LOW);

  // Set PWM values to 0
  analogWrite(PWM_right, 0);
  analogWrite(PWM_left, 0);
}

void forward() {
  // Move forward
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  // Set PWM values
  analogWrite(PWM_right, 220);
  analogWrite(PWM_left, 220);
}

void backward() {
  // Move backward
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);

  // Set PWM values
  analogWrite(PWM_right, 185);
  analogWrite(PWM_left, 185);
}

void turnleft() {
  // Turn left
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);

  // Set PWM values
  analogWrite(PWM_right, 240);
  analogWrite(PWM_left, 240);
}

void turnright() {
  // Turn right
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  // Set PWM values
  analogWrite(PWM_right, 240);
  analogWrite(PWM_left, 240);
}