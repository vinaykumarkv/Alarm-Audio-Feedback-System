#include <Arduino.h>
#include "../include/Config.h"
#include "FeedbackSystem.h"

void setup() {
    Serial.begin(9600);
    
    pinMode(IR_SENSOR_PIN, INPUT);
    pinMode(SOUND_SENSOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(INDICATOR_LED_PIN, OUTPUT);
    
    Serial.println("--- Modular C++ Feedback Framework Initialized ---");
}

void loop() {
    // Read raw hardware data lines
    int currentObstacleState = digitalRead(IR_SENSOR_PIN);
    int currentSoundState = digitalRead(SOUND_SENSOR_PIN);

    // Execute modular subsystems
    handleObstacleDetection(currentObstacleState);
    handleSoundFeedback(currentSoundState, currentObstacleState);

    delay(SYSTEM_LOOP_DELAY_MS); 
}
