#include QMK_KEYBOARD_H

/*
 * HHKB Layout
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │  `  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BkSpc│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Ctrl │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ Fn3 │  '  │▒▒▒▒▒│Enter│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Shift│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│Shift│ Fn  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│▒▒▒▒▒│ Gui │ Alt │█████│█████│█████│Space│█████│█████│█████│▒▒▒▒▒│ Alt │ Gui │▒▒▒▒▒│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    LAYOUT_legacy(
        ESC,    1,    2,   3,   4,   5,   6,   7,   8,    9,    0, MINS,  EQL, BSLS, GRV, \
        TAB,    Q,    W,   E,   R,   T,   Y,   U,   I,    O,    P, LBRC, RBRC, BSPC,      \
        LCTL,    A,    S,   D,   F,   G,   H,   J,   K,    L, SCLN, QUOT,   NO,  ENT,      \
        LSFT,   NO,    Z,   X,   C,   V,   B,   N,   M, COMM,  DOT, SLSH,   NO, RSFT, FN0, \
        NO, LGUI, LALT,                SPC,                   NO, RALT, RGUI,   NO),
    /* 1: HHKB Fn layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Pwr │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Ins │ Del │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Caps │     │     │     │     │     │     │     │ Psc │ Slk │ Pus │ Up  │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │ VoD │ VoU │ Mut │ Ejc │     │NP_* │NP_/ │Home │PgUp │Left │Right│▒▒▒▒▒│NPEnt│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │▒▒▒▒▒│     │     │     │     │     │NP_+ │NP_- │ End │PgDwn│Down │▒▒▒▒▒│     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│▒▒▒▒▒│     │     │█████│█████│█████│     │█████│█████│█████│▒▒▒▒▒│     │     │▒▒▒▒▒│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    LAYOUT_legacy(
       PWR,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS,  DEL, \
       CAPS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PSCR, SLCK, PAUS,   UP, TRNS, TRNS,       \
       TRNS, VOLD, VOLU, MUTE, EJCT, TRNS, PAST, PSLS, HOME, PGUP, LEFT, RGHT,   NO, PENT,       \
       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PPLS, PMNS,  END, PGDN, DOWN,   NO, TRNS, TRNS, \
       TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};