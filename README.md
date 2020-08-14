# Pulse-Input-Generator

Hi! Below is some information you may need to get this working:

*IMPORTANT*

* Please make sure you have the Arduino IDE installed. It is free online
@ https://www.arduino.cc/
* I will inlcude the corresponding library for digitalWriteFast: make sure to copy 
and paste the digitalWriteFast folder into C:/ProgramFiles(x86)/Arduino/libraries.
This allows for the method digitalWriteFast() to compile at speeds of up to 250 
nanosecs instead of the normal 100 microsecs (as close to instantaneous as can be) 
within the arduino code.


### THE PROGRAM WILL NOT RUN CORRECTLY IF THE ABOVE IS NOT DONE!!!



## USAGE INSTRUCTIONS

First, make sure the "Pulse Inputs Arduino.ino" file is uploaded to the Arduino via
the Arduino IDE. Use the IDE to upload the code onto the Arduino, then you may close
Arduino IDE and run the program as normal.

To run the program, navigate to the folder named "dist". Inside should be the ".exe"**
program which the user can simply run and the application should pop up in a browser
window (usually chrome). From there, just type in the desired time frames and measure
the signals in an oscilloscope.

*If a smaller pulse width is desired, 250 ns is attainable if you skip the usage of
the executable. To do this, open the "250ns HardCode Pulse Input" folder and open the
.ino file in the Arduino IDE. Here, change the values within the
__builtin_avr_delay_cycles(4) and delayMicroseconds(2) lines and upload the code onto
the Arduino.

** The final step is to make it a ".exe" file to simply make an executable for the
program. If you haven't yet, install pyinstaller via pip install pyinstaller in the
command line (I use Anaconda Prompt). Then simply type `python -m eel "YOUR_FILE.py"
web --noconsole --onefile`. The resulting executable should be in a "dist" folder.


## HOW IT WORKS

The user interacts with the front end GUI application which uses a combination of
JavaScript, HTML, and CSS, all with corresponding code files in the packaged
distribution. The HTML gives the layout of the GUI, and the CSS dictates the location
and specific colors, etc. of the user interface. The JS interfaces between the
frontend and the backend (python), using similar functions. Once the user inputs numbers
in the text fields and hits submit, the JS saves the values submitted and sends them
into the python script, which combines the three inputs as a single string with a ","
in between as a delimiter. This is then interfaced with the Arduino using serial
communication, in which the values in the string are parsed through, seperated based
on the delimeter, and put into variables used to change the corresponding pulse times.
(More detailed documentation on the Arduino code is commented in the Arduino ".ino" file


## DEBUGGING

With the program open, you can press F12 to see the DevTools and check to make sure
your inputs are being sent through to the backend. You can see this in the "console"
tab in the DevTools window.

### SOURCES:
https://www.youtube.com/watch?v=iy2aKf9AAvc
