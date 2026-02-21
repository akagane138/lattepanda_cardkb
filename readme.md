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

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
