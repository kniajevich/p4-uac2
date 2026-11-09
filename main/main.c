#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "tinyusb.h"
#include "tinyusb_default_config.h"
#include "tusb.h"
#include "i2s_tdm.h"
#include "phi_dsp_constants.h"

static const char *TAG = "P4_UAC2_MAIN";

void app_main(void) {
    ESP_LOGI(TAG, "=== Starting ESP32-P4 High-Speed UAC2 8x8 Soundcard ===");
    ESP_LOGI(TAG, "Golden Ratio Sync Damping Active (Alpha = %.4f)", PHI_FEEDBACK_ALPHA);

    // 1. Initialize High-Speed Hardware TDM Audio Engine
    ESP_ERROR_CHECK(p4_i2s_tdm_init());

    // 2. Initialize TinyUSB Device Stack via modern v2 Default Configuration
    tinyusb_config_t tusb_cfg = TINYUSB_DEFAULT_CONFIG();
#if defined(TUD_OPT_HIGH_SPEED) && TUD_OPT_HIGH_SPEED
    tusb_cfg.port = TINYUSB_PORT_HIGH_SPEED_0;
#endif
    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));

    ESP_LOGI(TAG, "UAC2 High-Speed Audio Subsystem Live & Ready for DAW connection");
}
