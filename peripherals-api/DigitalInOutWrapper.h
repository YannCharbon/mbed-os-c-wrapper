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

#ifndef DIGITALINOUT_WRAPPER_H
#define DIGITALINOUT_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"
#include "PinNames.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_digitalinout_t;

mbed_digitalinout_t mbed_digitalinout_create(PinName pin);
mbed_digitalinout_t mbed_digitalinout_create1(PinName pin, PinDirection direction, PinMode mode, int value);
void mbed_digitalinout_write(mbed_digitalinout_t p, int value);
int mbed_digitalinout_read(mbed_digitalinout_t p);
void mbed_digitalinout_output(mbed_digitalinout_t p);
void mbed_digitalinout_input(mbed_digitalinout_t p);
void mbed_digitalinout_mode(mbed_digitalinout_t p, PinMode pull);
int mbed_digitalinout_is_connected(mbed_digitalinout_t p);
void mbed_digitalinout_free(mbed_digitalinout_t p);

#ifdef __cplusplus
}
#endif

#endif