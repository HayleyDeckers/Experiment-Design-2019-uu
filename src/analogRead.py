import serial
from time import sleep
import sys
import matplotlib.pyplot as plt
import numpy as np

n_points = 100;
x = np.linspace(0, n_points, n_points)
y = np.zeros(n_points)

# You probably won't need this if you're embedding things in a tkinter plot...
plt.ion()
fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_ylim(0,2**16)
line1, = ax.plot(x, y, 'r-') # Returns a tuple of line objects, thus the comma


COM = '/dev/ttyACM1'# (Linux)
BAUD = 9600

ser = serial.Serial(COM, BAUD, timeout = .1)

print('Waiting for device');
sleep(3)
print(ser.name)

i = 0;

while True:
    #raw = ser.read(2) #read 2 bytes
    raw = ser.read_until(b'\xff\xff', 4096)
    line = ser.readline()
    print(raw)
    if len(raw) == 4:
        #line = ser.readline()
    #as_int = int(raw.decode().strip("\r\n"))
    #print(int.from_bytes(raw, byteorder='big', signed=False))
        data_part = raw[0:2]
        as_le = int.from_bytes(data_part, byteorder='little', signed=False)
        as_be = int.from_bytes(data_part, byteorder='big', signed=False)
        #print(as_int) #convert them to an integer and flush
        print(data_part, as_le, as_be)
        print(line)
        y[i] = as_le
        i = (i + 1)%100
        line1.set_ydata(y)
        fig.canvas.draw()
        fig.canvas.flush_events()
    else:
        print("SAW LENGTH", len(raw))
