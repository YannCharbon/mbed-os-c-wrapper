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

#include "DigitalOutWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_digitalout_t mbed_digitalout_create(PinName pin) {
    return new DigitalOut(pin);
}

mbed_digitalout_t mbed_digitalout_create1(PinName pin, int value) {
    return new DigitalOut(pin, value);
}

void mbed_digitalout_write(mbed_digitalout_t p, int value) {
    MBED_ASSERT(p != nullptr);
    ((DigitalOut *) p)->write(value);
}

int mbed_digitalout_read(mbed_digitalout_t p) {
    MBED_ASSERT(p != nullptr);
    return ((DigitalOut *) p)->read();
}
int mbed_digitalout_is_connected(mbed_digitalout_t p) {
    MBED_ASSERT(p != nullptr);
    return ((DigitalOut *) p)->is_connected();
}

void mbed_digitalout_free(mbed_digitalout_t p) {
    MBED_ASSERT(p != nullptr);
    delete (DigitalOut *) p;
}

}