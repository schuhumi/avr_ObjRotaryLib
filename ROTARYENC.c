#include <avr/io.h>
#include "ROTARYENC.h"

void ROTARYENC_INIT (type_ROTARYENC *device)
{
	*device->ddr &= ~(1<<(device->pinNr_A));
	*device->ddr &= ~(1<<(device->pinNr_B));
	if(device->internPullup)
	{
		*device->port |= (1<<(device->pinNr_A));
		*device->port |= (1<<(device->pinNr_B));
	}
	else
	{
		*device->port &= ~(1<<(device->pinNr_A));
		*device->port &= ~(1<<(device->pinNr_B));
	}
	device->__value = 0;
	device->__averageRotation = 0;
	device->__cache_000000BA = ROTARYENC_READ(device);
}

uint8_t ROTARYENC_READ (type_ROTARYENC *device)
{
	uint8_t cache = 0;
	cache |= ((*device->pin)&(1<<device->pinNr_A))?_A:0;
	cache |= ((*device->pin)&(1<<device->pinNr_B))?_B:0;
	return cache;
}

void ROTARYENC_RUN (type_ROTARYENC *device)
{
	uint8_t now_BA = ROTARYENC_READ(device);
	uint8_t cache_BA = device->__cache_000000BA;
	if(cache_BA != now_BA)												// Rotaryencoder was turned since last read-out
	{
		if( (~now_BA&_A) && (~now_BA&_B) )
		{
			if( (cache_BA&_A) && (~cache_BA&_B) )
			{
				device->__value += 1+((device->autoAcceleration)?(device->__averageRotation*device->accerelationFactor):0);
				device->__averageRotation= (device->__averageRotation*149+1)/150;
			}
			else if( (~cache_BA&_A) && (cache_BA&_B) )
			{
				device->__value -= 1+((device->autoAcceleration)?(device->__averageRotation*device->accerelationFactor):0);	
				device->__averageRotation=(device->__averageRotation*149+1)/150;
			}

		}
	}			
	else
	{
		device->__averageRotation=(device->__averageRotation*149+0)/150;
	}	
	device->__cache_000000BA = now_BA;
}



int16_t ROTARYENC_GET (type_ROTARYENC *device)
{
	uint16_t temp = device->__value;
	device->__value = 0;
	return temp;
}
