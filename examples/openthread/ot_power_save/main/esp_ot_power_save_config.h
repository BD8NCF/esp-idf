/*
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 *
 * OpenThread Command Line Example
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */

#pragma once

#include "esp_openthread_types.h"

# define CONFIG_OPENTHREAD_NETWORK_DATASET "0e080000000000010000000300000b35060004001fffe002084c14b4d26855fcd00708fdf7e918eb62e2a905107ca0e75a6ead4b960cfe073386943605030f4f70656e5468726561642d616631360102af1604102b9084b26c9a7d10a1a729bfc2e84ea00c0402a0f7f8"
# define CONFIG_OPENTHREAD_NETWORK_POLLPERIOD_TIME 3000

#if SOC_IEEE802154_SUPPORTED
#define ESP_OPENTHREAD_DEFAULT_RADIO_CONFIG()              \
    {                                                      \
        .radio_mode = RADIO_MODE_NATIVE,                   \
    }
#endif

#define ESP_OPENTHREAD_DEFAULT_HOST_CONFIG()                    \
    {                                                           \
        .host_connection_mode = HOST_CONNECTION_MODE_CLI_UART,  \
        .host_uart_config = {                                   \
            .port = 0,                                          \
            .uart_config =                                      \
                {                                               \
                    .baud_rate = 115200,                        \
                    .data_bits = UART_DATA_8_BITS,              \
                    .parity = UART_PARITY_DISABLE,              \
                    .stop_bits = UART_STOP_BITS_1,              \
                    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,      \
                    .rx_flow_ctrl_thresh = 0,                   \
                    .source_clk = UART_SCLK_DEFAULT,            \
                },                                              \
            .rx_pin = UART_PIN_NO_CHANGE,                       \
            .tx_pin = UART_PIN_NO_CHANGE,                       \
        },                                                      \
    }

#define ESP_OPENTHREAD_DEFAULT_PORT_CONFIG()    \
    {                                           \
        .storage_partition_name = "ot_storage", \
        .netif_queue_size = 10,                 \
        .task_queue_size = 10,                  \
    }
