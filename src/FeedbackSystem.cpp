#include <Arduino.h>
#include "FeedbackSystem.h"
#include "../include/Config.h"

void handleObstacleDetection(int obstacleState) {
    if (obstacleState == LOW) { 
        tone(BUZZER_PIN, BUZZER_FREQUENCY_HZ); 
        Serial.print("[ OBJECT ] Detected! -> Buzzer Active | ");
    } else {
        noTone(BUZZER_PIN);
        digitalWrite(INDICATOR_LED_PIN, LOW); 
        Serial.print("[ OBJECT ] None.     -> Buzzer Silent | ");
    }
}

void handleSoundFeedback(int soundState, int obstacleState) {
    // Logic gate handles structural sensor cross-talk filters
    if (soundState == LOW && obstacleState == LOW) {
        digitalWrite(INDICATOR_LED_PIN, HIGH); 
        Serial.println("[ SOUND ] PICKED UP! -> LED ON");
    } else {
        digitalWrite(INDICATOR_LED_PIN, LOW);  
        Serial.println("[ SOUND ] Quiet.     -> LED OFF");
    }
}
