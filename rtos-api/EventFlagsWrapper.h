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

#ifndef EVENTFLAGS_WRAPPER_H
#define EVENTFLAGS_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_eventflags_t;

mbed_eventflags_t mbed_eventflags_create();
mbed_eventflags_t mbed_eventflags_create1(const char *name);
uint32_t mbed_eventflags_set(mbed_eventflags_t p, uint32_t flags);
uint32_t mbed_eventflags_clear(mbed_eventflags_t p);
uint32_t mbed_eventflags_clear1(mbed_eventflags_t p, uint32_t flags);
uint32_t mbed_eventflags_get(mbed_eventflags_t p);
uint32_t mbed_eventflags_wait_all_for(mbed_eventflags_t p, uint32_t flags, uint32_t rel_time_ms);
uint32_t mbed_eventflags_wait_all_for1(mbed_eventflags_t p, uint32_t flags, uint32_t rel_time_ms, bool clear);
uint32_t mbed_eventflags_wait_all_until(mbed_eventflags_t p, uint32_t flags, uint64_t abs_time_ms);
uint32_t mbed_eventflags_wait_all_until1(mbed_eventflags_t p, uint32_t flags, uint64_t abs_time_ms, bool clear);
uint32_t mbed_eventflags_wait_any_for(mbed_eventflags_t p, uint32_t flags, uint32_t rel_time_ms);
uint32_t mbed_eventflags_wait_any_for1(mbed_eventflags_t p, uint32_t flags, uint32_t rel_time_ms, bool clear);
uint32_t mbed_eventflags_wait_any_until(mbed_eventflags_t p, uint32_t flags, uint64_t abs_time_ms);
uint32_t mbed_eventflags_wait_any_until1(mbed_eventflags_t p, uint32_t flags, uint64_t abs_time_ms, bool clear);
void mbed_eventflags_free(mbed_eventflags_t p);

#ifdef __cplusplus
}
#endif

#endif