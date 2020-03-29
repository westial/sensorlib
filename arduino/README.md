Arduino implementation for sensorlib
====================================

This directory contains the required files to convert the sensorlib library
into an Arduino library.

This directory files tree is as follows:
```
.
├── example
│   └── potentiometer.ino
├── README.md
└── src
    └── sensor
        ├── library.properties
        └── sensorlib.h
```

## Install ##

The main source code directory of sensorlib contains the class file Sensor.h.
Starting at the parent directory, it is located at ./src/sensor.

Copy library.properties and sensorlib.h into the main sensorlib directory.

And finally copy the main sensorlib directory into your Arduino libraries 
path.

For example, for a Unix based operating system with the Arduino libraries path 
into /home/me/Arduino/libraries, it would be as follows:

```
git clone https://github.com/westial/sensorlib
cd sensorlib
cp arduino/src/sensor/* src/sensor/
cp -R src/sensor /home/me/Arduino/libraries/
```