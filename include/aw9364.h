/*
 * SPDX-FileCopyrightText: © 2025 Hiruna Wijesinghe <hiruna.kawinda@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <driver/ledc.h>

#define AW9364_MAX_BRIGHTNESS_STEPS 16
#define AW9364_MIN_FADE_TIME_MS 50
#define AW9364_MAX_FADE_TIME_MS 10000

typedef struct aw9364_dev_t *aw9364_dev_handle_t;

esp_err_t aw9364_init(const ledc_channel_config_t *ledc_channel_cfg, const ledc_timer_config_t *ledc_timer_cfg, aw9364_dev_handle_t *out_hdl);

esp_err_t aw9364_set_brightness_step(aw9364_dev_handle_t dev, uint8_t step, uint32_t fade_time_ms);

esp_err_t aw9364_set_brightness_pct(aw9364_dev_handle_t dev, uint8_t pct, uint32_t fade_time_ms);

esp_err_t aw9364_increment_brightness_step(aw9364_dev_handle_t dev, uint32_t fade_time_ms);

esp_err_t aw9364_decrement_brightness_step(aw9364_dev_handle_t dev, uint32_t fade_time_ms);

uint8_t aw9364_get_brightness_pct(aw9364_dev_handle_t dev);

uint8_t aw9364_get_brightness_step(aw9364_dev_handle_t dev);

esp_err_t aw9364_deinit(aw9364_dev_handle_t dev);

#ifdef __cplusplus
} /*extern "C"*/
#endif