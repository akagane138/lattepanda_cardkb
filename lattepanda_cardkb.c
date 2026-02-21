#include "quantum.h"
#include "i2c_master.h"
#include "print.h"

#define CARDKB_ADDR (0x5F << 1)

void keyboard_post_init_kb(void) {
    uprintf("Initializing I2C...\n");
    i2c_init();
    keyboard_post_init_user();
}

void map_and_tap_cardkb(uint8_t ascii) {
    uprintf("Button was pressed: %d \n",ascii);
    //0. Arrow keys
    if (ascii >= 180 && ascii <= 183){
        switch (ascii) {
            case 180: tap_code(KC_LEFT); return;
            case 181: tap_code(KC_UP); return;
            case 182: tap_code(KC_DOWN); return;
            case 183: tap_code(KC_RIGHT); return;
        }
    }


    // 1. Lowercase Letters
    if (ascii >= 'a' && ascii <= 'z') { tap_code(KC_A + (ascii - 'a')); return; }

    // 2. Uppercase Letters (Requires Shift)
    if (ascii >= 'A' && ascii <= 'Z') {
        register_code(KC_LSFT);
        tap_code(KC_A + (ascii - 'A'));
        unregister_code(KC_LSFT);
        return;
    }

    // 3. Numbers
    if (ascii >= '1' && ascii <= '9') { tap_code(KC_1 + (ascii - '1')); return; }
    if (ascii == '0') { tap_code(KC_0); return; }

    // 4. Control Characters
    switch (ascii) {
        case 0x08: tap_code(KC_BSPC); return;
        case 0x0D: tap_code(KC_ENT); return;
        case 0x1B: tap_code(KC_ESC); return;
        case 0x09: tap_code(KC_TAB); return;
        case ' ':  tap_code(KC_SPC); return;
    }

    // 5. Unshifted Symbols
    switch (ascii) {
        case '-': tap_code(KC_MINS); return;
        case '=': tap_code(KC_EQL);  return;
        case '[': tap_code(KC_LBRC); return;
        case ']': tap_code(KC_RBRC); return;
        case '\\': tap_code(KC_BSLS); return;
        case ';': tap_code(KC_SCLN); return;
        case '\'': tap_code(KC_QUOT); return;
        case '`': tap_code(KC_GRV);  return;
        case ',': tap_code(KC_COMM); return;
        case '.': tap_code(KC_DOT);  return;
        case '/': tap_code(KC_SLSH); return;
    }

    // 6. Shifted Symbols
    uint16_t shifted_kc = KC_NO;
    switch (ascii) {
        case '!': shifted_kc = KC_1; break;
        case '@': shifted_kc = KC_2; break;
        case '#': shifted_kc = KC_3; break;
        case '$': shifted_kc = KC_4; break;
        case '%': shifted_kc = KC_5; break;
        case '^': shifted_kc = KC_6; break;
        case '&': shifted_kc = KC_7; break;
        case '*': shifted_kc = KC_8; break;
        case '(': shifted_kc = KC_9; break;
        case ')': shifted_kc = KC_0; break;
        case '_': shifted_kc = KC_MINS; break;
        case '+': shifted_kc = KC_EQL; break;
        case '{': shifted_kc = KC_LBRC; break;
        case '}': shifted_kc = KC_RBRC; break;
        case '|': shifted_kc = KC_BSLS; break;
        case ':': shifted_kc = KC_SCLN; break;
        case '"': shifted_kc = KC_QUOT; break;
        case '~': shifted_kc = KC_GRV; break;
        case '<': shifted_kc = KC_COMM; break;
        case '>': shifted_kc = KC_DOT; break;
        case '?': shifted_kc = KC_SLSH; break;
    }

    if (shifted_kc != KC_NO) {
        register_code(KC_LSFT);
        tap_code(shifted_kc);
        unregister_code(KC_LSFT);
    }
}

void matrix_scan_kb(void) {
    static uint32_t last_poll = 0;
    if (timer_elapsed32(last_poll) < 20) return;
    last_poll = timer_read32();

    uint8_t rx_data = 0;

    // Read 1 byte from CardKB
    if (i2c_receive(CARDKB_ADDR, &rx_data, 1, 10) == I2C_STATUS_SUCCESS) {
        if (rx_data != 0x00) {
            map_and_tap_cardkb(rx_data);
        }
    }
    matrix_scan_user();
}
