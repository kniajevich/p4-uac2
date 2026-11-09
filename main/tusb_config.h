#pragma once

#include "tusb_option.h"

#define CFG_TUSB_RHPORT0_MODE     (OPT_MODE_DEVICE | OPT_MODE_HIGH_SPEED)
#define CFG_TUD_AUDIO             1
#define CFG_TUD_AUDIO_FUNC_1_DESC_CLK_SRC_48K_EP_IN   0x81
#define CFG_TUD_AUDIO_FUNC_1_DESC_CLK_SRC_48K_EP_OUT  0x01
#define CFG_TUD_AUDIO_EP_SZ_IN_MAX                     (48 * 8 * 4) // 48 samples/ms * 8 ch * 4 bytes
#define CFG_TUD_AUDIO_EP_SZ_OUT_MAX                    (48 * 8 * 4)
#define CFG_TUD_AUDIO_FUNC_1_EP_IN_SZ_MAX              CFG_TUD_AUDIO_EP_SZ_IN_MAX
#define CFG_TUD_AUDIO_FUNC_1_EP_OUT_SZ_MAX             CFG_TUD_AUDIO_EP_SZ_OUT_MAX
#define CFG_TUD_AUDIO_FUNC_1_EP_OUT_SW_BUF_SZ          (CFG_TUD_AUDIO_EP_SZ_OUT_MAX * 4)
#define CFG_TUD_AUDIO_FUNC_1_EP_IN_SW_BUF_SZ           (CFG_TUD_AUDIO_EP_SZ_IN_MAX * 4)
#define CFG_TUD_AUDIO_FUNC_1_N_CHANNELS_RX             8
#define CFG_TUD_AUDIO_FUNC_1_N_CHANNELS_TX             8
