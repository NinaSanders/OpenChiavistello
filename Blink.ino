/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update


  Questo programma e' derivato da programmi presenti nella libreria MFRC522.
  Per maggiori dettagli sull'utilizzo della scheda RC522 fare riferimento
  alla suddetta libreria, reperibile in https://github.com/miguelbalboa/rfid

  Nota: La libreria utilizza in maniera predefinita alcune porte di Arduino
  per cui, per poter ripetere questo esercizio, e' necessario rispettare i
  seguenti collegamenti tra i pin della scheda RC522 e le porte di Arduino:
  -----------------------------------------------------------------------------------------
  ...........pin ......Arduino ......Arduino ...Arduino......Arduino........ Arduino
  Segnale....MFRC522 ... Uno ......... Mega .....Nano v3...Leonardo/Micro....ProMicro
  ----------------------------------------------------------------------------- -----------
  RST/Reset ...RST ..... 9 ........... 5 ......... D9 ......RESET/ICSP-5 ..... RST
  SPI SS .....SDA(SS)... 10 .......... 53 ........ D10 ........ 10 ........... 10
  SPI MOSI ....MOSI .... 11 .......... 51 ........ D11 .......ICSP-4 ......... 16
  SPI MISO ....MISO .... 12 .......... 50 ........ D12 .......ICSP-1 ......... 14
  SPI SCK .....SCK ..... 13 .......... 52 ........ D13 .......ICSP-3 ......... 15
  --------------------------------------------------------------------------------------

  ---------------------------------------------------------------------------------------
  Warning: cut&paste from PDF to IDE loses formatting. to restore it press CTRL + T.
  This program is derived from programs in MFRC522 library.
  Note: The library uses by default, some Arduino pins so, to be able to repeat this exercise, you
  must comply with the above connections between pins of RC522 device and Arduino.
  ----------------------------------------------------------------------------------------
*/
#include <SPI.h> // richiama la libreria di gestione del bus SPI
#include <MFRC522.h> // richiama la libreria di gestione del lettore rc522
#define SS_PIN D4
#define RST_PIN D3

MFRC522 mfrc522(SS_PIN, RST_PIN);

char codice [4];
int i = 0;

void setup () {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();
}
void loop () {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Avvicinare una scheda");

    return; // ricomincia il loop se non c'e' nulla vicino al lettore
  }
  else {
    Serial.print("Letta Scheda con Codice Identificativo : ");
    for (i = 0; i < mfrc522.uid.size; i++) // acquisisce, tramite le funzioni della libreria,
      // l'identificativo della scheda
    {
      Serial.print (mfrc522.uid.uidByte[i]); // visualizza il codice della scheda letta (valore ascii
      // dei quattro caratteri identificativi della scheda)
      Serial.print (" ");
      codice [i] = mfrc522.uid.uidByte[i];
    }
    Serial.println (codice);
  }
}
