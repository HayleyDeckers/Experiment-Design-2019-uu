The main source of noise at the moment seems to be alignment issues and vibrations.

The experiment picks up two clearly identifiable kinds of vibrations
 1. vibrations from the ground, caused by people walking past.
 2. vibrations from the air, when people are speaking it occasionally picks up noise. These problems are particularly noticable when the sample holder is attached and the brass sample is used.


We can try to further reduce these errors by
1. adding shock absorbing feet to the experiment, hopefully slightly reducing the ground vibrations
2. adding some cotton cotton wadding to the inside of the sample clamp.

 Furthermore, me noticed that when heating up a sample with a lighter, the heat makes the PLA holder more ductile and it will drop out of alignment as a result. We plan to work around this by freezing our samples instead of heating them.

 Finally, we hope to be able to remove some of the noise in post-processing. Of course we will apply a smoothing algorithm to reduce any high frequency noise but perhaps it would also be possible to detect any occurence of strong vibrations, and remove these measurements from our dataset.

 Because we are perfoming a qualitative measurement we do not expect any noise or offset-errors on the photo-detector to be significant.

 We have yet to test the temprature sensor. This will determine our final error on the x-axis. We expect the main source of error to be an offset error. We could reduce this by calibrating the sensor, but this will not be neccesary for a proof-of-concept and we do not expect to have the time to do so.
