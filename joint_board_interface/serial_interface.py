import serial
import time

Serial = serial.Serial( port = '/dev/ttyUSB0',
                        baudrate = 9600,
                        parity = serial.PARITY_NONE,
                        stopbits = serial.STOPBITS_ONE,
                        bytesize = serial.EIGHTBITS,
                        timeout = 0)

print("Connected to serial port: " + Serial.portstr)
print(Serial.get_settings())


with Serial as s:
    s.write(b'hello')
    time.sleep(1)
    d = s.readline()


time.sleep(5)
print(d)
Serial.close()
