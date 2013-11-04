#ifndef _ROTARYENC_h_
#define _ROTARYENC_h_

typedef struct {
	volatile uint8_t		*port;
	volatile uint8_t		*pin;
	volatile uint8_t		*ddr;
	uint8_t				pinNr_A;
	uint8_t				pinNr_B;
	uint8_t				internPullup;
	uint8_t				autoAcceleration;
	uint16_t				accerelationFactor;
	uint16_t				__value;
	uint8_t				__cache_000000BA;
	float					__averageRotation;
	
} type_ROTARYENC;

void ROTARYENC_INIT (type_ROTARYENC *device);
uint8_t ROTARYENC_READ (type_ROTARYENC *device);
void ROTARYENC_RUN (type_ROTARYENC *device);
int16_t ROTARYENC_GET (type_ROTARYENC *device);

#define _A	(1<<0)
#define _B	(1<<1)

#define	True	1
#define	False	0

#endif
