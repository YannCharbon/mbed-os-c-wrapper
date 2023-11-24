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

#ifndef SEMAPHORE_WRAPPER_H
#define SEMAPHORE_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_semaphore_t;

mbed_semaphore_t mbed_semaphore_create();
mbed_semaphore_t mbed_semaphore_create1(int32_t count);
mbed_semaphore_t mbed_semaphore_create2(int32_t count, uint16_t max_count);
void mbed_semaphore_acquire(mbed_semaphore_t p);
bool mbed_semaphore_try_acquire_for(mbed_semaphore_t p, uint32_t rel_time_ms);
bool mbed_semaphore_try_acquire_until(mbed_semaphore_t p, uint64_t abs_time_ms);
osStatus mbed_semaphore_release(mbed_semaphore_t p);
void mbed_semaphore_free(mbed_semaphore_t p);

#ifdef __cplusplus
}
#endif

#endif