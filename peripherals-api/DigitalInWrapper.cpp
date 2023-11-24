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

#include "DigitalInWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_digitalin_t mbed_digitalin_create(PinName pin) {
    return new DigitalIn(pin);
}

mbed_digitalin_t mbed_digitalin_create1(PinName pin, PinMode mode) {
    return new DigitalIn(pin, mode);
}

int mbed_digitalin_read(mbed_digitalin_t p) {
    MBED_ASSERT(p != nullptr);
    return ((DigitalIn *) p)->read();
}

void mbed_digitalin_mode(mbed_digitalin_t p, PinMode pull) {
    MBED_ASSERT(p != nullptr);
    ((DigitalIn *) p)->mode(pull);
}

int mbed_digitalin_is_connected(mbed_digitalin_t p) {
    MBED_ASSERT(p != nullptr);
    return ((DigitalIn *) p)->is_connected();
}

void mbed_digitalin_free(mbed_digitalin_t p) {
    delete (DigitalIn *) p;
}

}