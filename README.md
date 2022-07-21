# pddriver

Driver for the presence detect sensor that's embedded in the touchscreen AIO PC we use in our bar till.

## Dependencies

    sudo apt install libudev-dev libusb-1.0-0-dev

## Installation

- make sure to chown root + chmod u+s the file 

## Initial investigation

usbhid-dump output: 

    $ sudo usbhid-dump -e all --model=0bf8:101a
    002:003:000:DESCRIPTOR         1658149756.815730
    05 20 09 11 A1 00 05 20 0A 16 03 15 00 25 04 75
    08 95 01 A1 02 0A 40 08 0A 41 08 0A F0 08 0A C0
    08 0A E0 08 0A B0 08 B1 02 C0 0A 01 02 15 00 25
    06 75 08 95 01 A1 02 0A 00 08 0A 01 08 0A 02 08
    0A 03 08 0A 04 08 0A 05 08 0A 06 08 81 03 C0 0A
    B1 04 15 00 25 01 75 08 95 01 81 03 C0

    Starting dumping interrupt transfer stream
    with 1 minute timeout.

    002:003:000:STREAM             1658149791.337619
    01 01

    002:003:000:STREAM             1658149812.713873
    01 00

Seems that it just sends packets when the state changes; `01 00` if there is no presence, and `01 01` if there is. 