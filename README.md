# XF Roof Module

Deutsche Anleitung: [LIESMICH.md](https://github.com/viper-666/xf_roof_module/blob/master/LIESMICH.md)

An modul that automatic opened and closed the roof of an Chrysler Crossfire convertible up to 50 kph or 31 mph (recommended). You don't need to hold the open or close button the whole time the roof works. You can set the max speed (in kph) until the roof works in the Arduino sketch, you have only to change the value of the variable "int GESCHWINDIGKEIT = 50".
But don't go to high, you can damage your roof.

I have tested this modul now for a few month without any problem, but you build it to your own risks. I can't give you any warrant that it don't damage anything of your car.


## Getting Started

First you have to build the hardware. Sorry, I'm don't have the skills to build a PCB you can order. Maybee you can do that and give me the file, so that the other can use it.
So you have to build it on an perfboard like I build the prototyp.

### POM Hardware

Mikrocontroler:
Value		Quantity
Arduino Nano	1

Resistors:
Value	Quantity
1M	1
2k2	3
5k	2
22k	5
100k	5
560k	1
200	1

Zener Diode:
Value		Quantity
1N750 (4,7V)	1

Diode:
Value	Quantity
1N4007	1

Voltage regulator:
Value			Quantity
78L05Z (5V) TO92	1

Capacitor:
Value	Quantity
100µF	2
100n	2

Transistors:
Value	Quantity
BC547	5

Fuse:
Value		Quantity
200mA		1
Fuse holder	1

Connectors:
Value											Quantity
TE Connectivity AMP 1-1586041-4 VAL-U-LOK CONN HEADER 14POS R/A W/O PEGS 		1 or 2
TE Connectivity AMP 1-1586019-4 VAL-U-LOK CONN RCPT HOUSING 14POS 4.2MM 		1 or 2
TE Connectivity AMP 1586315-1 CONN TERM SOCKET 18-22AWG TIN 				14 or 28

PCB:
Perfboard


## Building the hardware

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper000.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper001.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper002.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper003.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper004.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper005.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper006.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper007.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper008.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper009.JPG)


### Installing

to be continued...


## Built With

* [ARDUINO](https://www.arduino.cc/en/Main/Software) - I used the Version 1.6.8
* [EAGLE](https://www.autodesk.com/products/eagle/free-download) - The Software is free for peronal use but you have to make an Autodesk Account.


## Author

* **Andre Holtkamp** - [viper-666](https://github.com/viper-666)



## License

This project is licensed under the GNU General Public License v3.0 License - see the [LICENSE](https://github.com/viper-666/xf_roof_module/blob/master/LICENSE) file for details.

## Acknowledgments

to be continued...
