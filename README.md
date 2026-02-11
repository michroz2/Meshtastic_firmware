# ⚠️ Custom Ebyte E22-400M30S/M33S Build (SX1268)
[EN] Meshtastic minimallistically-Modified Firmware with Ebyte E22 Mod (SX1268)
This is a customized version of the Meshtastic firmware for LILYGO T-Beam v1.1, specifically adapted for testing the board with high-power Ebyte E22-400M30S/M33S modules (SX1268).

Key Modifications
Conflict Resolution: Relocated LoRa pins to avoid interference with the onboard SX1276 chip.
High Power Support: Optimized for 30dBm (1W) and 33dBm (2W) operations - independent on Meshtastic regional settings.
Power Management: Forced LDO mode and disabled OCP (Overcurrent Protection) to prevent chip crashes during transmission.

Hardware:
Common SPI pins parallel to old Lora module. VCC is wired directly to stock battery contact.
Signal,GPIO (ESP32),Note
LORA_CS (NSS),13,Chip Select
LORA_RESET,14,Hardware Reset
LORA_BUSY,15,Busy Status
LORA_DIO1,35,Interrupt
LORA_TXEN,2,Power Amplifier 
LORA_RXEN,25,LNA Enable

[RU] Прошивка Meshtastic с модом Ebyte E22 (SX1268)
Это с минимальными изменениями кастомная версия прошивки Meshtastic для LILYGO T-Beam v1.1, адаптированная для проверки работы платы с мощными модулями Ebyte E22-400M30S/M33S (SX1268).

Основные изменения
Разрешение конфликтов: Переназначены пины LoRa, чтобы исключить конфликты со штатным чипом SX1276, распаянным на плате.
Поддержка высокой мощности: Оптимизировано для работы на мощностях 30dBm (1 Вт) и 33dBm (2 Вт)- независимо от региональных и юзерских настроек Meshtastic.
Питание: Принудительно включен режим LDO и отключена защита по току OCP, что предотвращает зависание чипа в момент передачи.
Разводка пинов - см. выше, Общие SPI пины припаяны параллельно старой LoRa. Питание заведено напрямую на штатную батарею.

### Сборка / How to Build:
При использовании этой прошивки с мощной LoRa следует использовать окружение (environment) `tbeam-e22-433`
При использовании этой прошивки со стандартной LoRa следует использовать окружение (environment) `tbeam`

---<div align="center" markdown="1">

<img src=".github/meshtastic_logo.png" alt="Meshtastic Logo" width="80"/>
<h1>Meshtastic Firmware</h1>

![GitHub release downloads](https://img.shields.io/github/downloads/meshtastic/firmware/total)
[![CI](https://img.shields.io/github/actions/workflow/status/meshtastic/firmware/main_matrix.yml?branch=master&label=actions&logo=github&color=yellow)](https://github.com/meshtastic/firmware/actions/workflows/ci.yml)
[![CLA assistant](https://cla-assistant.io/readme/badge/meshtastic/firmware)](https://cla-assistant.io/meshtastic/firmware)
[![Fiscal Contributors](https://opencollective.com/meshtastic/tiers/badge.svg?label=Fiscal%20Contributors&color=deeppink)](https://opencollective.com/meshtastic/)
[![Vercel](https://img.shields.io/static/v1?label=Powered%20by&message=Vercel&style=flat&logo=vercel&color=000000)](https://vercel.com?utm_source=meshtastic&utm_campaign=oss)

<a href="https://trendshift.io/repositories/5524" target="_blank"><img src="https://trendshift.io/api/badge/repositories/5524" alt="meshtastic%2Ffirmware | Trendshift" style="width: 250px; height: 55px;" width="250" height="55"/></a>

</div>

</div>

<div align="center">
	<a href="https://meshtastic.org">Website</a>
	-
	<a href="https://meshtastic.org/docs/">Documentation</a>
</div>

## Overview

This repository contains the official device firmware for Meshtastic, an open-source LoRa mesh networking project designed for long-range, low-power communication without relying on internet or cellular infrastructure. The firmware supports various hardware platforms, including ESP32, nRF52, RP2040/RP2350, and Linux-based devices.

Meshtastic enables text messaging, location sharing, and telemetry over a decentralized mesh network, making it ideal for outdoor adventures, emergency preparedness, and remote operations.

### Get Started

- 🔧 **[Building Instructions](https://meshtastic.org/docs/development/firmware/build)** – Learn how to compile the firmware from source.
- ⚡ **[Flashing Instructions](https://meshtastic.org/docs/getting-started/flashing-firmware/)** – Install or update the firmware on your device.

Join our community and help improve Meshtastic! 🚀

## Stats

![Alt](https://repobeats.axiom.co/api/embed/8025e56c482ec63541593cc5bd322c19d5c0bdcf.svg "Repobeats analytics image")

