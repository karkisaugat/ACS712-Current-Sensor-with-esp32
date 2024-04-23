
long lastsample = 0;
long Samplesum = 0;
long Samplecount = 0;
float vpc = (5.0 / 4095) * 1000; 
int sensor =35;
void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT_PULLDOWN);
}

void loop() {
  if (millis() > lastsample) {
    float s = (analogRead(sensor))-2760;
    // Serial.println(s);
    
    float y = s * vpc;
    Samplesum += sq(y); 
    Samplecount++;
    lastsample = millis();
  }
  if (Samplecount == 1000) {
    float mean = Samplesum / Samplecount;
    float value = sqrt(mean);
    float mV = value / 100;

    
    // if (mV <= 0.050) {
    //   mV = 0;
    // } else {
    //   mV -= 0.050;
    //    }

    Serial.println("The final rms: " + String(mV,2));
    
 
    Samplesum = 0;
    Samplecount = 0;
  }
}
