sensorlib
=========

Sensor abstraction library for multiple purposes.

## Usages ##

It can be widely used in many kind of sensors and other devices that return a 
numerical state. For example, apart from using in moisture, temperature, 
infrared sensors and many more, it can be used to get a potentiometer state.

The only one requirement is having a method with a numerical sensor Id as 
parameter, that reads the pointing sensor state.

## Architecture ##

Main interface Sensor.h provides 3 methods to transform the value got from 
sensor into a percentage, a relative to zero value or simply the absolute value
for the given minimum and maximum available range.

The internal Sensor.h calculations are delegated to a range calculator interface.
A basic calculator implementation is even provided.

And finally there is an implementation of the Sensor.h interface easily 
adaptable into any kind of embedded firmware. 

The Arduino implementation can be found at ./arduino directory.

## Author ##

Jaume Mila Bea <[jaume@westial.com](mailto:jaume@westial.com)>