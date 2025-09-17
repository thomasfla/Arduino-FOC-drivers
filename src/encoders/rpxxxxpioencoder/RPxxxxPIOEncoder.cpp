#include "RPxxxxPIOEncoder.h"
#include "quadrature_encoder.pio.h"
RPxxxxPIOEncoder::RPxxxxPIOEncoder(int pinAB, PIO pio, int cpr){
    _pinAB = pinAB;
    _cpr = cpr;
    _pio = pio;
}

void RPxxxxPIOEncoder::init() {
    // TODO: configure PIO program for quadrature decoding
    _sm = 0; //Todo find next available SM

    // we don't really need to keep the offset, as this program must be loaded
    // at offset 0
    pio_add_program(_pio, &quadrature_encoder_program);
    quadrature_encoder_program_init(_pio, _sm, _pinAB, 0);
}


float RPxxxxPIOEncoder::getSensorAngle()
{
    return ((float)quadrature_encoder_get_count(_pio,_sm)/_cpr);

}