# lattepanda_cardkb


This is just a simple litlle QMK firmware to turn the M5Stack CardKb into an USB keyboard
using an RP2040.
This is to be used with the stock Firmware of the Cardkb v1.1

* Keyboard Maintainer: [akagane138](https://github.com/akagane138)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make lattepanda_cardkb:default

Flashing example for this keyboard:

    make lattepanda_cardkb:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
Zou have to check the Documentation for your rp2024
for mine:
while holding down the "BOOT" button pres the "MCU RST" button then let go of the "BOOT" button.
A Removable drive should appear on Zour Comuter Drag n Drop the Firmware there
