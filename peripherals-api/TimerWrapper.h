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

#ifndef TIMER_WRAPPER_H
#define TIMER_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_timer_t;

mbed_timer_t mbed_timer_create();
void mbed_timer_start(mbed_timer_t p);
void mbed_timer_stop(mbed_timer_t p);
void mbed_timer_reset(mbed_timer_t p);
uint64_t mbed_timer_elapsed_time_us(mbed_timer_t p);
void mbed_timer_free(mbed_timer_t p);

#ifdef __cplusplus
}
#endif

#endif