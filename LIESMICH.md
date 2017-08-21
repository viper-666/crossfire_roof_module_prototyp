# XF Roof Module

English readme: [README.md](https://github.com/viper-666/xf_roof_module/blob/master/README.md)

Mit diesem Modul kann man das Verdeck des Crossfire öffnen/schließen ohne das man den Öffnen bzw. Schließen-Button die ganze Zeit gedrückt halten muss.
Eine weitere Funktion ist, dass man in dem Arduino-Sketch einstellen kann bis zu welcher Geschwindigkeit man dies tun kann.
Voreingestellt ist 50 km/h (in der Variable "int GESCHWINDIGKEIT = 50") und man sollte dies möglichst nicht erhöhen. Wenn die Geschwindigkeit bei der du das Verdeck öffest zu hoch ist wird dies dein Verdeck oder die Mechanik beschädigen.

Ich habe das Modul nun schon mehrere Monate ohne Probleme getestet aber es könnte deinen Wagen beschädigen. Deshalb geschieht ein Nachbau auf eigene Gefahr!


## Lasst uns anfangen:

Zuerst musst du die Hardware bauen, also die Platine löten. Leider habe ich nicht die Kenntnisse eine Platine zu designen welche du dir ätzen lassen kannst.
Aber falls du so eine Platine erstellt hast stelle mir das Layout bitte zur Verfügung, so dass alle anderen auch davon profitieren können.

Bis dahin musst du die Schaltung leider wie ich auf einer Lochrasterplatine aufbauen.


### Stückliste Hardware

|Mikrocontroler:       |
-----------------------
|Wert		|Anzahl|
|Arduino Nano V3|1     |

|Widerstaende:	       |
-----------------------
|Wert	        |Anzahl|
|1M	        |1     |
2k2	3
5k	2
22k	5
100k	5
560k	1
200	1

Zener Diode:
Wert		Anzahl
1N750 (4,7V)	1

Diode:
Wert	Anzahl
1N4007	1

Spannungsregler:
Wert			Anzahl
78L05Z (5V) TO92	1

Kondensatoren:
Wert	Anzahl
100µF	2
100n	2

Transistoren:
Wert	Anzahl
BC547	5

Sicherung:
Wert			Anzahl
200mA			1
Sicherungshalter	1

Stecker:
Wert		 									Anzahl
TE Connectivity AMP 1-1586041-4 VAL-U-LOK CONN HEADER 14POS R/A W/O PEGS 		1 oder 2
TE Connectivity AMP 1-1586019-4 VAL-U-LOK CONN RCPT HOUSING 14POS 4.2MM 		1 oder 2
TE Connectivity AMP 1586315-1 CONN TERM SOCKET 18-22AWG TIN 				14 oder 28

Platine:
Lochrasterplatine


## Aufbau der Hardware

Zum Aufbau wird eine Lochrasterplatine im Maß von 77mm x 80mm benötigt.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper000.JPG)

Zuerst habe ich die beiden Buchsen eingelötet. Für das Dachmodul wird nur die untere benötigt, die obere führt die anderen Ein- und Ausgänge des Arduino Nano nach außen. Dies habe ich für zukünftige Erweiterungen der Funktionen gemacht.
Dafür müssen die Löcher der Platine aufgebohrt werden.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper001.JPG)

Anschließend habe ich die Platine folgendermaßen nach dem [Schaltplan](https://github.com/viper-666/xf_roof_module/blob/master/Dachmodul.pdf) aufgebaut:
Ganz unten der Arduino Nano, rechts daneben die 12-18V auf 5V Spannungswandlung und daneben den Sichrungshalter.
Über dem Arduinno Nano die 5 Transistoren mit der dazugehörigen Komponenten.
Dann noch die fehlenden Verbindungen mit Kabeln herstellen.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper006.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper008.JPG)

Den Stecker mit den Kabeln wird nach folgendem [Schema](https://github.com/viper-666/xf_roof_module/blob/master/Verkabelung.pdf) erstellt und in den Kabelbaum des Crossfire eingebunden.
Die in Blau bezeichneten PINs gehören auf den entsprechenden PINs des Steckers.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper010.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper011.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper012.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper013.JPG)

So sieht das fertige Modul mit dem gedruckten Gehäuse aus:

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper014.JPG)

Ich empfehle den Bau eines Deaktivierungssteckers, dieser wird bei Problemen oder Verkauf des Autos anstatt des Dachmoduls eingesteckt. Damit werden die durchtrennten Leitungen wieder verbunden und der "Originalzustand" wieder hergestellt.
Dafür einfach bei einer Buchse folgende Pins verbinden:
PIN 3 mit PIN 11
PIN 7 mit PIN 12
PIN 9 mit PIN 13

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper002.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper003.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper004.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper005.JPG)



### Installation

to be continued...


### Einbau in den Crossfire

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper15.JPG)


## Erstellt mit:

* [ARDUINO](https://www.arduino.cc/en/Main/Software) - Ich habe die Version 1.6.8 verwendet
* [EAGLE](https://www.autodesk.com/products/eagle/free-download) - Die Software ist für den privaten Gebrauch kostenlos abe du benötigst einen Autodesk Account.


## Autor

* **Andre Holtkamp** - [viper-666](https://github.com/viper-666)



## License

Dieses Projekt steht unter GNU General Public License v3.0 License - schau dir die [LICENSE](https://github.com/viper-666/xf_roof_module/blob/master/LICENSE) an fuer details.

## Acknowledgments

to be continued...
