# Measuring thermal expansion with an interferometer

An object will expand or contract linearly when its temperature changes according to [the formula](http://hyperphysics.phy-astr.gsu.edu/hbase/thermo/thexp.html#c2)
\\[ \frac{\Delta L}{L_{0}} = \alpha \Delta T \\]
Where \\( L_{0} \\) is the length of the object at temperature \\(T_{0}\\) and \\(\alpha\\) is its coefficient of linear expansion. It it is this \\(\alpha\\) we wish to measure. \\(L_0\\) we can measure directly with a pair of calipers, \\(\Delta T\\) we can measure with a temperature sensor attached to the object,  
and \\(\Delta L\\) we can measure based upon the interference pattern we observe. As the sample expands or contracts, we should see a shift in the interference pattern due to a changing path-length. Everytime it cycles though a dark-center/bright-center/dark-center cycle this implies the sample has expanded or contracted by one wavelength, or \\(\Delta L = 635\\)nm.

The phenomenon of cycling through the dark and light interference patterns is exactly what we will try to use in our experiment to measure changes in pathlength.\
The idea is simple:
1.	Fix all the optical elements except one mirror.
2.	Allow this mirror to move and thereby change its pathlength to the beam splitter.
3.	Measure how many times you went through a cycle of the fringe pattern for a given measurement period.
4.	Use this information to compute how much the pathlength has changed over that measurement period.

We wanted to build and design a setup for this concept and decided to measure the thermal expansion of a metal sample for our proof of concept. The design would have all elements fixed with one mirror attached to a metal sample that could be heated/cooled to make it expand or shrink. This will introduce the pathlength difference into our Interferometer, as shown in the figure below. By adding a simple temperature sensor we can then compare the expansion to the temperature difference and make a simple measurement of the thermal expansion coefficient for the sample.

![Alt text](../images/Sample_Mirror.png)
*Example of how the thermal expansion of the sample can change the pathlength. \\( \Delta l \\)
 is how much the laser's pathlength has changed.*
