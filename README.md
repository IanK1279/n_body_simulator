# n_body_simulator
### Description:
This project is a 2D N-body simulator to compare the following integrators: Euler, leapfrog, and R4K.
When simulating physical objects, if we want to determine the future position of an object, we need the current object's position, velocity and the force applied on it. Using the force, we can deretmine the new velocity and position vectors. The three integrators are different ways of using the force to determine future position. 

### Project Setup:
include/nbody: Has all of the header files to declare what variables are stored in the objects, as well as the different integrators and certain diagnostics like total energy and momentum.
src: Contains the calculation scripts for the headers and a main script to run the simulation and create a report.

# DELETE LATER
### Checklist:
1. 