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

#include "SemaphoreWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_semaphore_t mbed_semaphore_create(){
    return new Semaphore();
}

mbed_semaphore_t mbed_semaphore_create1(int32_t count){
    return new Semaphore(count);
}

mbed_semaphore_t mbed_semaphore_create2(int32_t count, uint16_t max_count){
    return new Semaphore(count, max_count);
}

void mbed_semaphore_acquire(mbed_semaphore_t p){
    MBED_ASSERT(p != nullptr);
    ((Semaphore *) p)->acquire();
}

bool mbed_semaphore_try_acquire(mbed_semaphore_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Semaphore *) p)->try_acquire();
}

bool mbed_semaphore_try_acquire_for(mbed_semaphore_t p, uint32_t rel_time_ms) {
    MBED_ASSERT(p != nullptr);
    return ((Semaphore *) p)->try_acquire_for(std::chrono::duration<uint32_t, milli>(rel_time_ms));
}

bool mbed_semaphore_try_acquire_until(mbed_semaphore_t p, uint64_t abs_time_ms) {
    MBED_ASSERT(p != nullptr);
    return ((Semaphore *) p)->try_acquire_until(Kernel::Clock::time_point(std::chrono::duration<uint64_t, milli>(abs_time_ms)));
}

osStatus mbed_semaphore_release(mbed_semaphore_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Semaphore *) p)->release();
}

void mbed_semaphore_free(mbed_semaphore_t p){
    MBED_ASSERT(p != nullptr);
    delete (Semaphore *) p;
}

}