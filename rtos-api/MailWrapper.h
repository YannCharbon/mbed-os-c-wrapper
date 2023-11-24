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

#ifndef MAIL_WRAPPER_H
#define MAIL_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MBED_MAIL_DEFAULT_QUEUE_SIZE    16

enum mbed_mail_type {
    MAIL_INT,
    MAIL_DOUBLE,
    // Add types here
};

struct mbed_mail {
    enum mbed_mail_type type;
    void* mail_ptr;
};

typedef struct mbed_mail* mbed_mail_t;

mbed_mail_t mbed_mail_create(enum mbed_mail_type type);
bool mbed_mail_empty(mbed_mail_t p);
bool mbed_mail_full(mbed_mail_t p);
void* mbed_mail_try_alloc(mbed_mail_t p);
void* mbed_mail_try_alloc_for(mbed_mail_t p, uint32_t rel_time_ms);
void* mbed_mail_try_alloc_until(mbed_mail_t p, uint64_t abs_time_ms);
void* mbed_mail_try_calloc(mbed_mail_t p);
void* mbed_mail_try_calloc_for(mbed_mail_t p, uint32_t rel_time_ms);
void* mbed_mail_try_calloc_until(mbed_mail_t p, uint64_t abs_time_ms);
osStatus mbed_mail_put(mbed_mail_t p, void* mptr);
void* mbed_mail_try_get(mbed_mail_t p);
void* mbed_mail_try_get_for(mbed_mail_t p, uint32_t rel_time_ms);
osStatus mbed_mail_free_block(mbed_mail_t p, void* mptr);
void mbed_mail_free(mbed_mail_t p);

#ifdef __cplusplus
}
#endif

#endif