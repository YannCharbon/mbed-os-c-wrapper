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

#include "TimerWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_timer_t mbed_timer_create() {
    return new Timer();
}

void mbed_timer_start(mbed_timer_t p) {
    MBED_ASSERT(p != nullptr);
    ((Timer *) p)->start();
}

void mbed_timer_stop(mbed_timer_t p) {
    MBED_ASSERT(p != nullptr);
    ((Timer *) p)->stop();
}

void mbed_timer_reset(mbed_timer_t p) {
    MBED_ASSERT(p != nullptr);
    ((Timer *) p)->reset();
}

uint64_t mbed_timer_elapsed_time_us(mbed_timer_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Timer *) p)->elapsed_time().count();
}

void mbed_timer_free(mbed_timer_t p) {
    MBED_ASSERT(p != nullptr);
    delete (Timer *) p;
}

}