idf_component_register(
    SRCS "main.c" "usb_descriptors.c" "i2s_tdm.c"
    INCLUDE_DIRS "."
    REQUIRES esp_tinyusb esp_driver_i2s esp_timer freertos
)
