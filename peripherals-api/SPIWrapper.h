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

#ifndef SPI_WRAPPER_H
#define SPI_WRAPPER_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"
#include "PinNames.h"
#include "spi_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* mbed_spi_t;

mbed_spi_t mbed_spi_create(PinName mosi, PinName miso, PinName sclk);
mbed_spi_t mbed_spi_create1(PinName mosi, PinName miso, PinName sclk, PinName ssel, bool use_gpio_for_ssel);
mbed_spi_t mbed_spi_create2(const spi_pinmap_t *static_pinmap);
mbed_spi_t mbed_spi_create3(const spi_pinmap_t *static_pinmap, PinName ssel);
void mbed_spi_format(mbed_spi_t p, int bits);
void mbed_spi_format1(mbed_spi_t p, int bits, int mode);
void mbed_spi_frequency(mbed_spi_t p, int hz);
int mbed_spi_write(mbed_spi_t p, int value);
int mbed_spi_write1(mbed_spi_t p, const char *tx_buffer, int tx_length, char *rx_buffer, int rx_length);
void mbed_spi_lock(mbed_spi_t p);
void mbed_spi_unlock(mbed_spi_t p);
void mbed_spi_select(mbed_spi_t p);
void mbed_spi_deselect(mbed_spi_t p);
void mbed_spi_set_default_write_value(mbed_spi_t p, char data);
int mbed_spi_transfer(mbed_spi_t p, const uint8_t *tx_buffer, int tx_length, uint8_t *rx_buffer, int rx_length, void (*callback)(int));
int mbed_spi_transfer1(mbed_spi_t p, const uint8_t *tx_buffer, int tx_length, uint8_t *rx_buffer, int rx_length, void (*callback)(int), int event);
void mbed_spi_abort_transfer(mbed_spi_t p);
void mbed_spi_clear_transfer_buffer(mbed_spi_t p);
void mbed_spi_abort_all_transfers(mbed_spi_t p);
int mbed_spi_set_dma_usage(mbed_spi_t p, DMAUsage usage);
void mbed_spi_free(mbed_spi_t p);

#ifdef __cplusplus
}
#endif

#endif