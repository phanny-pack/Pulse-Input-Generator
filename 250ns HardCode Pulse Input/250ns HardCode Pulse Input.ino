#include <digitalWriteFast.h>

// I will send the corresponding library for digitalWriteFast: make sure to copy and paste the folder into C:/ProgramFiles(x86)/Arduino/libraries
// this allows for the method digitalWriteFast() to compile at speeds of up to 250 nanosecs instead of the normal 100 microsecs (as close to instantaneous as can be)

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(13, OUTPUT);      // first pulse at pin 13
    pinMode(12, OUTPUT);      // second pulse at pin 12
    
//    Serial.begin(2000000);
}

// the loop function runs over and over again forever
void loop() {
    digitalWriteFast(13, HIGH);      // turn pin 13 on (HIGH is the voltage level)

    __builtin_avr_delay_cycles(4);

    digitalWriteFast(13, LOW);      // turn pin 12 on (HIGH is the voltage level)

// Keep in mind, the above two take up some time to initiate: ~250 nanosecs I think; don't have oscilloscope to test with tho, so not completely sure, check to make sure they are closely in phase or not

    
    delayMicroseconds(2);                      // hold pulseOne on for __ microseconds (I used 1 arbitrarily: feel free to change this)
                        
    digitalWriteFast(12, HIGH);       // turn pin 13 off by making the voltage LOW


    __builtin_avr_delay_cycles(4);                     // __ microseconds between pulseOne trailing edge and pulseTwo trailing edge (I used 10 arbitrarily: feel free to change this)

    digitalWriteFast(12, LOW);       // turn pin 12 off by making the voltage LOW

    
    delayMicroseconds(50);                     // delay signal for 50 microseconds between sets of dual pulses
}
