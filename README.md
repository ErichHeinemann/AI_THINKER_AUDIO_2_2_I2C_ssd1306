# AI_THINKER_AUDIO_2_2_TESTs

I bought 3 x AI THINKER AUDIO 2.2 Boards to rebuild the Synth, Drum  and Sampler - Modules developed by Marcel Licence.
As Marcel uses a MIDI-Controller with a rich MIDI-Controller-Interface - I had some problems to use his implementations with 
my simple Keyboard which does not send any CC-Messages.
My plan was to add some local Buttons, Pots, Rotary Encoder and a Display via I2C.
To get a running I2C-Bus beside the interenal I2C-Bus to the Audio-Codec on this special board, I needed to remove R68 and R70 for Key 4 and Key 6.
Now with this modification IO 5 and IO 23 could be used as a new second I2C-Bus.
IO5 would be SDA, IO23 is SCL.

If You use this I2C with Core0 in an extra TASK-Handle while Core1 is controlling the Audio, this I2C could be used only
with 50.000 Hz - not with 400.000 Hz! - it took me days to get that.

The second Arduino-Sketch uses PIN 22 for the well know MIDI-Library ( by FortysevenEffects).
.. same situation here, there is not a lot information available for this in combination with this well sounding baard.

To drive the A1S-101 Audio-Chip, I recommend to take a look at the Github Repo of Marcel Licence and his good Audio-Examples for Musicians.
https://github.com/marcel-licence

Erich Heinemann
