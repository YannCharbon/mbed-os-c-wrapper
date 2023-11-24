/*
 * Copyright 2023 Yann Charbon <yann.charbon@heig-vd.ch>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "DigitalInOutWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_digitalinout_t mbed_digitalinout_create(PinName pin) {
    return new DigitalInOut(pin);
}

mbed_digitalinout_t mbed_digitalinout_create1(PinName pin, PinDirection direction, PinMode mode, int value) {
    return new DigitalInOut(pin, direction, mode, value);
}

void mbed_digitalinout_write(mbed_digitalinout_t p, int value) {
    MBED_ASSERT(p != nullptr);
    ((DigitalInOut *) p)->write(value);
}

int mbed_digitalinout_read(mbed_digitalinout_t p) {
    MBED_ASSERT(p != nullptr);
    return ((DigitalInOut *) p)->read();
}

void mbed_digitalinout_output(mbed_digitalinout_t p) {
    MBED_ASSERT(p != nullptr);
    ((DigitalInOut *) p)->output();
}

void mbed_digitalinout_input(mbed_digitalinout_t p) {
    MBED_ASSERT(p != nullptr);
    ((DigitalInOut *) p)->output();
}

void mbed_digitalinout_mode(mbed_digitalinout_t p, PinMode pull) {
    MBED_ASSERT(p != nullptr);
    ((DigitalInOut *) p)->mode(pull);
}

int mbed_digitalinout_is_connected(mbed_digitalinout_t p) {
    MBED_ASSERT(p != nullptr);
    return ((DigitalInOut *) p)->is_connected();
}

void mbed_digitalinout_free(mbed_digitalinout_t p) {
    delete (DigitalInOut *) p;
}

}