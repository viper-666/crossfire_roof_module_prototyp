# XF Roof Module

English readme: [README.md](https://github.com/viper-666/xf_roof_module/blob/master/README.md)

Mit diesem Modul kann man das Verdeck des Crossfire öffnen/schließen ohne das man den Öffnen bzw. Schließen-Button die ganze Zeit gedrückt halten muss, ein kurzes antippen reicht.

Eine weitere Funktion ist, dass man in dem Arduino-Sketch einstellen kann bis zu welcher Geschwindigkeit man dies tun kann.
Voreingestellt ist 50 km/h (in der Variable "int GESCHWINDIGKEIT = 50") und man sollte dies möglichst nicht erhöhen. Wenn die Geschwindigkeit bei der du das Verdeck öffest zu hoch ist wird dies dein Verdeck oder die Mechanik beschädigen.

Außerdem werden, nachdem das Verdeck geöffnet ist, die Fenster automatisch hoch gefahren. 
Es gibt auch noch eine Nothaltfunktion einfach den Taster, egal in welcher Richtung, noch mal drücken und das Dach hält an.

Ich habe das Modul nun schon mehrere Monate ohne Probleme getestet aber es könnte deinen Wagen beschädigen. Deshalb geschieht ein Nachbau auf eigene Gefahr!


## Bedienung

Will man im Stand das Dach öffnen oder schließen einfach den Schalter kurz in der entsprechenden Richtung drücken. Es kann bis zu 2 Sekunden dauern bis das Dach sich bewegt. Wenn ein Fehler auftritt wird es Pipen.
Während der Fahrt kann man das Dach bis zu der eingestellten Geschwindigkeit öffnen bzw. schließen es gibt dabei nur folgendes zu beachten:

Will man das Dach während der Fahrt öffnen ist es ganz wichtig zuerst auf dem Schalter öffnen zu drücken und anschließend innerhalb von 2 Sekunden das Dach zu entriegeln.
Entriegelt man das Dach zuerst, geht das Originale Verdeckmodul des Crossfire auf Störung und man muss das Dach wieder verschließen und ein m paar Sekunden warten bis man es öffnen kann.

Beim Schließen während der Fahrt bis zur eingestellten Geschwindigkeit gibt es nichts weiter zu beachten, einfach auf dem Schalter auf schließen drücken und nach ca. 2 Sekunden wird sich das Dach schließen.
Wenn man während des öffnen oder schließens über die eingestellte Geschwindigkeit kommt geht das Originale Verdeckmodul des Crossfire auf Störung.
Dann muss man unter die eingestellte Geschwindigkeit gehen und kann nach ein paar Sekunden das Dach wieder betätigen.


## Lasst uns anfangen

Zuerst musst du die Hardware bauen, also die Platine löten. Leider habe ich nicht die Kenntnisse eine Platine zu designen welche du dir ätzen lassen kannst.
Aber falls du so eine Platine erstellt hast stelle mir das Layout bitte zur Verfügung, so dass alle anderen auch davon profitieren können.

Bis dahin musst du die Schaltung leider wie ich auf einer Lochrasterplatine aufbauen.


### Stückliste Hardware

|Mikrocontroler:| |
|---|---|
|Wert		|Anzahl|
|Arduino Nano V3|1     |

|Widerstände:| |
|---|---|
|Wert|Anzahl|
|1M |1 |
|2k2 |3 |
|5k |2 |
|22k |5 |
|100k |5 |
|560k |1 |
|200 |1 |

|Zener Diode:| |
|---|---|
|Wert|Anzahl|
|1N750 (4,7V)|1|

|Diode:| |
|---|---|
|Wert|Anzahl|
|1N4007|1|

|Spannungsregler:| |
|---|---|
|Wert|Anzahl|
|78L05Z (5V) TO92|1|

|Kondensatoren:| |
|---|---|
|Wert|Anzahl|
|100µF|2|
|100n|2|

|Transistoren:| |
|---|---|
|Wert|Anzahl|
|BC547|5|

|Sicherung:| |
|---|---|
|Wert|Anzahl|
|200mA|1|
|Sicherungshalter|1|

|Stecker:| |
|---|---|
|Wert|Anzahl|
|TE Connectivity AMP 1-1586041-4 VAL-U-LOK CONN HEADER 14POS R/A W/O PEGS|1 oder 2|
|TE Connectivity AMP 1-1586019-4 VAL-U-LOK CONN RCPT HOUSING 14POS 4.2MM|1 oder 2|
|TE Connectivity AMP 1586315-1 CONN TERM SOCKET 18-22AWG TIN|14 oder 28|

In Deutschland bekommt man die Buchse, den Stecker und die Buchsenkontakte z.B. bei [Conrad Elektronik](https://www.conrad.de)

|Artikel|Bezeichnung|
|---|---|
|1174833|STIFTSTECKER 180° (1-1586041-4)|
|1174793|BUCHSENGEHÄUSE (1-0794954-4)|
|747987|BUCHSENKONTAKT AWG 22-18|

Man kann aber jede andere Buchse und Stecker nehmen solange diese mindestens 8 Kontakte haben.



|Platine:|
|---|
|Lochrasterplatine|


## Aufbau der Hardware

Zum Aufbau wird eine Lochrasterplatine im Maß von 77mm x 80mm benötigt.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper000.JPG)

Zuerst habe ich die beiden Buchsen eingelötet. Für das Dachmodul wird nur die untere benötigt, die obere führt die anderen Ein- und Ausgänge des Arduino Nano nach außen. Dies habe ich für zukünftige Erweiterungen der Funktionen gemacht.
Damit die Buchse passt müssen die Löcher der Platine aufgebohrt werden.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper001.JPG)

Anschließend habe ich die Platine folgendermaßen nach dem [Schaltplan](https://github.com/viper-666/xf_roof_module/blob/master/Dachmodul.pdf) aufgebaut:
Ganz unten der Arduino Nano, rechts daneben die 12-18V auf 5V Spannungswandlung und daneben den Sichrungshalter.
Über dem Arduinno Nano die 5 Transistoren mit der dazugehörigen Komponenten.
Dann noch die fehlenden Verbindungen mit Kabeln herstellen. Und nicht von dem Kabelchaos abschrecken lassen. Du kannst die grüne Buchse und die Verkabelung weglassen wenn du auf die Erweiterbarkeit auf zusätzliche andrere Funktionen verzichten willst.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper006.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper008.JPG)

Der Stecker mit den Kabeln wird nach folgendem [Schema](https://github.com/viper-666/xf_roof_module/blob/master/Verkabelung.pdf) erstellt und in den Kabelbaum des Crossfire eingebunden.
Die in Blau bezeichneten PINs gehören auf den entsprechenden PINs des Steckers. 
Die Pins für den Stecker sollten mit einer Crimpzange auf die abisolierten Kabelenden aufgekrimpt werden. Falls du keine Crimpzange hast, diese gibt es günstig für 10-20€ oder du kannst die Kabelenden auch mit den Pins verlöten.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper010.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper011.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper012.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper013.JPG)

So sieht das fertige Modul mit dem gedruckten Gehäuse aus:

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper014.JPG)

Ich empfehle den Bau eines Deaktivierungssteckers, dieser wird bei Problemen oder Verkauf des Autos anstatt des Dachmoduls eingesteckt. Damit werden die durchtrennten Leitungen wieder verbunden und der "Originalzustand" wieder hergestellt.
Dafür einfach bei einer Buchse folgende Pins verbinden:

|A|B|
|---|---|
|PIN 3|PIN 11|
|PIN 7|PIN 12|
|PIN 9|PIN 13|

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper002.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper003.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper004.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper005.JPG)


### Installation der Software

Einfach das [Sketch](https://github.com/viper-666/xf_roof_module/blob/master/Crossfire_Dachmodul-4.ino) mit der [ARDUINO IDE](https://www.arduino.cc/en/Main/Software) auf den Arduino laden.


### Einbau in den Crossfire

Der im vorherigen Punkt erstellte Stecker mit den Kabeln wird nun nach folgenden [Schema](https://github.com/viper-666/xf_roof_module/blob/master/Verkabelung.pdf) im Crossfire verkabelt.

Ich empfehle die Kabel zu verlöten und mit Schrumpfschlauch zu isolieren. 

Wir fangen am Dachschalter an. Um an den Dachschalter zu kommen den Cup-Holder aufmachen, mit den Fingern in die Öffnung greifen und die silbernene Blende vorne an der Schaltung anheben bis sie sich aus der Rasterung löst.
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper026.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper025.JPG)
Anschließend muss das Weiß/Violette Kabel durchtrennt werden und das Rosa Kabel unseres Steckers mit dem Teil des Weiß/Violetten Kabels verbunden werden welches noch am Stecker hängt. Das Schwarze Kabel des Steckers kommt an das nun noch offene Ende des Weiß/Violetten Kabels.
Das Weiße Kabel unseres Steckers kommt nun noch an das Braun/Gelbe Kabel.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper18.JPG)

Jetzt müssen wir im Beifahrerfußraum den Teppich hoch heben und in Richtung Sitz klappen und die weiße Styrophor Platte weg nehmen.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper020.JPG)

Die silberne Blechplatte ist mit 3 schwarzen Kunststoffmuttern gesichert, welche entfernt werden müssen.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper021.JPG)

Nun können wir diese in Richtung Sitz weg klappen. Der Kabelbaum mit den benötigten Kabeln ist rechts oben.

![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper16.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper17.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper19.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper15.JPG)

In diesem Kabelbaum müssen wir nun folgende Kabel suchen:
- Rosa/Rot/Schwarz (+12V) dieses verbinden wir mit dem roten Kabel des Steckers
- Braun (Masse) dieses verbinden wir mit den braunen Kabel des Steckers
- Blau/Grün (BCM PIN 56) dieses muss durchtrennt werden und an das Kabelende welches nach links zur Mittelkonsole geht kommt das gelbe und an das andere Ende das blaue Kabel des Steckers
- Grün/Weiß (BCM PIN 74) hier muss man aufpassen, das Kabel ist mehrfach vorhanden. Am besten man testet mit einen Multimeter in Durchgangsprüfung ob man das richtige Kabel vom Steuergerät PIN 74 erwischt hat. Dann muss dieses durchtrennt werden und an das Kabelende welches nach links zur Mittelkonsole geht kommt das orange und an das andere Ende das grüne Kabel des Steckers

Wenn noch genügend Platz im Kasten für das RCM-Modul und dem Steuergerät ist kann man die Kabel auch direkt am Stecker des Steuergerätes abgreifen und muss nur die Kabel für den Dachschalter durch die Durchführung des Kabelbaumes nach innen führen.
Vorteil ist, die bessere Zugänglichkeit und das man die Kabel eindeutig am Stecker findet, da dort die PIN-Nummern lesbar sind.
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper022.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper023.JPG)
![Build of the prototyp-PCB](https://github.com/viper-666/xf_roof_module/blob/master/Viper024.JPG)


## Erstellt mit:

* [ARDUINO](https://www.arduino.cc/en/Main/Software) - Ich habe die Version 1.6.8 verwendet
* [EAGLE](https://www.autodesk.com/products/eagle/free-download) - Die Software ist für den privaten Gebrauch kostenlos abe du benötigst einen Autodesk Account.


## Autor

* **Andre Holtkamp** - [viper-666](https://github.com/viper-666)


## License

Dieses Projekt steht unter GNU General Public License v3.0 License - schau dir die [LICENSE](https://github.com/viper-666/xf_roof_module/blob/master/LICENSE) an fuer details.

