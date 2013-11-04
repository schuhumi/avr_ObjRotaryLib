#include <avr/io.h>
#include "ROTARYENC.h"

/// DEVICES ///////////////////////////////////////////////////
	type_ROTARYENC encoder_A;
	type_ROTARYENC encoder_B;
/// END DEVICES ///////////////////////////////////////////////

void RUN_THIS_EVERY_1MS (void)		// Without this the rotary encoders won't do anything
{
	ROTARYENC_RUN(&encoder_A);
	ROTARYENC_RUN(&encoder_B);
}
	
int main (void)
{	
	
	/// Configure Devices //////////////////////////////////////
	// Rotary encoder A  configuration
		encoder_A.ddr = &DDRC;
		encoder_A.port = &PORTC;
		encoder_A.pin = &PINC;
		encoder_A.pinNr_A = PC6;
		encoder_A.pinNr_B = PC5;
		encoder_A.internPullup = True;
		encoder_A.autoAcceleration = True; // -> When rotaryknob is turned faster, the counts per step rise automatically...
		encoder_A.accerelationFactor = 200; // ...according to this value
	
	// Rotary encoder B  configuration
		encoder_B.ddr = &DDRC;
		encoder_B.port = &PORTC;
		encoder_B.pin = &PINC;
		encoder_B.pinNr_A = PC3;
		encoder_B.pinNr_B = PC2;
		encoder_B.internPullup = True;
		encoder_B.autoAcceleration = True;
		encoder_B.accerelationFactor = 100;
	/// END Configure Devices //////////////////////////////////
	
	/// INIT Devices ///////////////////////////////////////////
	// INIT rotary encoders
		ROTARYENC_INIT(&encoder_A);
		ROTARYENC_INIT(&encoder_B);
	/// END INIT Devices ///////////////////////////////////////

	int ChangeSinceLastReading = 0;
	int RotationInTotal = 0;
	while(1)
	{
		ChangeSinceLastReading = ROTARYENC_GET(&encoder_A);
		RotationInTotal += ROTARYENC_GET(&encoder_B);
	}

	return 0;
}
