#include <Arduino.h>
#include <digitalWriteFast.h>

// I will send the corresponding library for digitalWriteFast: make sure to copy and paste the folder into C:/ProgramFiles(x86)/Arduino/libraries
// this allows for the method digitalWriteFast() to compile at speeds of up to 250 nanosecs instead of the normal 100 microsecs (as close to instantaneous as can be)



int pulseWidth = 2;           // pulse width (time) in terms of clock cycles: each Arduino Uno clock is 62.5 nanoseconds - 2 gives
                                    // 125 ns on top of the 150 ns it takes to execute digitalWriteFast. EDIT: incorporating serial inputs adds ~550 ns
                                    // to pulse width, so entering 0.5 gives ~750 ns pulse width: the smallest I could get it so far

int gapWidth = 4;             // gap between pulses in microseconds

int pulseSetGap = 50;         // gap between sets of pulses in microseconds



// This program expects serial inputs in this format: 2,4,50,



// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    
    pinMode(13, OUTPUT);            // first pulse at pin 13
    pinMode(12, OUTPUT);            // second pulse at pin 12
    Serial.begin(115200);           // make sure serial monitor is in same frequency (baud rate) as this line
}



// the loop function runs over and over again forever
void loop() {
    
    while (Serial.available() < 1) {
        digitalWriteFast(13, HIGH);                         // turn pin 13 on (HIGH is the voltage level)                     |
                                                            //                                                                |
        for (int i = 0; i < (pulseWidth); i++) {            //                                                                |
                __builtin_avr_delay_cycles(1);              // to control pulse width                                         |   PULSE 1
        }                                                   //                                                                |
                                                            //                                                                |
        digitalWriteFast(13, LOW);                          // turn pin 13 off (LOW)                                          |
    
        
                                                            //                                                                |
        delayMicroseconds(gapWidth);                        // insert delay before second pulse                               |   DELAY BETWEEN PULSE 1 AND 2
                                                            //                                                                |
        
        
        digitalWriteFast(12, HIGH);                         // turn pin 12 on (HIGH is the voltage level)                     |
                                                            //                                                                |
        for (int i = 0; i < (pulseWidth); i++) {            //                                                                |
                __builtin_avr_delay_cycles(1);              // control pulse width                                            |   PULSE 2
        }                                                   //                                                                |
                                                            //                                                                |
        digitalWriteFast(12, LOW);                          // turn pin 12 off by making the voltage LOW                      |
    
        
                                                            //                                                                |
        delayMicroseconds(pulseSetGap);                     // delay signal for __ microseconds between sets of dual pulses   |   DELAY BETWEEN SETS OF PULSES
                                                            //                                                                |
    }




    String rxString = "";
    String strArr[3];           //Set the size of the array to equal the number of values you will be receiveing.
    
    //Keep looping until there is something in the buffer.
    while (Serial.available()) {
        //Delay to allow byte to arrive in input buffer.
        delay(2);
        
        //Read a single character from the buffer.
        char ch = Serial.read();
        
        //Append that single character to a string.
        rxString+= ch;
    }
    int stringStart = 0;
    int arrayIndex = 0;
    for (int i=0; i < rxString.length(); i++){
        //Get character and check if it's our "special" character. In this case, ","
        if(rxString.charAt(i) == ','){
            //Clear previous values from array.
            strArr[arrayIndex] = "";
            
            //Save substring into array.
            strArr[arrayIndex] = rxString.substring(stringStart, i);
            
            //Set new string starting point.
            stringStart = (i+1);
            arrayIndex++;
        }
    }
    //Put values from the array into the variables.
    String value1 = strArr[0];
    String value2 = strArr[1];
    String value3 = strArr[2];
    
    //Convert string to int if you need it.
    pulseWidth = value1.toInt();
    gapWidth = value2.toInt();
    pulseSetGap = value3.toInt();

    Serial.println(pulseWidth);
    Serial.println(gapWidth);
    Serial.println(pulseSetGap);
    Serial.println("----------");
    
}
