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

#include "UnbufferedSerialWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_unbufferedserial_t mbed_unbufferedserial_create(PinName tx, PinName rx) {
    return new UnbufferedSerial(tx, rx);
}

mbed_unbufferedserial_t mbed_unbufferedserial_create1(PinName tx, PinName rx, int baud) {
    return new UnbufferedSerial(tx, rx, baud);
}

mbed_unbufferedserial_t mbed_unbufferedserial_create2(const serial_pinmap_t *static_pinmap) {
    return new UnbufferedSerial(*static_pinmap);
}

mbed_unbufferedserial_t mbed_unbufferedserial_create3(const serial_pinmap_t *static_pinmap, int baud) {
    return new UnbufferedSerial(*static_pinmap, baud);
}

ssize_t mbed_unbufferedserial_write(mbed_unbufferedserial_t p, const void *buffer, size_t length) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->write(buffer, length);
}

ssize_t mbed_unbufferedserial_read(mbed_unbufferedserial_t p, void *buffer, size_t length) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->read(buffer, length);
}

off_t mbed_unbufferedserial_seek(mbed_unbufferedserial_t p, off_t offset, int whence) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->seek(offset, whence);
}

off_t mbed_unbufferedserial_size(mbed_unbufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->size();
}

int mbed_unbufferedserial_isatty(mbed_unbufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->isatty();
}

int mbed_unbufferedserial_close(mbed_unbufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->close();
}

int mbed_unbufferedserial_enable_input(mbed_unbufferedserial_t p, bool enabled) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->enable_input(enabled);
}

int mbed_unbufferedserial_enable_output(mbed_unbufferedserial_t p, bool enabled) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->enable_output(enabled);
}

short mbed_unbufferedserial_poll(mbed_unbufferedserial_t p, short events) {
    MBED_ASSERT(p != nullptr);
    return ((UnbufferedSerial *) p)->poll(events);
}

#if DEVICE_SERIAL_FC
void mbed_unbufferedserial_set_flow_control(mbed_unbufferedserial_t p, mbed_unbufferedserial_flow_t type) {
    MBED_ASSERT(p != nullptr);
    ((UnbufferedSerial *) p)->set_flow_control((SerialBase::Flow)type);
}

void mbed_unbufferedserial_set_flow_control1(mbed_unbufferedserial_t p, mbed_unbufferedserial_flow_t type, PinName flow1) {
    MBED_ASSERT(p != nullptr);
    ((UnbufferedSerial *) p)->set_flow_control((SerialBase::Flow)type, flow1);
}

void mbed_unbufferedserial_set_flow_control2(mbed_unbufferedserial_t p, mbed_unbufferedserial_flow_t type, PinName flow1, PinName flow2) {
    MBED_ASSERT(p != nullptr);
    ((UnbufferedSerial *) p)->set_flow_control((SerialBase::Flow)type, flow1, flow2);
}
#endif

void mbed_unbufferedserial_free(mbed_unbufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    delete (UnbufferedSerial *) p;
}

}