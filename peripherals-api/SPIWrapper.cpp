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

#include "SPIWrapper.h"
#include "mbed.h"

extern "C"
{

mbed_spi_t mbed_spi_create(PinName mosi, PinName miso, PinName sclk) {
    return new SPI(mosi, miso, sclk, NC);
}

mbed_spi_t mbed_spi_create1(PinName mosi, PinName miso, PinName sclk, PinName ssel, bool use_gpio_for_ssel) {
    if (use_gpio_for_ssel) {
        return new SPI(mosi, miso, sclk, ssel);
    } else {
        return new SPI(mosi, miso, sclk, ssel, use_gpio_ssel);
    }
}

mbed_spi_t mbed_spi_create2(const spi_pinmap_t *static_pinmap) {
    return new SPI(*static_pinmap);
}

mbed_spi_t mbed_spi_create3(const spi_pinmap_t *static_pinmap, PinName ssel) {
    return new SPI(*static_pinmap, ssel);
}

void mbed_spi_format(mbed_spi_t p, int bits) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->format(bits);
}

void mbed_spi_format1(mbed_spi_t p, int bits, int mode) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->format(bits, mode);
}

void mbed_spi_frequency(mbed_spi_t p, int hz) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->frequency(hz);
}

int mbed_spi_write(mbed_spi_t p, int value) {
    MBED_ASSERT(p != nullptr);
    return ((SPI *) p)->write(value);
}

int mbed_spi_write1(mbed_spi_t p, const char *tx_buffer, int tx_length, char *rx_buffer, int rx_length) {
    MBED_ASSERT(p != nullptr);
    return ((SPI *) p)->write(tx_buffer, tx_length, rx_buffer, rx_length);
}

void mbed_spi_lock(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->lock();
}

void mbed_spi_unlock(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->unlock();
}

void mbed_spi_select(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->select();
}

void mbed_spi_deselect(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->deselect();
}

void mbed_spi_set_default_write_value(mbed_spi_t p, char data) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->set_default_write_value(data);
}

int mbed_spi_transfer(mbed_spi_t p, const uint8_t *tx_buffer, int tx_length, uint8_t *rx_buffer, int rx_length, void (*callback)(int)) {
    MBED_ASSERT(p != nullptr);
    return ((SPI *) p)->transfer(tx_buffer, tx_length, rx_buffer, rx_length, callback, SPI_EVENT_COMPLETE);
}

int mbed_spi_transfer1(mbed_spi_t p, const uint8_t *tx_buffer, int tx_length, uint8_t *rx_buffer, int rx_length, void (*callback)(int), int event) {
    MBED_ASSERT(p != nullptr);
    return ((SPI *) p)->transfer(tx_buffer, tx_length, rx_buffer, rx_length, callback, event);
}

void mbed_spi_abort_transfer(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->abort_transfer();
}

void mbed_spi_clear_transfer_buffer(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->clear_transfer_buffer();
}

void mbed_spi_abort_all_transfers(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    ((SPI *) p)->abort_all_transfers();
}

int mbed_spi_set_dma_usage(mbed_spi_t p, DMAUsage usage) {
    MBED_ASSERT(p != nullptr);
    return ((SPI *) p)->set_dma_usage(usage);
}

void mbed_spi_free(mbed_spi_t p) {
    MBED_ASSERT(p != nullptr);
    delete (SPI *) p;
}

}