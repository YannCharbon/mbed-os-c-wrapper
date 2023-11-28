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

#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"
#include "cmsis_os2.h"
#include "mbed_rtx_storage.h"

#ifdef __cplusplus
extern "C" {
#endif

struct mbed_queue {
    osMessageQueueId_t id;
    mbed_rtos_storage_msg_queue_t obj_mem;
    char *queue_mem;
};

typedef mbed_queue* mbed_queue_t;

mbed_queue_t mbed_queue_create(uint32_t queue_size, uint32_t item_size);
bool mbed_queue_empty(mbed_queue_t p);
bool mbed_queue_full(mbed_queue_t p);
uint32_t mbed_queue_count(mbed_queue_t p);
bool mbed_queue_try_put(mbed_queue_t p, void *data);
bool mbed_queue_try_put1(mbed_queue_t p, void *data, uint8_t prio);
bool mbed_queue_try_put_for(mbed_queue_t p, uint32_t rel_time_ms, void *data);
bool mbed_queue_try_put_for1(mbed_queue_t p, uint32_t rel_time_ms, void *data, uint8_t prio);
// data_out must be "void **" (see queue.h for more detail)
bool mbed_queue_try_get(mbed_queue_t p, void *data_out);
// data_out must be "void **" (see queue.h for more detail)
bool mbed_queue_try_get_for(mbed_queue_t p, uint32_t rel_time_ms, void *data_out);
void mbed_queue_free(mbed_queue_t p);

#ifdef __cplusplus
}
#endif

#endif