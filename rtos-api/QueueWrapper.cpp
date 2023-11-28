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

/*
 * NOTE: This is a reimplementation of the C++ Queue to avoid dealing with
 * templates. So this is not exactly a wrapper, but it emulates the C++
 * queue behaviour.
 */

#include "QueueWrapper.h"
#include "mbed.h"
#include "rtos/mbed_rtos_types.h"
#include "rtos/internal/mbed_rtos1_types.h"
#include "rtos/internal/mbed_rtos_storage.h"
#include "rtos/Kernel.h"
#include "platform/mbed_error.h"
#include "platform/NonCopyable.h"
#include "platform/mbed_assert.h"


extern "C" {

mbed_queue_t mbed_queue_create(uint32_t queue_size, uint32_t item_size) {
    mbed_queue_t queue = (mbed_queue_t)malloc(sizeof(struct mbed_queue));
    MBED_ASSERT(queue);
    queue->queue_mem = (char *)malloc(queue_size * (item_size + sizeof(mbed_rtos_storage_message_t)));
    MBED_ASSERT(queue->queue_mem);

    osMessageQueueAttr_t attr;
    memset(&attr, 0, sizeof(attr));
    attr.mq_mem = queue->queue_mem;
    attr.mq_size = queue_size * (item_size + sizeof(mbed_rtos_storage_message_t));
    attr.cb_mem = &queue->obj_mem;
    attr.cb_size = sizeof(queue->obj_mem);

    queue->id = osMessageQueueNew(queue_size, item_size, &attr);
    MBED_ASSERT(queue->id);

    return queue;
}

bool mbed_queue_empty(mbed_queue_t p) {
    MBED_ASSERT(p != NULL);
    return osMessageQueueGetCount(p->id) == 0;
}

bool mbed_queue_full(mbed_queue_t p) {
    MBED_ASSERT(p != NULL);
    return osMessageQueueGetSpace(p->id) == 0;
}

uint32_t mbed_queue_count(mbed_queue_t p) {
    MBED_ASSERT(p != NULL);
    return osMessageQueueGetCount(p->id);
}

bool mbed_queue_try_put(mbed_queue_t p, void *data) {
    MBED_ASSERT(p != NULL);
    return mbed_queue_try_put_for(p, 0, data);
}

bool mbed_queue_try_put1(mbed_queue_t p, void *data, uint8_t prio) {
    MBED_ASSERT(p != NULL);
    return mbed_queue_try_put_for1(p, 0, data, prio);
}

bool mbed_queue_try_put_for(mbed_queue_t p, uint32_t rel_time_ms, void *data) {
    MBED_ASSERT(p != NULL);
    osStatus status = osMessageQueuePut(p->id, &data, 0, rel_time_ms);
    return status == osOK;
}

bool mbed_queue_try_put_for1(mbed_queue_t p, uint32_t rel_time_ms, void *data, uint8_t prio) {
    MBED_ASSERT(p != NULL);
    osStatus status = osMessageQueuePut(p->id, &data, prio, rel_time_ms);
    return status == osOK;
}

bool mbed_queue_try_get(mbed_queue_t p, void *data_out) {
    MBED_ASSERT(p != NULL);
    return mbed_queue_try_get_for(p, 0, data_out);
}

bool mbed_queue_try_get_for(mbed_queue_t p, uint32_t rel_time_ms, void *data_out) {
    MBED_ASSERT(p != NULL);
    osStatus status = osMessageQueueGet(p->id, data_out, NULL, rel_time_ms);
    return status == osOK;
}

void mbed_queue_free(mbed_queue_t p) {
    MBED_ASSERT(p != NULL);

    osMessageQueueDelete(p->id);

    free(p->queue_mem);
    free(p);
}

}