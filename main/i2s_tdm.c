#include "i2s_tdm.h"
#include "freertos/FreeRTOS.h"
#include "driver/i2s_tdm.h"
#include "esp_log.h"
#include "phi_dsp_constants.h"

static const char *TAG = "P4_TDM";
static i2s_chan_handle_t tx_chan = NULL;
static i2s_chan_handle_t rx_chan = NULL;

esp_err_t p4_i2s_tdm_init(void) {
    ESP_LOGI(TAG, "Initializing 8-Channel 24-bit TDM Engine on ESP32-P4");

    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0, I2S_ROLE_MASTER);
    chan_cfg.dma_desc_num = 8;
    chan_cfg.dma_frame_num = 128;
    ESP_ERROR_CHECK(i2s_new_channel(&chan_cfg, &tx_chan, &rx_chan));

    i2s_tdm_config_t tdm_cfg = {
        .clk_cfg = I2S_TDM_CLK_DEFAULT_CONFIG(UAC2_SAMPLE_RATE),
        .slot_cfg = I2S_TDM_PHILIPS_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_32BIT, I2S_SLOT_MODE_STEREO, I2S_TDM_SLOT0 | I2S_TDM_SLOT1 | I2S_TDM_SLOT2 | I2S_TDM_SLOT3 | I2S_TDM_SLOT4 | I2S_TDM_SLOT5 | I2S_TDM_SLOT6 | I2S_TDM_SLOT7),
        .gpio_cfg = {
            .mclk = GPIO_NUM_NC,
            .bclk = GPIO_NUM_12,
            .ws   = GPIO_NUM_13,
            .dout = GPIO_NUM_11,
            .din  = GPIO_NUM_10,
            .invert_flags = { .mclk_inv = false, .bclk_inv = false, .ws_inv = false },
        },
    };
    tdm_cfg.slot_cfg.total_slot = 8;

    ESP_ERROR_CHECK(i2s_channel_init_tdm_mode(tx_chan, &tdm_cfg));
    ESP_ERROR_CHECK(i2s_channel_init_tdm_mode(rx_chan, &tdm_cfg));
    ESP_ERROR_CHECK(i2s_channel_enable(tx_chan));
    ESP_ERROR_CHECK(i2s_channel_enable(rx_chan));

    ESP_LOGI(TAG, "TDM Audio Engine running at %d Hz, 8 Slots Active", UAC2_SAMPLE_RATE);
    return ESP_OK;
}

esp_err_t p4_i2s_tdm_write_8ch(const uint32_t *samples, size_t count) {
    size_t bytes_written = 0;
    return i2s_channel_write(tx_chan, samples, count * sizeof(uint32_t), &bytes_written, portMAX_DELAY);
}

esp_err_t p4_i2s_tdm_read_8ch(uint32_t *samples, size_t count) {
    size_t bytes_read = 0;
    return i2s_channel_read(rx_chan, samples, count * sizeof(uint32_t), &bytes_read, portMAX_DELAY);
}
