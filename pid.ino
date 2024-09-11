float kp = 1.0;
float ki = 0.1;
float kd = 0.01;

float desired_speed = 71;
float actual_speed;
float error, last_error;
float integral;
float derivative;
float pid_calulation;
float smoothed=0
float alpha = 0.1;

// getting delta Time for the integration and differentiation

long previous_time = 0;
long current_time;
float dt;

void smoothing_Filter(float *ptr);

void setup() {

  Serial.begin(9600);

}

void loop() {
  actual_speed = 40; // assuming that encoder calculated the actual speed to be 40
  error = desired_speed - actual_speed;

  current_time= millis();
  dt = (current_time - previous_time);

  integral += dt*error;
  derivative = (error - last_error) / dt;

  pid_calulation= kp * error + ki * integral + kd * derivative;

  smoothing_Filter(&smoothed);

  last_error = error;
  previous_time = current_time;

  Serial.print("actual speed is ");
  Serial.println(actual_speed);
  Serial.print("Pid calulation is ");
  Serial.println(pid_calulation);
  Serial.print("Smoothed PID calculation is: ");
  Serial.println(smoothed);

  delay(1000);

}

void smoothing_Filter(float *ptr)
{
  *ptr = alpha * pid_calulation + (1-alpha) * smoothed;
}





