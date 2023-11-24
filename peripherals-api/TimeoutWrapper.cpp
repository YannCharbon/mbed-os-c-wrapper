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

#include "TimeoutWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_timeout_t mbed_timeout_create() {
    return new Timeout();
}

uint64_t mbed_timeout_scheduled_time_us(mbed_timeout_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Timeout *) p)->scheduled_time().time_since_epoch().count();
}

uint64_t mbed_timeout_remaining_time(mbed_timeout_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Timeout *) p)->remaining_time().count();
}

void mbed_timeout_attach(mbed_timeout_t p, void (*cb)(void), uint64_t t) {
    MBED_ASSERT(p != nullptr);
    ((Timeout *) p)->attach(cb, std::chrono::microseconds{t});
}

void mbed_timeout_detach(mbed_timeout_t p) {
    MBED_ASSERT(p != nullptr);
    ((Timeout *) p)->detach();
}

void mbed_timeout_free(mbed_timeout_t p) {
    MBED_ASSERT(p != nullptr);
    delete (Timeout *) p;
}

}