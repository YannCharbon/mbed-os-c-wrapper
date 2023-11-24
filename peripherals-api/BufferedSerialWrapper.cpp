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

#include "BufferedSerialWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_bufferedserial_t mbed_bufferedserial_create(PinName tx, PinName rx) {
    return new BufferedSerial(tx, rx);
}

mbed_bufferedserial_t mbed_bufferedserial_create1(PinName tx, PinName rx, int baud) {
    return new BufferedSerial(tx, rx, baud);
}

mbed_bufferedserial_t mbed_bufferedserial_create2(const serial_pinmap_t *static_pinmap) {
    return new BufferedSerial(*static_pinmap);
}

mbed_bufferedserial_t mbed_bufferedserial_create3(const serial_pinmap_t *static_pinmap, int baud) {
    return new BufferedSerial(*static_pinmap, baud);
}

short mbed_bufferedserial_poll(mbed_bufferedserial_t p, short events) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->poll(events);
}

ssize_t mbed_bufferedserial_write(mbed_bufferedserial_t p, const void *buffer, size_t length) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->write(buffer, length);
}

ssize_t mbed_bufferedserial_read(mbed_bufferedserial_t p, void *buffer, size_t length) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->read(buffer, length);
}

int mbed_bufferedserial_close(mbed_bufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->close();
}

int mbed_bufferedserial_isatty(mbed_bufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->isatty();
}

off_t mbed_bufferedserial_seek(mbed_bufferedserial_t p, off_t offset, int whence) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->seek(offset, whence);
}

int mbed_bufferedserial_sync(mbed_bufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->sync();
}

int mbed_bufferedserial_set_blocking(mbed_bufferedserial_t p, bool blocking) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->set_blocking(blocking);
}

bool mbed_bufferedserial_is_blocking(mbed_bufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->is_blocking();
}

int mbed_bufferedserial_enable_input(mbed_bufferedserial_t p, bool enabled) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->enable_input(enabled);
}

int mbed_bufferedserial_enable_output(mbed_bufferedserial_t p, bool enabled) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->enable_output(enabled);
}

void mbed_bufferedserial_sigio(mbed_bufferedserial_t p, void (*func)(void)) {
    MBED_ASSERT(p != nullptr);
    return ((BufferedSerial *) p)->sigio(func);
}

void mbed_bufferedserial_set_data_carrier_detect(mbed_bufferedserial_t p, PinName dcd_pin) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_data_carrier_detect(dcd_pin);
}

void mbed_bufferedserial_set_data_carrier_detect1(mbed_bufferedserial_t p, PinName dcd_pin, bool active_high) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_data_carrier_detect(dcd_pin, active_high);
}

void mbed_bufferedserial_set_baud(mbed_bufferedserial_t p, int baud) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_baud(baud);
}

void mbed_bufferedserial_set_format(mbed_bufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_format();
}

void mbed_bufferedserial_set_format1(mbed_bufferedserial_t p, int bits) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_format(bits);
}

void mbed_bufferedserial_set_format2(mbed_bufferedserial_t p, int bits, mbed_bufferedserial_parity_t parity) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_format(bits, (SerialBase::Parity)parity);
}

void mbed_bufferedserial_set_format3(mbed_bufferedserial_t p, int bits, mbed_bufferedserial_parity_t parity, int stop_bits) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_format(bits, (SerialBase::Parity)parity, stop_bits);
}

#if DEVICE_SERIAL_FC
void mbed_bufferedserial_set_flow_control(mbed_bufferedserial_t p, mbed_bufferedserial_flow_t type) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_flow_control((SerialBase::Flow)type);
}

void mbed_bufferedserial_set_flow_control1(mbed_bufferedserial_t p, mbed_bufferedserial_flow_t type, PinName flow1) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_flow_control((SerialBase::Flow)type, flow1);
}

void mbed_bufferedserial_set_flow_control2(mbed_bufferedserial_t p, mbed_bufferedserial_flow_t type, PinName flow1, PinName flow2) {
    MBED_ASSERT(p != nullptr);
    ((BufferedSerial *) p)->set_flow_control((SerialBase::Flow)type, flow1, flow2);
}
#endif

void mbed_bufferedserial_free(mbed_bufferedserial_t p) {
    MBED_ASSERT(p != nullptr);
    delete (BufferedSerial *) p;
}

}