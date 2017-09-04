# XF Roof Module

Deutsche Anleitung: [LIESMICH.md](https://github.com/viper-666/xf_roof_module/blob/master/LIESMICH.md)

This module allows you to open / close the Crossfire's soft top without having to press and hold the Open / Close button all the time.

Another feature is that you can set up the speed at which you can do this in the Arduino Sketch.
The default is 31 mph (50 kph) (variable "int GESCHWINDIGKEIT = 50" attention it is in kph not in mph) and should not be increased. If the speed at which you open the soft top is too high, this will damage your convertible top or the mechanics.

In addition, the windows are automatically raised after the convertible top is opened.
There is also an emergency stop function simply push the button, no matter which direction, again and the roof stops.

I have tested the module for several months without problems but it could damage your car. Therefore, a replica is done at your own risk!


##Handling

If you want to open or close the roof while the car stands simply press the switch short in the appropriate direction. It can take up to 2 seconds before the roof moves. If an error occurs it will piping.
During the journey, you can open or close the roof up to the set speed. 

Please note the following:

If you want to open the roof while driving, it is very important first to press the switch open and then to unlock the roof within 2 seconds.
If you unlock the roof first, the original CrossFire convertible module is interrupted and you have to close the roof again and wait a few seconds until you can open it.

When closing while driving up to the set speed, there is nothing else to do, just press the switch on close and after about 2 seconds the roof will close.
If you get over the set speed while opening or closing, the CrossFire's original convertible module goes to fault.
Then you have to go below the set speed and can press the roof again after a few seconds.


## Lets start

First you have to build the hardware, so solder the board. Unfortunately, I do not have the knowledge to design a circuit board which you can etch.
But if you have created such a circuit board, please give me the file, I make the layout available so that everyone else can benefit from it.

Until then you have to build the circuit unfortunately as I on a perfboard.


## POM Hardware


|Microcontroler:| |
|---|---|
|Value		|Quantily|
|Arduino Nano V3|1     |

|Resistors:| |
|---|---|
|Value|Quantily|
|1M |1 |
|2k2 |3 |
|5k |2 |
|22k |5 |
|100k |5 |
|560k |1 |
|200 |1 |

|Zener Diode:| |
|---|---|
|Value|Quantily|
|1N750 (4,7V)|1|

|Diode:| |
|---|---|
|Value|Quantily|
|1N4007|1|

|Voltage regulator:| |
|---|---|
|Value|Quantily|
|78L05Z (5V) TO92|1|

|Capacitors:| |
|---|---|
|Value|Quantily|
|100µF|2|
|100n|2|

|Transistors:| |
|---|---|
|Value|Quantily|
|BC547|5|

|Fuse:| |
|---|---|
|Value|Quantily|
|200mA|1|
|Sicherungshalter|1|

|Plug and socket:| |
|---|---|
|Value|Quantily|
|TE Connectivity AMP 1-1586041-4 VAL-U-LOK CONN HEADER 14POS R/A W/O PEGS|1 oder 2|
|TE Connectivity AMP 1-1586019-4 VAL-U-LOK CONN RCPT HOUSING 14POS 4.2MM|1 oder 2|
|TE Connectivity AMP 1586315-1 CONN TERM SOCKET 18-22AWG TIN|14 oder 28|

But you can take any other socket and plug as long as they have at least 8 contacts.


## Building the hardware

A perfboard measuring 77mm x 80mm is required for assembly.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper000.JPG)

First I soldered the two sockets. For the roof module only the lower one is required, the upper one guides the other inputs and outputs of the Arduino Nano to the outside. This I have made for future extensions of the functions.
In order for the socket to fit, the holes of the circuit board must be inflated.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper001.JPG)

Subsequently, I have constructed the board according to the [schematic] (https://github.com/viper-666/xf_roof_module/blob/master/Dachmodul.pdf):

At the bottom of the Arduino Nano, on the right the 12-18V to 5V voltage conversion and next to the fuse holder.
Above the Arduinno Nano the 5 transistors with the associated components.
Then make the missing connections with cables. And do not let the cable chaos deter you. 

You can omit the green socket and the cabling if you want to do without the extensibility to additional other functions.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper006.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper008.JPG)

The plug with the cables is created according to the following [schema] (https://github.com/viper-666/xf_roof_module/blob/master/Wiring.pdf) and integrated into the Crossfire cable harness.
The PINs marked in blue belong to the corresponding PINs of the connector.
The pins for the plug should be crimped onto the stripped cable ends with a crimping tool. If you do not have a crimping pliers, it is cheap, you can get it for 10-20 $ or you can solder the cable ends with the pins.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper010.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper011.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper012.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper013.JPG)

This is how the finished module with the printed housing looks like:

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper014.JPG)

I recommend the construction of a deactivation plug, which is inserted in case of problems or sale of the car instead of the roof module. Thus, the severed lines are reconnected and the "original state" is restored.
Simply connect the following pins for a socket:

|A|B|
|---|---|
|PIN 3|PIN 11|
|PIN 7|PIN 12|
|PIN 9|PIN 13|

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper002.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper003.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper004.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper005.JPG)


## Installing of the firmware

Simply use the [Sketch] (https://github.com/viper-666/xf_roof_module/blob/master/Crossfire_Dachmodul-4.ino) with the [ARDUINO IDE] (https://www.arduino.cc/en/Main/Software) to the Arduino.


## Installation in the Crossfire

The plug created in the previous section with the cables is now wired according to the following [schema] (https://github.com/viper-666/xf_roof_module/blob/master/Wiring.pdf) in the Crossfire.

I recommend soldering the cables and isolating them with a shrink tube.

We start at the roof switch. To get to the roof switch, open the cup holder, grasp the opening with the fingers and lift the silver bezel at the front of the circuit until it is released from the grid.


![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper026.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper025.JPG)

The white / purple cable must then be cut and the pink cable of our plug must be connected with the part of the white / purple cable which is still hanging on the plug. The black cable of the plug comes to the now still open end of the white / purple cable.
The white cable of our plug comes to the brown / yellow cable.


![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper18.JPG)

Now we have to lift the carpet in the passenger footwell and fold in the direction of the seat and remove the white styrophoric plate.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper020.JPG)

The silver plate is secured with 3 black plastic nuts, which must be removed.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper021.JPG)

Now we can fold this towards the seat. The wiring harness with the required cables is on the upper right.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper16.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper17.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper19.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper15.JPG)

In this harness we have to look for the following cables:
- Pink / Red / Black (+ 12V) this we connect with the red cable of the plug
- Brown (ground) this we connect with the brown cables of the plug
- Blue / Green (BCM PIN 56) this must be cut through and the cable end which goes to the left to the center console comes the yellow and to the other end the blue cable of the plug
- Green / White (BCM PIN 74) you have to be careful, the cable is available several times. It is best to test with a multimeter in the continuity test whether the correct cable from the control unit PIN 74 has caught. Then this must cut through and to the cable end which goes to the left to the center console comes the orange and to the other end the green cable of the plug

If there is still enough space in the box for the RCM module and the control unit, the cables can also be tapped directly at the connector of the control unit and you only have to pass the three cables for the roof switch through the cable harness.
Advantage is, the better accessibility and one the cables unambiguously at the connector finds, since there the PIN numbers are readable.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper022.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper023.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper024.JPG)


## Built With

* [ARDUINO](https://www.arduino.cc/en/Main/Software) - I used the Version 1.6.8
* [EAGLE](https://www.autodesk.com/products/eagle/free-download) - The Software is free for peronal use but you have to make an Autodesk Account.


## Author

* **Andre Holtkamp** - [viper-666](https://github.com/viper-666)


## License

This project is licensed under the GNU General Public License v3.0 License - see the [LICENSE](https://github.com/viper-666/xf_roof_module/blob/master/LICENSE) file for details.

