#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "tinyusb.h"
#include "tusb_audio.h"
#include "i2s_tdm.h"
#include "phi_dsp_constants.h"

static const char *TAG = "P4_UAC2_MAIN";

void app_main(void) {
    ESP_LOGI(TAG, "=== Starting ESP32-P4 High-Speed UAC2 8x8 Soundcard ===");
    ESP_LOGI(TAG, "Golden Ratio Sync Damping Active (Alpha = %.4f)", PHI_FEEDBACK_ALPHA);

    // 1. Initialize High-Speed Hardware TDM Audio Engine
    ESP_ERROR_CHECK(p4_i2s_tdm_init());

    // 2. Initialize TinyUSB Device Stack
    tinyusb_config_t const tusb_cfg = {
        .device_descriptor = NULL,
        .string_descriptor = NULL,
        .external_phy = false,
        .configuration_descriptor = NULL,
    };
    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));

    ESP_LOGI(TAG, "UAC2 High-Speed Audio Subsystem Live & Ready for DAW connection");
}
