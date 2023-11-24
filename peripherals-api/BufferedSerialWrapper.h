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

#ifndef BUFFEREDSERIAL_WRAPPER_H
#define BUFFEREDSERIAL_WRAPPER_H

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

typedef void* mbed_bufferedserial_t;

typedef enum  {
    None = 0,
    Odd,
    Even,
    Forced1,
    Forced0
} mbed_bufferedserial_parity_t;

typedef enum {
    Disabled = 0,
    RTS,
    CTS,
    RTSCTS
} mbed_bufferedserial_flow_t;

mbed_bufferedserial_t mbed_bufferedserial_create(PinName tx, PinName rx);
mbed_bufferedserial_t mbed_bufferedserial_create1(PinName tx, PinName rx, int baud);
mbed_bufferedserial_t mbed_bufferedserial_create2(const serial_pinmap_t *static_pinmap);
mbed_bufferedserial_t mbed_bufferedserial_create3(const serial_pinmap_t *static_pinmap, int baud);
short mbed_bufferedserial_poll(mbed_bufferedserial_t p, short events);
ssize_t mbed_bufferedserial_write(mbed_bufferedserial_t p, const void *buffer, size_t length);
ssize_t mbed_bufferedserial_read(mbed_bufferedserial_t p, void *buffer, size_t length);
int mbed_bufferedserial_close(mbed_bufferedserial_t p);
int mbed_bufferedserial_isatty(mbed_bufferedserial_t p);
off_t mbed_bufferedserial_seek(mbed_bufferedserial_t p, off_t offset, int whence);
int mbed_bufferedserial_sync(mbed_bufferedserial_t p);
int mbed_bufferedserial_set_blocking(mbed_bufferedserial_t p, bool blocking);
bool mbed_bufferedserial_is_blocking(mbed_bufferedserial_t p);
int mbed_bufferedserial_enable_input(mbed_bufferedserial_t p, bool enabled);
int mbed_bufferedserial_enable_output(mbed_bufferedserial_t p, bool enabled);
void mbed_bufferedserial_sigio(mbed_bufferedserial_t p, void (*func)(void));
void mbed_bufferedserial_set_data_carrier_detect(mbed_bufferedserial_t p, PinName dcd_pin);
void mbed_bufferedserial_set_data_carrier_detect1(mbed_bufferedserial_t p, PinName dcd_pin, bool active_high);
void mbed_bufferedserial_set_baud(mbed_bufferedserial_t p, int baud);
void mbed_bufferedserial_set_format(mbed_bufferedserial_t p);
void mbed_bufferedserial_set_format1(mbed_bufferedserial_t p, int bits);
void mbed_bufferedserial_set_format2(mbed_bufferedserial_t p, int bits, mbed_bufferedserial_parity_t parity);
void mbed_bufferedserial_set_format3(mbed_bufferedserial_t p, int bits, mbed_bufferedserial_parity_t parity, int stop_bits);
#if DEVICE_SERIAL_FC
void mbed_bufferedserial_set_flow_control(mbed_bufferedserial_t p, mbed_bufferedserial_flow_t type);
void mbed_bufferedserial_set_flow_control1(mbed_bufferedserial_t p, mbed_bufferedserial_flow_t type, PinName flow1);
void mbed_bufferedserial_set_flow_control2(mbed_bufferedserial_t p, mbed_bufferedserial_flow_t type, PinName flow1, PinName flow2);
#endif
void mbed_bufferedserial_free(mbed_bufferedserial_t p);

#ifdef __cplusplus
}
#endif

#endif