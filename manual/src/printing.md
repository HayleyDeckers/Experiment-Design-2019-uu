# Printing the parts

The 3D-printable structural parts for this experiment were modelled in [Fusion 360](https://www.autodesk.com/products/fusion-360/overview#banner) by Autodesk. The CAD files can be found in the [appendices](./CAD.md). The parts were designed with the idea that they can be simply fixed to the aluminium extrusions using simple bolts and nuts that are widely available.

The 3D printed parts for this experiment were printed using an [Ultimaker 2+](https://ultimaker.com/3d-printers/ultimaker-2-plus) and the prints were prepared using the [free slicing software Cura](https://ultimaker.com/software/ultimaker-cura), which is published by Ultimaker. The Ultimaker 2+  is a [fused-filament-fabrication (FFF)](https://en.wikipedia.org/wiki/Fused_filament_fabrication#Fused_deposition_modeling) 3D-printer and the polymer used for the fabrication was [polyactic acid (PLA)](https://en.wikipedia.org/wiki/Polylactic_acid) filament.

The preparation of the prints is done by [slicing](https://en.wikipedia.org/wiki/Slicer_(3D_printing)) the 3D models of the parts. This is the process of computing the path that the 3D-printer must follow to fully print the part. The slicer will divide the model into a stack of xy-layers and for each layer the slicer computes the path needed to deposit filament on that layer. Slicing software will give the user a wide range of options to modify how the slicer needs to behave when computing how to move. Important options are:
- infill: how much of the inside of the part should be solid?
- supports: are there areas where the 3D-printer will need supports to properly print the overhanging part of a model?
- shells: how wide do you want the outer shell of the model to be?
- layer height: how high is each subdivided layer of the model?

Our prints were done using the standard 'fine' slicing profile that Cura provides for the Ultimaker 2+. If the parts are not stiff or strong enough you might want to increase the shell thickness and infill. The most important settings for this profile are:
- 0.1mm layer height
- 0.27mm initial layer height
- 40% infill
- 0.4mm nozzle diameter
- 0.8mm shell thickness
- 50mm/s print speed
- supports enabled
