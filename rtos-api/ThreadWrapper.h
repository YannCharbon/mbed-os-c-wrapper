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

#ifndef THREAD_WRAPPER_H
#define THREAD_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_thread_t;

/** State of the Thread */
typedef enum {
    Inactive,           /**< NOT USED */
    Ready,              /**< Ready to run */
    Running,            /**< Running */
    WaitingDelay,       /**< Waiting for a delay to occur */
    WaitingJoin,        /**< Waiting for thread to join. Only happens when using RTX directly. */
    WaitingThreadFlag,  /**< Waiting for a thread flag to be set */
    WaitingEventFlag,   /**< Waiting for a event flag to be set */
    WaitingMutex,       /**< Waiting for a mutex event to occur */
    WaitingSemaphore,   /**< Waiting for a semaphore event to occur */
    WaitingMemoryPool,  /**< Waiting for a memory pool */
    WaitingMessageGet,  /**< Waiting for message to arrive */
    WaitingMessagePut,  /**< Waiting for message to be send */
    WaitingInterval,    /**< NOT USED */
    WaitingOr,          /**< NOT USED */
    WaitingAnd,         /**< NOT USED */
    WaitingMailbox,     /**< NOT USED (Mail is implemented as MemoryPool and Queue) */

    /* Not in sync with RTX below here */
    Deleted,            /**< The task has been deleted or not started */
} mbed_thread_state_t;

mbed_thread_t mbed_thread_create();
mbed_thread_t mbed_thread_create1(osPriority priority);
mbed_thread_t mbed_thread_create2(osPriority priority, uint32_t stack_size);
mbed_thread_t mbed_thread_create3(osPriority priority, uint32_t stack_size, unsigned char *stack_mem);
mbed_thread_t mbed_thread_create4(osPriority priority, uint32_t stack_size, unsigned char *stack_mem, const char *name);
mbed_thread_t mbed_thread_create5(uint32_t tz_module);
mbed_thread_t mbed_thread_create6(uint32_t tz_module, osPriority priority);
mbed_thread_t mbed_thread_create7(uint32_t tz_module, osPriority priority, uint32_t stack_size);
mbed_thread_t mbed_thread_create8(uint32_t tz_module, osPriority priority, uint32_t stack_size, unsigned char *stack_mem);
mbed_thread_t mbed_thread_create9(uint32_t tz_module, osPriority priority, uint32_t stack_size, unsigned char *stack_mem, const char *name);
osStatus mbed_thread_start(mbed_thread_t p, void (*task)(const void*), void* args);
osStatus mbed_thread_join(mbed_thread_t p);
osStatus mbed_thread_terminate(mbed_thread_t p);
osStatus mbed_thread_set_priority(mbed_thread_t p, osPriority priority);
osPriority mbed_thread_get_priority(mbed_thread_t p);
uint32_t mbed_thread_flags_set(mbed_thread_t p, uint32_t flags);
mbed_thread_state_t mbed_thread_get_state(mbed_thread_t p);
uint32_t mbed_thread_stack_size(mbed_thread_t p);
uint32_t mbed_thread_free_stack(mbed_thread_t p);
uint32_t mbed_thread_used_stack(mbed_thread_t p);
uint32_t mbed_thread_max_stack(mbed_thread_t p);
const char *mbed_thread_get_name(mbed_thread_t p);
osThreadId_t mbed_thread_get_id(mbed_thread_t p);
void mbed_thread_free(mbed_thread_t p);

#ifdef __cplusplus
}
#endif

#endif



