import numpy as np
from struct import unpack

with open('cool.bin', 'rb') as content_file:
    data = content_file.read()
outfile = open('smooth.bin', 'w')
y = unpack('H'*(len(data)//2),data)
means = [np.mean(y[i:i + 2048]) for i in range(0, len(y), 2048)]
dev = [np.std(y[i:i + 2048]) for i in range(0, len(y), 2048)]
#mean = np.mean(y)
for i in range(0, len(means)):
    outfile.write("{} {}\n".format(means[i], dev[i]))
