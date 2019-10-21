import serial
from time import sleep
from struct import iter_unpack

PACKET_SIZE = 8
BYTES_PER_FRAME = 4096
PACKETS_PER_FRAME = BYTES_PER_FRAME/PACKET_SIZE
#TODO: make this a command line option
#NOTE: this has to be changed to "COM1" on Windows!
#the number might also vary per pc.
COM = '/dev/ttyACM1'# (Linux)
BAUD = 115200
#connect to the arduino over serial
ser = serial.Serial(COM, BAUD, timeout = 5)
#sleep for a little while so that we can actuall connect
sleep(3)
#send an identification payload
ser.write("THERMITE\n".encode('ascii'))
# and clear the read buffer up-to-and-including acknowledge from the Arduino
preface = ser.read_until(b'ACKN')
#now open a binary file to store our data into
f = open('out.bin', 'wb')
while True:
    #TODO: deal with not reading exactly 4096 bytes, won't corrupt data as iter_unpack will fail in that case but needs a nice solution.
    # easy solution would be to just round down the len. Better solution would be to packet the data.
    data = ser.read(BYTES_PER_FRAME)
    #read some data, the math and print statements are to watch progress on the terminal.
    sum_t = 0.0
    sum_i = 0.0
    y = iter_unpack("HHI",data)
    for measurement in y:
        sum_i += measurement[0]
        sum_t += measurement[1]
    sum_i /= PACKETS_PER_FRAME
    sum_t /= PACKETS_PER_FRAME
    #prints smoothed out data
    print(sum_t, " ", sum_i)
    #and copy the raw data to a file.
    f.write(data)
f.close()
