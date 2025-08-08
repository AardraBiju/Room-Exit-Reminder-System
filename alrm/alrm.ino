#include "HX711.h"

const int insensor = 4;   // Pin for the entry IR sensor
const int outsensor = 5;  // Pin for the exit IR sensor

bool entryDetected = false;  // Flag to track entry detection
bool exitDetected = false;   // Flag to track exit detection
#define LOADCELL_DOUT_PIN 2
#define LOADCELL_SCK_PIN 3
#define buzzer 13

HX711 scale;
int toggle1 = 0;
int toggle2 = 0;

// Start with an approximate calibration factor.
float calibration_factor = 90000.0;
int flag = 0;

// Variables for non-blocking weight measurement
unsigned long lastWeightUpdate = 0;
const unsigned long weightUpdateInterval = 100; // Update weight every 100ms
int grams = 0;

// Variables for sensor debouncing
unsigned long lastSensorRead = 0;
const unsigned long sensorDebounceDelay = 50; // 50ms debounce

void setup() {
  Serial.begin(9600);
  
  pinMode(buzzer, OUTPUT);
  pinMode(insensor, INPUT);   
  pinMode(outsensor, INPUT);  
  
  Serial.println("System started");
  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare();       // Set zero baseline

  long zero_factor = scale.read_average(5);  // Use fewer readings for faster startup
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
  
  Serial.println("System ready");
}

void loop() {
  unsigned long currentTime = millis();
  
  // Update weight measurement non-blocking (every 100ms)
  if (currentTime - lastWeightUpdate >= weightUpdateInterval) {
    if (scale.is_ready()) {
      // Use fewer readings (3 instead of 10) for faster response
      grams = scale.get_units(3) * 453.592;  
      // Serial.print("Weight: ");
      // Serial.print(grams);
      // Serial.println(" grams");
    }
    lastWeightUpdate = currentTime;
  }
  
  // Read sensors with debouncing
  if (currentTime - lastSensorRead >= sensorDebounceDelay) {
    readSensors();
    lastSensorRead = currentTime;
  }
  
  // Handle buzzer logic
  handleBuzzer();
}

void readSensors() {
  static int prevInSensor = HIGH;
  static int prevOutSensor = HIGH;
  
  int currentInSensor = digitalRead(insensor);
  int currentOutSensor = digitalRead(outsensor);
  
  // Detect sensor state changes (falling edge detection)
  if (prevInSensor == HIGH && currentInSensor == LOW) {
    Serial.println("Entry sensor triggered");
    toggle1 = 1;
  }
  
  if (prevOutSensor == HIGH && currentOutSensor == LOW) {
    Serial.println("Exit sensor triggered");
    toggle2 = 1;
  }
  
  // Direction logic - improved and more reliable
  if (toggle1 == 1 && currentOutSensor == LOW) {
    Serial.println("Direction: GOING OUT");
    exitDetected = true;
    entryDetected = false;
    toggle1 = 0;
    toggle2 = 0;  // Reset both toggles
  } 
  else if (toggle2 == 1 && currentInSensor == LOW) {
    Serial.println("Direction: GOING IN");
    entryDetected = true;
    exitDetected = false;
    toggle1 = 0;
    toggle2 = 0;  // Reset both toggles
  }
  
  // Reset flags when both sensors are clear
  if (currentInSensor == HIGH && currentOutSensor == HIGH) {
    // Optional: Reset entry/exit flags after both sensors are clear
    // entryDetected = false;
    // exitDetected = false;
  }
  
  prevInSensor = currentInSensor;
  prevOutSensor = currentOutSensor;
}

void handleBuzzer() {
  if (exitDetected == true && grams > 15 && flag == 0) {
    Serial.println("ALERT: Object removed with weight detected!");
    digitalWrite(buzzer, HIGH);
    delay(5000);  // Reduced from 10 seconds to 1 second to avoid blocking
    flag = 1;
  } 
  else if (exitDetected == false || grams < 15) {
    digitalWrite(buzzer, LOW);
    flag = 0;
  } 
  else {
    digitalWrite(buzzer, LOW);
  }
}