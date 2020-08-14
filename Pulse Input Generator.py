import serial
import eel

eel.init('web')

ser = serial.Serial('COM3', 115200, timeout = 1)

# while(1):
@eel.expose
def submit_input(data1, data2, data3):
    # print("Input desired values in this format: 2,4,50,")
    # print
    # userInput = input('Desired pulse width, gap width, and pulse set width: ')
    userInput = str(data1 + "," + data2 + "," + data3 + ",")
    ser.write(userInput.encode())
    return userInput
    

eel.start('index.html', size=(1300,650))
