# pddriver

At hackerspace.gent we have a Fujitsu touch screen PC that we use as the cash register for the bar. However, the screen is rather slow to wake up when you tap it. The hardware has a built-in presence detect sensor within the webcam module. This repository contains a daemon that monitors this sensor and wakes up the screen when a human-like object is detected. 

The device identifier of the sensor in this machine is:

    0bf8:101a Fujitsu Siemens Computers HID Presence Sensor


## Installation

Install the debian package from this repository (or build it yourself, see below).

Then create a systemd user service (important, not system-level) in `~/.config/systemd/user/pddriver.service` from the account running the bar UI.

Then reload using `systemctl --user daemon-reload`, and enable and start using: 

    systemctl --user enable pddriver
    systemctl --user start pddriver

Inspect the log files using `systemctl --user status pddriver`

## Building

Install the dependencies using: 

    sudo apt install libudev-dev libusb-1.0-0-dev xdotool 

Build using a recent version of cmake, and copy the pddriver executable to `/usr/local/bin`.

Chown the `pddriver` executable to root, and set the correct setuid permissions:

    chown root /usr/local/bin/pddriver
    chmod u+s /usr/local/bin/pddriver 

A Debian package should be able to be created using 

    cpack -G DEB

## Author

This tool was written by Yvan Janssens <yvanj@cyber.gent>.
 
