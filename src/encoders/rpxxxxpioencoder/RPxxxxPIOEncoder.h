#pragma once
#include "Arduino.h"
#include "common/base_classes/Sensor.h"

/**
 * @brief Encoder implementation using RPxxxx (RP2040 / RP2350 etc.) PIO hardware.
 */
class RPxxxxPIOEncoder : public Sensor {
public:
    /**
     * @brief Construct a new RPxxxxPIOEncoder object
     * 
     * @param pinAB Encoder channel A pin (channel B is pinAB+1)
     * @param pio  PIO instance
     * @param cpr  Counts per revolution
     */
    RPxxxxPIOEncoder(int pinAB, PIO pio, int cpr);

    /** @brief Initialize hardware resources */
    void init() override;

    /** @brief Get current angle in radians */
    float getSensorAngle() override;

private:
    int _cpr;
    PIO _pio;
    int _pinAB;
    uint _sm;          // state machine index
};