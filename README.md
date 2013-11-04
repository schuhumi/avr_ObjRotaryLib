avr_ObjRotaryLib
================

This is a more object-orientated rotary-encoders-library for AVR Microcontrollers written in C.

This library consits of:

    ROTARYENC.h
    ROTARYENC.c

and offers:

    handle infinite number of rotary encoders with no duplicate code
    functions:
        ROTARYENC_INIT: Initialise rotary encoders
        ROTARYENC_RUN: This function must be run every ~1-5ms to catch every movement of the encoders
        ROTARYENC_GET: Gives you the amount of rotation since you called this function the last time

There are examples in main.c, which show the basics.