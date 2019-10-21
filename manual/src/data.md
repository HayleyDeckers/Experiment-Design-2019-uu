# Data processing

## Processing and plotting the Data.
The previous Python script simply created a file with raw binary data. This is not always ideal to work with, so we have written [a small script](https://github.com/HayleyDeckers/Experiment-Design-2019-uu/blob/master/src/smooth.py) given below to read the binary data and produce a text file called `smooth.dat` containing average-smoothed data. This data can easilly be read into your favourite ploting program. For example, to plot the data in `gnuplot` it is enough to open gnuplot and run `plot 'smooth.dat' u 1:3`.

```python
from struct import unpack

#open binary input file and read its contents into data
with open('out.bin', 'rb') as content_file:
    data = content_file.read()
#open the enby output file
outfile = open('smooth.dat', 'w')
#convert it from bytes to structured data
y = unpack("HHI"*(len(data)//8),data)
# group it by 3 elements
y = [y[i:i+3] for i in range(0,len(y),3)]
#how many elements to group together
group_by = 128
#split data into chunks of group_by elements
grouped_data = [y[i:i + group_by] for i in range(0, len(y), group_by)]
#loop over the groups and compute the average for each.
for group in grouped_data:
    photosensor = 0.0
    thermocouple = 0.0
    timestamp = 0.0
    for measurement in group:
        photosensor += measurement[0]
        thermocouple += measurement[1]
        timestamp += measurement[2]
    photosensor /= len(group)
    thermocouple /= len(group)
    timestamp /= len(group)
    outfile.write("{} {} {}\n".format(timestamp,thermocouple,photosensor))
```

In order to obtain a numerical value for the expansion coefficient of the sample one would have to convert the thermocouple from arbitrary DAC units to degrees Kelvin and count the fringes of the light-sensor. Each fringe would corresponds to a shift of one wavelength of the laser.

 Unfortunately, we were not personally able to collect adequate data for processing yet as it took a long time to set-up the experiment itself but we hope that you, dear reader, might be able to make us proud :)
