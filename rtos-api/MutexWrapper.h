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

#ifndef MUTEX_WRAPPER_H
#define MUTEX_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_mutex_t;

mbed_mutex_t mbed_mutex_create();
mbed_mutex_t mbed_mutex_create1(const char *name);
void mbed_mutex_lock(mbed_mutex_t p);
bool mbed_mutex_trylock(mbed_mutex_t p);
bool mbed_mutex_trylock_for(mbed_mutex_t p, uint32_t rel_time_ms);
bool mbed_mutex_trylock_until(mbed_mutex_t p, uint64_t abs_time_ms);
void mbed_mutex_unlock(mbed_mutex_t p);
osThreadId_t mbed_mutex_get_owner(mbed_mutex_t p);
void mbed_mutex_free(mbed_mutex_t p);

#ifdef __cplusplus
}
#endif

#endif