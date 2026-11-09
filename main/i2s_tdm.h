#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"

esp_err_t p4_i2s_tdm_init(void);
esp_err_t p4_i2s_tdm_write_8ch(const uint32_t *samples, size_t count);
esp_err_t p4_i2s_tdm_read_8ch(uint32_t *samples, size_t count);
