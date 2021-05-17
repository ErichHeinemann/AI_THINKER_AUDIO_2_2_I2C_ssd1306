#include <Arduino.h>
#include <MIDI.h>
#include <esp_now.h>


// TEST how to get a MIDI-Port up and running with the FortysevenEffects-MIDI-Library on the ESP32 on PIN 22 as RX-Pin
// There aree not a lot of sources which reeally helped to mapp MIDI IN/OUT to other PINs
// the finall helping hint was: https://github.com/rheslip/Motivation-Radio-BLEMIDI/blob/master/BLEmidi.ino

// Free in any way - Erich Heinemann


struct Serial2MIDISettings : public midi::DefaultSettings
{
  static const long BaudRate = 31250;
  static const int8_t RxPin  = 22;
  static const int8_t TxPin  = 19; // LED-Pin
};

HardwareSerial MIDISerial(2);

MIDI_CREATE_CUSTOM_INSTANCE( HardwareSerial, MIDISerial, MIDI, Serial2MIDISettings );

void setup(){
    // Initiate MIDI communications, listen to all channels
    pinMode( 22 , INPUT_PULLUP);  /* 22: GPIO 22, u2_RXD */
    //Serial2.begin(31250, SERIAL_8N1, 22, 19);
    // midiA.begin(MIDI_CHANNEL_OMNI);
     MIDISerial.begin(31250, SERIAL_8N1, 22,19 ); // midi port
     
    Serial.begin(115200);
    Serial.println();
    Serial.printf("Setup Done\n");
}

void loop(){
 
  if( MIDI.read() ){
        // Thru on A has already pushed the input message to out A.
        // Forward the message to out B as well.
        Serial.println( MIDI.getType() );
        Serial.println( MIDI.getData1() );
        Serial.println( MIDI.getData2() );
        Serial.println( MIDI.getChannel() );
    }
    // Serial.println("x");
}
