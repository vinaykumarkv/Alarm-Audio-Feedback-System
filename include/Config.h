#ifndef CONFIG_H
#define CONFIG_H

// Input Sensor Pins
constexpr int IR_SENSOR_PIN = 2;   
constexpr int SOUND_SENSOR_PIN = 4; 

// Output Actuator Pins
constexpr int BUZZER_PIN = 3;     
constexpr int INDICATOR_LED_PIN = 5; 

// System Constraints
constexpr unsigned int BUZZER_FREQUENCY_HZ = 1000;
constexpr unsigned long SYSTEM_LOOP_DELAY_MS = 50;

#endif // CONFIG_H
