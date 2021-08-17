import serial


Serial = serial.Serial( port = 'ttyUSB0',
                        baudrate = 9600,
                        parity = serial.PARITY_NONE,
                        stopbits = serial.STOPBITS_NONE,
                        bytesize = serial.EIGHTBITS,
                        timeout = 0)

print("Connected to serial port: " + Serial.portstr)
