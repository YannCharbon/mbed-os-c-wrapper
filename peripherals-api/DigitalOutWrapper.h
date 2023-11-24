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

#ifndef DIGITALOUT_WRAPPER_H
#define DIGITALOUT_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"
#include "PinNames.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_digitalout_t;

mbed_digitalout_t mbed_digitalout_create(PinName pin);
mbed_digitalout_t mbed_digitalout_create1(PinName pin, int value);
void mbed_digitalout_write(mbed_digitalout_t p, int value);
int mbed_digitalout_read(mbed_digitalout_t p);
int mbed_digitalout_is_connected(mbed_digitalout_t p);
void mbed_digitalout_free(mbed_digitalout_t p);

#ifdef __cplusplus
}
#endif

#endif