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

#include "TickerWrapper.h"
#include "mbed.h"

extern "C"
{
mbed_ticker_t mbed_ticker_create() {
    return new Ticker();
}

void mbed_ticker_attach(mbed_ticker_t p, void (*func)(void), uint32_t interval_us) {
    ((Ticker *) p)->attach(func, std::chrono::microseconds{interval_us});
}

void mbed_ticker_detach(mbed_ticker_t p) {
    ((Ticker *) p)->detach();
}

void mbed_ticker_free(mbed_ticker_t p) {
    MBED_ASSERT(p != nullptr);
    delete (Ticker *) p;
}

}