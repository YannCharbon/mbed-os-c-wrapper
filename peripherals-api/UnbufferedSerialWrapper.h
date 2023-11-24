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

#ifndef UNBUFFEREDSERIAL_WRAPPER_H
#define UNBUFFEREDSERIAL_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"
#include "PinNames.h"
#include "serial_api.h"
#include "platform/platform.h"
#include "drivers/SerialBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_unbufferedserial_t;

typedef enum  {
    None = 0,
    Odd,
    Even,
    Forced1,
    Forced0
} mbed_unbufferedserial_parity_t;

typedef enum {
    Disabled = 0,
    RTS,
    CTS,
    RTSCTS
} mbed_unbufferedserial_flow_t;

mbed_unbufferedserial_t mbed_unbufferedserial_create(PinName tx, PinName rx);
mbed_unbufferedserial_t mbed_unbufferedserial_create1(PinName tx, PinName rx, int baud);
mbed_unbufferedserial_t mbed_unbufferedserial_create2(const serial_pinmap_t *static_pinmap);
mbed_unbufferedserial_t mbed_unbufferedserial_create3(const serial_pinmap_t *static_pinmap, int baud);
ssize_t mbed_unbufferedserial_write(mbed_unbufferedserial_t p, const void *buffer, size_t length);
ssize_t mbed_unbufferedserial_read(mbed_unbufferedserial_t p, void *buffer, size_t length);
off_t mbed_unbufferedserial_seek(mbed_unbufferedserial_t p, off_t offset, int whence);
off_t mbed_unbufferedserial_size(mbed_unbufferedserial_t p);
int mbed_unbufferedserial_isatty(mbed_unbufferedserial_t p);
int mbed_unbufferedserial_close(mbed_unbufferedserial_t p);
int mbed_unbufferedserial_enable_input(mbed_unbufferedserial_t p, bool enabled);
int mbed_unbufferedserial_enable_output(mbed_unbufferedserial_t p, bool enabled);
short mbed_unbufferedserial_poll(mbed_unbufferedserial_t p, short events);
#if DEVICE_SERIAL_FC
void mbed_unbufferedserial_set_flow_control(mbed_unbufferedserial_t p, mbed_unbufferedserial_flow_t type);
void mbed_unbufferedserial_set_flow_control1(mbed_unbufferedserial_t p, mbed_unbufferedserial_flow_t type, PinName flow1);
void mbed_unbufferedserial_set_flow_control2(mbed_unbufferedserial_t p, mbed_unbufferedserial_flow_t type, PinName flow1, PinName flow2);
#endif
void mbed_unbufferedserial_free(mbed_unbufferedserial_t p);

#ifdef __cplusplus
}
#endif

#endif