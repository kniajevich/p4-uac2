#pragma once

/**
 * @file phi_dsp_constants.h
 * @brief Golden Ratio harmonic constants for jitter damping and queue elasticity.
 */

#define PHI_RATIO                 1.618033988749895f
#define PHI_INV                   0.618033988749895f  // 1 / phi  (High watermark ~ 61.8%)
#define PHI_INV_SQ                0.381966011250105f  // 1 / phi^2 (Low watermark ~ 38.2%)
#define PHI_FEEDBACK_ALPHA        0.381966f           // Critically damped IIR smoothing factor

// Target standard sample rate
#define UAC2_SAMPLE_RATE          48000
#define UAC2_CHANNELS_OUT         8
#define UAC2_CHANNELS_IN          8
#define UAC2_BIT_DEPTH            24
#define UAC2_BYTES_PER_SAMPLE     4                   // 24-bit in 32-bit slot
