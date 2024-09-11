class PIDControl {
  private:
    float kp, ki, kd;
    float alpha;
    float integral, last_error;
    float smoothed_output;
    long previous_time;

  public:

    PIDControl(float kp, float ki, float kd, float alpha = 0.1) {
      this->kp = kp;
      this->ki = ki;
      this->kd = kd;
      this->alpha = alpha;
      this->integral = 0;
      this->last_error = 0;
      this->smoothed_output = 0;
      this->previous_time = millis();
    }

    float calc_pid(float desired_value, float actual_value)
    {
      float error = desired_value - actual_value;

      long current_time = millis();
      float dt = (current_time - previous_time)
      previous_time = current_time;

      integral += error * dt;
      float derivative = (error - last_error) / dt;
      float pid_calc = (kp * error) + (ki * integral) + (kd * derivative);

      smoothing_filter(pid_calc);

      last_error = error;

      return smoothed_output;
    }

    void smoothing_filter(float pid_output) {
      smoothed_output = alpha * pid_output + (1 - alpha) * smoothed_output;
    }

    void setKp(float newKp)
    { 
      kp = newKp;
    }
    void setKi(float newKi) 
    { 
      ki = newKi;
    }
    void setKd(float newKd) 
    {
    kd = newKd; 
    }
    void setAlpha(float newAlpha) 
    {
       alpha = newAlpha; 
    }
};

PIDControl pid1(1.0, 0.1, 0.01, 0.1);

float desired_speed = 71;   
float actual_speed = 40;


void setup() {

  Serial.begin(9600);

}

void loop() {
  float smoothed = pid1.calc_pid(desired_speed, actual_speed);

  Serial.print("actual speed is ");
  Serial.println(actual_speed);
  Serial.print("actual speed is ");
  Serial.println(desired_speed);
  Serial.print("Smoothed PID calculation is: ");
  Serial.println(smoothed);

  delay(1000);

}






