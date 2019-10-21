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
group_by = 512
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
