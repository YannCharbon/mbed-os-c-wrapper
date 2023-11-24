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

#include "ThreadWrapper.h"
#include "mbed.h"

extern "C"
{
mbed_thread_t mbed_thread_create() {
    return new Thread();
}

mbed_thread_t mbed_thread_create1(osPriority priority) {
    return new Thread(priority);
}

mbed_thread_t mbed_thread_create2(osPriority priority, uint32_t stack_size) {
    return new Thread(priority, stack_size);
}

mbed_thread_t mbed_thread_create3(osPriority priority, uint32_t stack_size, unsigned char *stack_mem) {
    return new Thread(priority, stack_size, stack_mem);
}

mbed_thread_t mbed_thread_create4(osPriority priority, uint32_t stack_size, unsigned char *stack_mem, const char *name) {
    return new Thread(priority, stack_size, stack_mem, name);
}

mbed_thread_t mbed_thread_create5(uint32_t tz_module) {
    return new Thread(tz_module);
}

mbed_thread_t mbed_thread_create6(uint32_t tz_module, osPriority priority) {
    return new Thread(tz_module, priority);
}

mbed_thread_t mbed_thread_create7(uint32_t tz_module, osPriority priority, uint32_t stack_size) {
    return new Thread(tz_module, priority, stack_size);
}

mbed_thread_t mbed_thread_create8(uint32_t tz_module, osPriority priority, uint32_t stack_size, unsigned char *stack_mem) {
    return new Thread(tz_module, priority, stack_size, stack_mem);
}

mbed_thread_t mbed_thread_create9(uint32_t tz_module, osPriority priority, uint32_t stack_size, unsigned char *stack_mem, const char *name) {
    return new Thread(tz_module, priority, stack_size, stack_mem, name);
}

osStatus mbed_thread_start(mbed_thread_t p, void (*task)(const void*), void* args) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->start(callback(task, args));
}

osStatus mbed_thread_join(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->join();
}

osStatus mbed_thread_terminate(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->terminate();
}

osStatus mbed_thread_set_priority(mbed_thread_t p, osPriority priority) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->set_priority(priority);
}

osPriority mbed_thread_get_priority(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->get_priority();
}

uint32_t mbed_thread_flags_set(mbed_thread_t p, uint32_t flags) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->flags_set(flags);
}

mbed_thread_state_t mbed_thread_get_state(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return (mbed_thread_state_t)((Thread *) p)->get_state();
}

uint32_t mbed_thread_stack_size(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->stack_size();
}

uint32_t mbed_thread_free_stack(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->free_stack();
}

uint32_t mbed_thread_used_stack(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->used_stack();
}

uint32_t mbed_thread_max_stack(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->max_stack();
}

const char *mbed_thread_get_name(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->get_name();
}

osThreadId_t mbed_thread_get_id(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    return ((Thread *) p)->get_id();
}

void mbed_thread_free(mbed_thread_t p) {
    MBED_ASSERT(p != nullptr);
    delete (Thread *) p;
}

}