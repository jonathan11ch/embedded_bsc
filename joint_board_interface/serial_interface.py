import serial
import time

Serial = serial.Serial( port = '/dev/ttyUSB0',
                        baudrate = 115155,
                        parity = serial.PARITY_NONE,
                        stopbits = serial.STOPBITS_ONE,
                        bytesize = serial.EIGHTBITS,
                        timeout = 0)

print("Connected to serial port: " + Serial.portstr)
print(Serial.get_settings())

while True:

    Serial.write(b'R')
    time.sleep(0.001)
    d = Serial.read(2)
    print(d)
    #time.sleep(0.001)
Serial.close()
