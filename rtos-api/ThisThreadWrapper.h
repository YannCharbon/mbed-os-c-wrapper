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

#ifndef THISTHREAD_WRAPPER_H
#define THISTHREAD_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t mbed_thisthread_flags_clear(uint32_t flags);
uint32_t mbed_thisthread_flags_get();
uint32_t mbed_thisthread_flags_wait_all(uint32_t flags);
uint32_t mbed_thisthread_flags_wait_all1(uint32_t flags, bool clear);
uint32_t mbed_thisthread_flags_wait_any(uint32_t flags);
uint32_t mbed_thisthread_flags_wait_any1(uint32_t flags, bool clear);
uint32_t mbed_thisthread_flags_wait_all_for(uint32_t flags, uint32_t rel_time_ms);
uint32_t mbed_thisthread_flags_wait_all_for1(uint32_t flags, uint32_t rel_time_ms, bool clear);
uint32_t mbed_thisthread_flags_wait_all_until(uint32_t flags, uint64_t abs_time_ms);
uint32_t mbed_thisthread_flags_wait_all_until1(uint32_t flags, uint64_t abs_time_ms, bool clear);
uint32_t mbed_thisthread_flags_wait_any_for(uint32_t flags, uint32_t rel_time_ms);
uint32_t mbed_thisthread_flags_wait_any_for1(uint32_t flags, uint32_t rel_time_ms, bool clear);
uint32_t mbed_thisthread_flags_wait_any_until(uint32_t flags, uint64_t abs_time_ms);
uint32_t mbed_thisthread_flags_wait_any_until1(uint32_t flags, uint64_t abs_time_ms, bool clear);
void mbed_thisthread_sleep_for(uint32_t rel_time_ms);
void mbed_thisthread_sleep_until(uint64_t abs_time_ms);
void mbed_thisthread_yield();
osThreadId_t mbed_thisthread_get_id();
const char *mbed_thisthread_get_name();

#ifdef __cplusplus
}
#endif

#endif