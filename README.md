# p4-uac2: High-Speed 8x8 USB Audio Class 2.0 for ESP32-P4

Professional, low-latency, 8-input / 8-output USB Audio Class 2.0 (UAC2) soundcard firmware designed exclusively for the **ESP32-P4** RISC-V SoC (480 Mbps High-Speed USB PHY + TDM/I2S hardware).

---

## Key Architectural Features

* **USB 2.0 High-Speed (480 Mbps):** Full native High-Speed Isochronous endpoints eliminating the 2-channel 12 Mbps bottleneck of legacy ESP32-S2/S3.
* **8x8 Multi-Channel TDM:** 8 channels IN and 8 channels OUT simultaneously at 24-bit / 48 kHz across a single hardware TDM data line.
* **Phi-Damped Feedback Control ($\\phi \\approx 1.618$):** Asynchronous feedback endpoints smoothed with critically damped Golden Ratio filters to eliminate clock drift and buffer clicks without phase resonance.
* **Plug-and-Play Compliance:** Fully class-compliant on macOS, Linux, Windows 10/11, iOS, and Android without external drivers.

---

## Default Hardware Pinout (ESP32-P4)

| Signal | ESP32-P4 GPIO | Description |
| :--- | :--- | :--- |
| **TDM BCLK** | GPIO 12 | Bit Clock (Bit Rate = 48000 * 8 * 32) |
| **TDM WS / FS** | GPIO 13 | Frame Sync (Word Select) |
| **TDM DOUT** | GPIO 11 | Serial Audio Data Output (8 Time Slots to DAC) |
| **TDM DIN** | GPIO 10 | Serial Audio Data Input (8 Time Slots from ADC) |
| **USB D+ / D-** | On-chip HS PHY | Direct connection to USB-C port |

---

## Dual Licensing & Commercial Inquiries

This project is distributed under a Dual-Licensing model:

1. **Open Source (GPLv3):** Free for non-commercial use, research, education, Eurorack DIY builds, and open-source projects. In accordance with GNU GPLv3, any derivative firmware or commercial hardware embedding this code must also be published under GPLv3.
2. **Commercial / Closed-Source License:** If you plan to integrate this high-speed UAC2 audio core into proprietary commercial hardware, DSP audio interfaces, or closed-source firmware, you must acquire a separate commercial license.

For commercial licensing terms, custom DSP adaptations, or hardware consulting, reach out via GitHub: [@kniajevich](https://github.com/kniajevich).

---

## License

This firmware is licensed under the terms of the GNU General Public License v3.0 (GPL-3.0). See the [LICENSE](LICENSE) file for complete details.

Upstream dependencies:
* TinyUSB stack is Copyright (c) Ha Thach under the MIT License.
* ESP-IDF framework is Copyright (c) Espressif Systems under Apache License 2.0.

---

## Support & Sponsorship

If you find this project useful for professional audio hardware, Eurorack modules, or low-latency interfaces, consider sponsoring:

| Network / Asset | Address |
| :--- | :--- |
| **EVM** *(ETH, Arbitrum, Base, BSC, Polygon)* | `0xfd8029b4295d6f4d8AB77Bfc061BBaff4f143C44` |
| **USDT / Tron** *(TRC-20)* | `TQMmeTMudPqafdNqsRnwRGeupBNinLbLdt` |
| **Bitcoin** *(Native SegWit)* | `bc1q9rwm4p5vplqt5a0mdat3vmegm2kgk38zfzlfd7` |
| **Solana** *(SOL, SPL)* | `GKbakfAXmaEXZ4DPTgDJCiZTCtXe9a1qgT5q1Y1hXm35` |
| **Stellar** *(XLM)* | `GACXOMM26U4GL2JT3TEGS2MV5IF7O43Y7X2RGYRUZT2RWQODIOERRITD` |
