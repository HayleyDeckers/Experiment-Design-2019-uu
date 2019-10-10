import serial
from time import sleep
import sys
import matplotlib.pyplot as plt
import numpy as np

#TODO: make this a command line option
use_batch = False
COM = '/dev/ttyACM1'# (Linux)
BAUD = 115200
ser = serial.Serial(COM, BAUD, timeout = 5)
ser.write(("BATCH\n" if use_batch else "REALTIME\n").encode('ascii'))
preface = ser.read_until(b'ACKN')
print("got preface: ", preface)

if not use_batch:
    n_points = 100;
    x = np.linspace(0, n_points, n_points)
    y = np.zeros(n_points)

    # plot stuff
    plt.ion()
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.set_ylim(500,1200)
    line1, = ax.plot(x, y, 'r-') # Returns a tuple of line objects, thus the comma

    while True:
        raw = ser.read_until(b'\xff\xff', 4096)
        if len(raw) == 4:
            data_part = raw[0:2]
            as_le = int.from_bytes(data_part, byteorder='little', signed=False)
            print(as_le)
            y = np.roll(y, -1)
            y[n_points-1] = as_le
            line1.set_ydata(y)
            fig.canvas.draw()
            fig.canvas.flush_events()
        else:
            print("SAW LENGTH", len(raw))
else:
    f = open('out.bin', 'wb')
    while True:
        f.write(ser.read(4096))
    f.close()
