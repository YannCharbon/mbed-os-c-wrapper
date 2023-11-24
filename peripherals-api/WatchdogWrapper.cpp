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

#include "WatchdogWrapper.h"
#include "mbed.h"
#include "Watchdog.h"

extern "C"
{

bool mbed_watchdog_start() {
    return Watchdog::get_instance().start();
}

bool mbed_watchdog_start1(uint32_t timeout_ms) {
    return Watchdog::get_instance().start(timeout_ms);
}

bool mbed_watchdog_stop() {
    return Watchdog::get_instance().stop();
}

uint32_t mbed_watchdog_get_timeout() {
    return Watchdog::get_instance().get_timeout();
}

uint32_t mbed_watchdog_get_max_timeout() {
    return Watchdog::get_instance().get_max_timeout();
}

bool mbed_watchdog_is_running() {
    return Watchdog::get_instance().is_running();
}

void mbed_watchdog_kick() {
    Watchdog::get_instance().kick();
}

}