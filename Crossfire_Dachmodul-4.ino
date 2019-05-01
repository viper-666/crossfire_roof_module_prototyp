/**
 * Chrysler Crossfire Roadster Dachmodul
 * Funktionen:
 * -Halten des Tasters für Dach-Auf und Dach-Zu entfällt, einfach Taster 1x kurz drücken.
 * -Öffnen und Schließen des Daches bis zu x km/h
 * Skript von Andre Holtkamp AKA Viper 
 * V1.1 vom 05/2018 
 * https://crossfire-forum-deutschland.de/viewtopic.php?f=8&t=694#p5604
 * 
 * Anschluss Dachsteuerung PINS Arduino
 * PIN2 = Frequenz Eingang (Radfrequenz 6Hz pro km/h Grün/Weiß vom Steuergerät PIN 74 kommend)
 * PIN8 = Dach auf zum Transistor
 * PIN4 = Dach zu zum Transistor
 * PIN5 = LED-Dachschalter
 * PIN9 = erzeugte 3Hz
 */
 
 #define OUT_PIN_AUF 8  // Arduino Digital I/O pin für Ausgang Dach Auf zum Transistor
 #define OUT_PIN_ZU 4  // Arduino Digital I/O pin für Ausgang Dach Zu zum Transistor
 #define LED_SCHALTER 5  // Arduino Digital I/O pin für Eingang Schalter LED im Dachschalter AN/AUS
 #define FREQ_3HZ 9      // Arduino Digital I/O pin für Ausgang 3Hz Erzeugung
 #define OUT_PIN_F 6  // Arduino Digital I/O pin für Ausgang schaltet Transistor für ABS-Steuersignal 3Hz/21Hz (HIGH=PIN 56 Steuergerät durchgeschaltet)
 #define OUT_PIN_F1 7  // Arduino Digital I/O pin für Ausgang  schaltet Transistor für Radfrequenz Geschwindigkeitssignal (HIGH=PIN 74 Steuergerät durchgeschaltet)
 #define BUZZER 10  // Arduino Digital I/O pin für BUZZER

 long f = 0;
 int FENSTERZU = 0;  // Variable Fenster ZU/AUF
 int FENSTERZUA = 0;  // Variable Fenster ZU/AUF automatische schließen Fenster
 int LED = 0;  // Variable LED AN/AUS
 int IN_PIN_AUF_ZU = 0;  // Arduino Analog I/O pin für Ausgang Dach Auf
 int AKTIVIERT = 0;   // Speichert ob das Dach gerade göffnet/geschlossen wird
 int SPEED = 0;   // Speichert ob das Dach gerade göffnet/geschlossen wird und die Geschwindigkeit überschritten wurde
 int  HOLD1 = 0;   // Variable um das Dach bei Geschwindigkeiten zwischen 7km/h bis GESCHWINDIGKEIT zu freizuschalten
 int  HOLD_AN_AUS = 0;   // Variable um das Dach bei Geschwindigkeiten zwischen 7km/h bis GESCHWINDIGKEIT zu freizuschalten
 String MELDUNG = "";   // Debugvariable
 int ZFZU = 0;   //Zählvariable
 int ANALOG_EINGANG0 = 0;   //Zählvariable unsigned long currentTime; // Zeitvariable aktuell
unsigned long loopTime = 0; // Zeitvariable gespeichert
unsigned long loopTimeMAX = 0; // Zeitvariable Max Öffnen7Schließen gespeichert
unsigned long loopTimeFZU = 0; // Zeitvariable gespeichert
unsigned long loopTimeHOLD = 0; //Zeitvariable um zwischen 7km/h bis GESCHWINDIGKEIT freizuschalten

// Frequenz messen
unsigned long Timestamp;
volatile unsigned long count;

// Diese Variablen können angepasst werden
 int KARENZZEIT = 1000; // Karenzzeit zwischen zwei Tastendrücken in ms
 int DOPPELKLICKZEIT = 300; // Zeit in zwischen Doppelklick zum Fensterschließen ms
 long MAXLAUFZEIT = 30000; // Zeit welche das Dachöffnen/schließen Signal max. geschaltet wird in ms
 const unsigned long Tmess = 200; // Messfrequenz Frequenzmessung in ms
 int TimeHOLD = 10000; // Zeitvariable wie lange zwischen 7km/h bis GESCHWINDIGKEIT freigeschaltet wird in ms
 int TimeHOLD_AN = 2000; // Zeitvariable wann Ausgang Dach AUF/ZU geschaltet wird in ms
 int GESCHWINDIGKEIT = 55; //Geschwindigkeit bis zu der das Dach geöffnet werden kann

void setup() {

  // Serielle Schnittstelle starten
    Serial.begin(115000);
 
  // Setup TASTER
  pinMode(LED_SCHALTER,INPUT);

  // Setup Ausgänge
  pinMode(OUT_PIN_AUF,OUTPUT);
  pinMode(OUT_PIN_ZU,OUTPUT);
  pinMode(OUT_PIN_F,OUTPUT);  
  pinMode(OUT_PIN_F1,OUTPUT);
  pinMode(FREQ_3HZ, OUTPUT);
  
    // Activiere internen pull-up
  digitalWrite(LED_SCHALTER,LOW);
 
  //Schalte Frequenz vom Radsensor durch
    digitalWrite(OUT_PIN_F, HIGH); //ABS-Steuersignal durchschalten 3Hz
    digitalWrite(OUT_PIN_F1, HIGH); //Radfrequenz durchschalten Geschwindigkeitssignal

  // Frequenz
    attachInterrupt(0, ISR_f, RISING); // Interrupt an Pin2

 // Erste Zeile für Frequenzmessung auf Serieller Schnittstelle ausgeben   
     Serial.print("Frequenz");Serial.print("\t");
     Serial.print("Debugmeldung"); Serial.print("\t");
     Serial.print("Analogeingang");Serial.println("\t");
     Serial.print("Aktiviert");Serial.print("\t\t");
     Serial.print("Hold");Serial.print("\t\t"); 
     Serial.print("HOLD_AN_AUS");Serial.print("\t\t");
     Serial.print("LED");Serial.print("\t\t");
     Serial.print("LED-Schalter");Serial.print("\t\t");
     Serial.print("ZFZU");Serial.print("\t\t");
     Serial.println();

  // Timer 1 erzeugen
  noInterrupts();           // Alle Interrupts temporär abschalten
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 56066;            // Timer auf 3Hz stellen
  TCCR1B |= (1 << CS12);    // 256 als Prescale-Wert spezifizieren
  interrupts();             // alle Interrupts scharf schalten
}

// 3Hz Frequenz erzeugen
ISR(TIMER1_OVF_vect)        
{
  TCNT1 = 56066;             // Timer auf 3Hz stellen
  digitalWrite(FREQ_3HZ, digitalRead(FREQ_3HZ) ^ 1); // Port HIGH/LOW
}

void loop() {


// Analogwert vom Dacheingangsschalter lesen und auf Serieller Schnittstelle ausgeben
  ANALOG_EINGANG0 = analogRead(IN_PIN_AUF_ZU);    // Schalter Analog einlesen


// Frequenz
   if ( millis()-Timestamp > Tmess){
    f = (count * long(1000))/ Tmess;
  
// Debug auf Serieller Schnittstelle ausgeben
     Serial.print(f);Serial.print("\t\t");
     Serial.print(MELDUNG); Serial.print("\t\t");
     Serial.print(ANALOG_EINGANG0);Serial.print("\t"); 
     Serial.print(AKTIVIERT);Serial.print("\t");
     Serial.print(HOLD1);Serial.print("\t");  
     Serial.print(HOLD_AN_AUS);Serial.print("\t");
     Serial.print(LED);Serial.print("\t");
     Serial.print(digitalRead(LED_SCHALTER));Serial.print("\t");
     Serial.print(ZFZU);Serial.print("\t");
     Serial.println("\t");

// Auswertung Taster**************************************************************************************************************************
   
// Überprüfe ob Taster Dach-AUF gedrückt wird
if ((millis() >= (loopTime + KARENZZEIT)) && (HOLD_AN_AUS == 0) && (f < (GESCHWINDIGKEIT*6)) && (digitalRead(LED_SCHALTER) == HIGH) && ((ANALOG_EINGANG0 > 10) && (ANALOG_EINGANG0 < 300)) && (AKTIVIERT == 0)) {
    //Schalte Frequenz an:
    F3HZ_AN();   
    // schalte Ausgang an:
    digitalWrite(OUT_PIN_AUF, HIGH);
    AKTIVIERT = 1; // Dach auf/zu aktiviert
    FENSTERZU = 1;
    FENSTERZUA = 1;
    HOLD_AN_AUS = 1;
    loopTime = millis(); // Laufzeit setzen
    loopTimeMAX = millis(); // Laufzeit setzen
    HOLD1 = 0;
    MELDUNG = "Taster AUF";
  } 

 // Überprüfe ob Taster Dach-ZU gedrückt wird
if ((millis() >= (loopTime + KARENZZEIT)) && (HOLD_AN_AUS == 0) && (f < (GESCHWINDIGKEIT*6)) && (digitalRead(LED_SCHALTER) == HIGH) && (ANALOG_EINGANG0 < 10)) {
    //Schalte Frequenz an:
    F3HZ_AN();  
   // schalte Ausgang an
    digitalWrite(OUT_PIN_ZU, HIGH);
    HOLD_AN_AUS = 2;
    AKTIVIERT = 1;// Dach auf/zu aktiviert
    FENSTERZU = 1;
    FENSTERZUA = 2;
    loopTime = millis(); // Laufzeit setzen
    loopTimeMAX = millis(); // Laufzeit setzen
    HOLD1 = 0;
    MELDUNG = "Taster Zu";
  } 

// Überprüfe ob Taster Dach-AUF gedrückt wird und LED im Taster nicht an ist
if ((digitalRead(LED_SCHALTER) == LOW) && (f < (GESCHWINDIGKEIT*6)) && ((ANALOG_EINGANG0 > 10) && (ANALOG_EINGANG0 < 300)) && (AKTIVIERT == 0)) {
    F3HZ_AN();
    // schalte Ausgang an
    //digitalWrite(OUT_PIN_AUF, HIGH);
    HOLD1 = 1;
    HOLD_AN_AUS = 1;
    loopTimeHOLD = millis();
    AKTIVIERT = 1;// Dach auf/zu aktiviert
    FENSTERZU = 1;
    FENSTERZUA = 1;
    loopTime = millis(); // Laufzeit setzen
    loopTimeMAX = millis(); // Laufzeit setzen
    MELDUNG = "Taster AUF ohne LED*";
      } 

      
 // Überprüfe ob Taster Dach-ZU gedrückt wird wird und LED im Taster nicht an ist
if ((digitalRead(LED_SCHALTER) == LOW) && (f < (GESCHWINDIGKEIT*6)) && (ANALOG_EINGANG0 < 10) && (AKTIVIERT == 0)) {
    // schalte Frequenz
    F3HZ_AN();
    //digitalWrite(OUT_PIN_ZU, HIGH);
    HOLD1 = 1;
    HOLD_AN_AUS = 2;
    loopTimeHOLD = millis();
     AKTIVIERT = 1;// Dach auf/zu aktiviert
     FENSTERZU = 1;
     FENSTERZUA = 2;
    loopTime = millis(); // Laufzeit setzen
    loopTimeMAX = millis(); // Laufzeit setzen
    MELDUNG = "Taster ZU ohne LED*";
      } 

// Überprüfe ob Taster Dach-AUF gedrückt, Dach schon geöffnet oder geschlossen wird und KARENZZEIT vergangen ist (STOP)
if ((millis() >= (loopTime + KARENZZEIT)) && (AKTIVIERT == 1) && ((ANALOG_EINGANG0 > 10) && (ANALOG_EINGANG0 < 300))) {
    loopTime = millis(); // Laufzeit setzen
    MELDUNG = "STOP AUF";
    STOP (0);
      } 

 // Überprüfe ob Taster Dach-ZU gedrückt, Dach schon geöffnet oder geschlossen wird und KARENZZEIT vergangen ist (STOP)
if ((millis() >= (loopTime + KARENZZEIT)) && (AKTIVIERT == 1) && (ANALOG_EINGANG0 < 10)) {
    loopTime = millis(); // Laufzeit setzen
    MELDUNG = "STOP ZU";
    STOP (0);
      } 


// Fenstersteuerung ***************************************************************************************************************************
// Fenster automatisch schließen nach Dach öffnen
    if ((millis() >= (loopTimeFZU + 4 * DOPPELKLICKZEIT)) && (ZFZU==1) && (FENSTERZUA == 1)) {
    digitalWrite(OUT_PIN_AUF, HIGH);
    ZFZU++;
    MELDUNG = "Fenster schließen";
    }
  
    if (millis() >= (loopTimeFZU + (5 * DOPPELKLICKZEIT)) && (ZFZU==2) && (FENSTERZUA == 1)) {
    digitalWrite(OUT_PIN_AUF, LOW);
    ZFZU++;
    }
    
    if (millis() >= (loopTimeFZU + (6 * DOPPELKLICKZEIT)) && (ZFZU==3) && (FENSTERZUA == 1)) {
    digitalWrite(OUT_PIN_AUF, HIGH);
    ZFZU++;
    }
    
    if (millis() >= (loopTimeFZU + (22 * DOPPELKLICKZEIT)) && (ZFZU==4) && (FENSTERZUA == 1)) {
    digitalWrite(OUT_PIN_AUF, LOW);
    ZFZU = 0;
    FENSTERZUA = 0;
    }


// Fenster automatisch schließen nach Dach schließen
    if ((millis() >= (loopTimeFZU + 4 * DOPPELKLICKZEIT)) && (ZFZU==1) && (FENSTERZUA == 2)) {
    digitalWrite(OUT_PIN_ZU, HIGH);
    ZFZU++;
    MELDUNG = "Fenster schließen";
    }
  
    if (millis() >= (loopTimeFZU + (5 * DOPPELKLICKZEIT)) && (ZFZU==2) && (FENSTERZUA == 2)) {
    digitalWrite(OUT_PIN_ZU, LOW);
    ZFZU++;
    }
    
    if (millis() >= (loopTimeFZU + (6 * DOPPELKLICKZEIT)) && (ZFZU==3) && (FENSTERZUA == 2)) {
    digitalWrite(OUT_PIN_ZU, HIGH);
    ZFZU++;
    }
    
    if (millis() >= (loopTimeFZU + (22 * DOPPELKLICKZEIT)) && (ZFZU==4) && (FENSTERZUA == 2)) {
    digitalWrite(OUT_PIN_ZU, LOW);
    ZFZU = 0;
    FENSTERZUA = 0;
    }



//**************************************************************************************************************************

 // LED im Taster

if ((digitalRead(LED_SCHALTER) == HIGH) && (AKTIVIERT == 1)) {
 LED = 1;
 MELDUNG = "LED=1";
}

if ((digitalRead(LED_SCHALTER) == LOW) && (AKTIVIERT == 1) && (LED == 1)) {
 STOP (1);
 LED = 0;
 MELDUNG = "Stop LED";
}

// Max. Laufzeit wo der Tastendruck Dach AUF/ZU simuliert wird ist abgelaufen (STOP)
if ((millis() >= (loopTimeMAX + MAXLAUFZEIT)) && (AKTIVIERT == 1) && (ANALOG_EINGANG0 > 300)) {
    loopTime = millis(); // Laufzeit setzen
    loopTimeMAX = millis(); // Laufzeit setzen
    MELDUNG = "Laufzeit abgelaufen";
    STOP (0);
  } 

// Dach_AUF ist gedrückt ohne LED und Wartezeit abgelaufen
if ((millis() >= (loopTimeHOLD + TimeHOLD_AN)) && (HOLD1 == 1) && (HOLD_AN_AUS == 1) && (ANALOG_EINGANG0 > 300)) {
    MELDUNG = "Schalte_Auf";
    digitalWrite(OUT_PIN_AUF, HIGH);
  } 

// Dach_ZU ist gedrückt ohne LED und Wartezeit abgelaufen
if ((millis() >= (loopTimeHOLD + TimeHOLD_AN)) && (HOLD1 == 1) && (HOLD_AN_AUS == 2) && (ANALOG_EINGANG0 > 300)) {
    MELDUNG = "Schalte_Zu";
    digitalWrite(OUT_PIN_ZU, HIGH);
  } 

// Max. Laufzeit Freischaltung ist abgelaufen
if ((millis() >= (loopTimeHOLD + TimeHOLD)) && (HOLD1 == 1) && (AKTIVIERT == 0) && (ANALOG_EINGANG0 > 300)) {
    MELDUNG = "Laufzeit Freischaltung abgelaufen";
    STOP (0);
  } 

//  Geschwindigkeit überprüfen**************************************************************************************************************************
 
 if ((f < (GESCHWINDIGKEIT*6)) && (AKTIVIERT==1) && (SPEED == 1) && (HOLD_AN_AUS == 1)) {
     MELDUNG = "Schalte_Auf";
    digitalWrite(OUT_PIN_AUF, HIGH);
    loopTime = millis(); // Laufzeit setzen
    loopTimeMAX = millis(); // Laufzeit setzen
    digitalWrite(BUZZER, LOW);
    SPEED = 0;        
  }

 if ((f < (GESCHWINDIGKEIT*6)) && (AKTIVIERT==1) && (SPEED == 1) && (HOLD_AN_AUS == 2)) {
     MELDUNG = "Schalte_Zu";
    digitalWrite(OUT_PIN_ZU, HIGH);
    loopTime = millis(); // Laufzeit setzen
    loopTimeMAX = millis(); // Laufzeit setzen
    digitalWrite(BUZZER, LOW);
    SPEED = 0;        
  }

if ((f > (GESCHWINDIGKEIT*6))&& (AKTIVIERT==1))
    {
    MELDUNG = "Zu schnell";
    digitalWrite(OUT_PIN_ZU, LOW); //Dach zu Stop
    digitalWrite(OUT_PIN_AUF, LOW); //Dach Auf Stop
    digitalWrite(BUZZER, HIGH);
    SPEED = 1;
    }

     count = 0;
     Timestamp = millis();
     interrupts();
  } 
}


//  Funktionen##############################################################################################################################################

// Frequenz
void ISR_f(){
  count++;
}

// Schalte alles AUS 
void STOP (boolean FZU) {
  F3HZ_AUS();
  digitalWrite(OUT_PIN_AUF, LOW);
  digitalWrite(OUT_PIN_ZU, LOW);
  LED = 0;
  AKTIVIERT = 0;
  HOLD1 = 0;
  HOLD_AN_AUS = 0;
  MELDUNG = "STOP Ausgefuehrt";
  MELDUNG = "STOP Ausgefuehrt";

 // Fenster schließen
 if ((FZU==1) && (FENSTERZU == 1)) {
  loopTimeFZU = millis(); // Laufzeit setzen
   FZU=0; 
   ZFZU=1;
   MELDUNG = "Fenster zu aktiviert";
   }
}

// schalte 3HZ Frequenz an
void F3HZ_AN() {
    digitalWrite(OUT_PIN_F, LOW); //ABS-Steuersignal blockieren 3Hz
    digitalWrite(OUT_PIN_F1, LOW); //Radfrequenz blockieren Geschwindigkeitssignal
    noInterrupts();
    TIMSK1 |= (1 << TOIE1); // Timer Overflow Interrupt aktivieren
    interrupts();
}

// schalte 3HZ Frequenz aus
void F3HZ_AUS() {
    noInterrupts();
    TIMSK1 &= (~(1 << TOIE1)); // Timer Overflow Interrupt deaktivieren
    interrupts();
    digitalWrite(9, LOW);  //Frequenzausgang Low schalten
    digitalWrite(OUT_PIN_F, HIGH); //ABS-Steuersignal durchschalten 3Hz
    digitalWrite(OUT_PIN_F1, HIGH); //Radfrequenz durchschalten Geschwindigkeitssignal
}



