// Based off andrew_osx keymap, which itself is based off ergodox ez default
// Guiding principles:
// 1. Cool as this keyboard is, I will from time to time need to use standard
//    QWERTY keyboards. So this layout doesn't deviate too much from that.
// 2. Layer toggles are a bit much to keep in your head. So these layers are
//    triggered by holding a key, and are immediately dismissed when releasing.
//    This way you hold the layer in your finger.

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0  // Basic layer
#define PROG 1  // Programmer layer
#define MDIA 2  // Media layer
#define OPER 3  // OS layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  |~~~~~~|           |~~~~~~|   6  |   7  |   8  |   9  |   0  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |~~~~~~|           |~~~~~~|   Y  |   U  |   I  |   O  |   P  |~~~~~~~~|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Cap/Ctrl| A/L1 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/L2 | '/Hyper|
 * |--------+------+------+------+------+------|~~~~~~|           |~~~~~~|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //L3 | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  |GuiAlt| Left | Right|                                       | Down |  Up  |GuiAlt| Alt  | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  \   |  {   |       |  }   | Esc  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  [   |       |  ]   |      |      |
 *                                 | Space| LGui |------|       |------| RGui |Enter |
 *                                 |      |      |  (   |       |  )   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
  // Left Hand
  KC_GRV,           KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_NO,
  KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_NO,
  CTL_T(KC_CAPS),   LT(PROG,KC_A),    KC_S,             KC_D,             KC_F,             KC_G,
  KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_NO,
  KC_LCTL,          KC_LALT,          LALT(KC_LGUI),       KC_LEFT,          KC_RGHT,

  // Left Thumb
                                                                                            KC_BSLS,          KC_LCBR,
                                                                                                              KC_LBRC,
                                                                          KC_SPC,           KC_LGUI,          KC_RPRN,

  // Right Hand
  KC_NO,            KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_BSPC,
  KC_NO,            KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_NO,
                    KC_H,             KC_J,             KC_K,             KC_L,             LT(MDIA,KC_SCLN), ALL_T(KC_QUOT),
  KC_NO,            KC_N,             KC_M,             KC_COMM,          KC_DOT,           LT(OPER,KC_SLSH), KC_RSFT,
                                      KC_DOWN,          KC_UP,            RALT(KC_RGUI),    KC_RALT,          KC_RCTL,

  // Right Thumb
  KC_RCBR,          KC_ESC,
  KC_RBRC,
  KC_RPRN,          KC_RGUI,          KC_ENT
),

/* Keymap 1: Programmer layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  /   |  {   |  }   |  |   |      |           |      |      |  7   |  8   |  9   |  *   |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  #   |  (   |  )   |  -   |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  `   |  [   |  ]   |  _   |      |           |      |      |  1   |  2   |  3   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |  .   |  0   |  =   |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[PROG] = KEYMAP(
  // Left Hand
  KC_TRNS,          KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_SLSH,          KC_LCBR,          KC_RCBR,          KC_PIPE,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_HASH,          KC_LPRN,          KC_RPRN,          KC_MINS,
  KC_TRNS,          KC_TRNS,          KC_GRV,           KC_LBRC,          KC_RBRC,          KC_UNDS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,

  // Left Thumb
                                                                                            KC_TRNS,          KC_TRNS,
                                                                                                              KC_TRNS,
                                                                          KC_TRNS,          KC_TRNS,          KC_TRNS,

  // Right Hand
  KC_TRNS,          KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,
  KC_TRNS,          KC_TRNS,          KC_7,             KC_8,             KC_9,             KC_ASTR,          KC_F12,
                    KC_TRNS,          KC_4,             KC_5,             KC_6,             KC_PLUS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_1,             KC_2,             KC_3,             KC_SLSH,          KC_TRNS,
                                      KC_TRNS,          KC_DOT,           KC_0,             KC_EQL,           KC_TRNS,

  // Right Thumb
  KC_TRNS,          KC_TRNS,
  KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS
),

/* Keymap 2: Media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down |Right |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Play | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolDn |VolUp | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|      |      |
 *                                 |      |      | 3clk |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = KEYMAP(
  // Left Hand
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_MS_U,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_MS_L,          KC_MS_D,          KC_MS_R,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,

  // Left Thumb
                                                                                            KC_TRNS,          KC_TRNS,
                                                                                                              KC_TRNS,
                                                                          KC_BTN1,          KC_BTN2,          KC_BTN3,

  // Right Hand
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_UP,            KC_TRNS,          KC_TRNS,          KC_TRNS,
                    KC_TRNS,          KC_LEFT,          KC_DOWN,          KC_RGHT,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_MPRV,          KC_MNXT,          KC_MPLY,          KC_TRNS,          KC_TRNS,
                                      KC_VOLD,          KC_VOLU,          KC_MUTE,          KC_TRNS,          KC_TRNS,

  // Right Thumb
  KC_TRNS,          KC_TRNS,
  KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS
),

/* Keymap 3: OS layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |GiAtUp|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |GiAtLt|GiAtDn|GiAtRt|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |GuiTab|GiStTb|      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[OPER] = KEYMAP(
  // Left Hand
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,

  // Left Thumb
                                                                                            KC_TRNS,          KC_TRNS,
                                                                                                              KC_TRNS,
                                                                          KC_TRNS,          KC_TRNS,          KC_TRNS,

  // Right Hand
  KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS,          LGUI(LALT(KC_UP)),KC_TRNS,          KC_TRNS,          KC_TRNS,
                    KC_TRNS,          LGUI(LALT(KC_LEFT)),LGUI(LALT(KC_DOWN)),LGUI(LALT(KC_RGHT)),KC_TRNS,    KC_TRNS,
  KC_TRNS,          KC_TRNS,          LGUI(KC_TAB),     LGUI(LSFT(KC_TAB)),KC_TRNS,         KC_TRNS,          KC_TRNS,
                                      KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,

  // Right Thumb
  KC_TRNS,          KC_TRNS,
  KC_TRNS,
  KC_TRNS,          KC_TRNS,          KC_TRNS
),
};


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(PROG)                // FN1 - Momentary Layer 1 (symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case PROG:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        case OPER:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
