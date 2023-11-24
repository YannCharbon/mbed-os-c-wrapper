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

#include "KernelWrapper.h"
#include "mbed.h"

using namespace std::chrono;

extern "C"
{

uint64_t mbed_kernel_now_us() {
    return time_point_cast<microseconds>(Kernel::Clock::now()).time_since_epoch().count();
}

void mbed_kernel_lock() {
    Kernel::Clock::lock();
}

void mbed_kernel_unlock() {
    Kernel::Clock::unlock();
}

void mbed_kernel_attach_idle_hook(void (*fptr)(void)) {
    Kernel::attach_idle_hook(fptr);
}

void mbed_kernel_attach_thread_terminate_hook(void (*fptr)(osThreadId_t id)) {
    Kernel::attach_thread_terminate_hook(fptr);
}


}