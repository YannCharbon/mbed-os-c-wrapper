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

#include "MailWrapper.h"
#include "mbed.h"
#include "mbed_assert.h"

extern "C"
{

mbed_mail_t mbed_mail_create(enum mbed_mail_type type) {
    mbed_mail_t new_mail = (mbed_mail_t) new mbed_mail();

    new_mail->type = type;

    switch (type) {
        case MAIL_INT:
            new_mail->mail_ptr = new Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>();
            break;
        case MAIL_DOUBLE:
            new_mail->mail_ptr = new Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>();
            break;
        // Add more types here
    }

    return new_mail;
}

bool mbed_mail_empty(mbed_mail_t p) {
    switch (p->type) {
        case MAIL_INT:
            return static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->empty();
        case MAIL_DOUBLE:
            return static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->empty();
        // Add more types here
        default:
            return false;
    }
}

bool mbed_mail_full(mbed_mail_t p) {
    switch (p->type) {
        case MAIL_INT:
            return static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->full();
        case MAIL_DOUBLE:
            return static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->full();
        // Add more types here
        default:
            return false;
    }
}

void* mbed_mail_try_alloc(mbed_mail_t p) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_alloc();
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_alloc();
        // Add more types here
        default:
            return NULL;
    }
}

void* mbed_mail_try_alloc_for(mbed_mail_t p, uint32_t rel_time_ms) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_alloc_for(std::chrono::duration<uint32_t, milli>(rel_time_ms));
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_alloc_for(std::chrono::duration<uint32_t, milli>(rel_time_ms));
        // Add more types here
        default:
            return NULL;
    }
}

void* mbed_mail_try_alloc_until(mbed_mail_t p, uint64_t abs_time_ms) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_alloc_until(Kernel::Clock::time_point(std::chrono::duration<uint64_t, milli>(abs_time_ms)));
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_alloc_until(Kernel::Clock::time_point(std::chrono::duration<uint64_t, milli>(abs_time_ms)));
        // Add more types here
        default:
            return NULL;
    }
}

void* mbed_mail_try_calloc(mbed_mail_t p) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_calloc();
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_calloc();
        // Add more types here
        default:
            return NULL;
    }
}

void* mbed_mail_try_calloc_for(mbed_mail_t p, uint32_t rel_time_ms) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_calloc_for(std::chrono::duration<uint32_t, milli>(rel_time_ms));
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_calloc_for(std::chrono::duration<uint32_t, milli>(rel_time_ms));
        // Add more types here
        default:
            return NULL;
    }
}

void* mbed_mail_try_calloc_until(mbed_mail_t p, uint64_t abs_time_ms) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_calloc_until(Kernel::Clock::time_point(std::chrono::duration<uint64_t, milli>(abs_time_ms)));
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_calloc_until(Kernel::Clock::time_point(std::chrono::duration<uint64_t, milli>(abs_time_ms)));
        // Add more types here
        default:
            return NULL;
    }
}

osStatus mbed_mail_put(mbed_mail_t p, void* mptr) {
    switch (p->type) {
        case MAIL_INT:
            return static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->put((int *)mptr);
        case MAIL_DOUBLE:
            return static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->put((double *)mptr);
        // Add more types here
        default:
            return osError;
    }
}

void* mbed_mail_try_get(mbed_mail_t p) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_get();
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_get();
        // Add more types here
        default:
            return NULL;
    }
}
void* mbed_mail_try_get_for(mbed_mail_t p, uint32_t rel_time_ms) {
    switch (p->type) {
        case MAIL_INT:
            return (void *)static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_get_for(std::chrono::duration<uint32_t, milli>(rel_time_ms));
        case MAIL_DOUBLE:
            return (void *)static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->try_get_for(std::chrono::duration<uint32_t, milli>(rel_time_ms));
        // Add more types here
        default:
            return NULL;
    }
}
osStatus mbed_mail_free_block(mbed_mail_t p, void* mptr) {
    switch (p->type) {
        case MAIL_INT:
            return static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->free((int *)mptr);
        case MAIL_DOUBLE:
            return static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr)->free((double *)mptr);
        // Add more types here
        default:
            return osError;
    }
}

void mbed_mail_free(mbed_mail_t p) {
    switch (p->type) {
        case MAIL_INT:
            delete static_cast<Mail<int, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr);
            break;
        case MAIL_DOUBLE:
            delete static_cast<Mail<double, MBED_MAIL_DEFAULT_QUEUE_SIZE>*>(p->mail_ptr);
            break;
        // Add more types here
    }

    delete p;
}

}