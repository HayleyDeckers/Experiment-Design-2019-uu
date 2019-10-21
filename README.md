# Experiment-Design-2019-uu
Code and CAD models for our Michelson Interferometer based experiment, aiming to measure thermal expansion, for the course *Experiment Design* at Utrecht University (2019).

For detailed build instructions, see our manual at https://codingcat.nl/book

## The Experiment
A [Michelson Interferometer](https://en.wikipedia.org/wiki/Michelson_interferometer) is a, relatively, simple interferometer requiring at a minimum only two mirrors, a light source, a beam-splitter, and a target.
By affixing one of the mirrors to a free moving object, the linear expansion of the object can be measured by looking at the interference pattern shown on the target.

For this project we have build our own Michelson interferometer using 3d printed parts and readilly available alluminium supports. Optical parts were provided by the university and manufactured by Thorlabs.

## Navigating the repository

If you wish to reproduce the experiment, everything you need should be in [the manual](https://codingcat.nl/book). You can find the source code for interfacing with the Arduino in `src`, and the source for the manual in `manual`. Information about the physical parts can be found in `physical_setup` including the [CAD files](https://github.com/HayleyDeckers/Experiment-Design-2019-uu/blob/mdBook/physical_setup/CAD_links.md) for the 3d-printed parts.
