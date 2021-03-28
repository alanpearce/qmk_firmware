/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#define BASE 0
#define SYMB 1
#define NUMB 2
#define PLOV 3

#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | L1/ESC |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  { \   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  | RMB  |           |Plover|   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LMB  |           |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .-----.
 *                    | Super/Del|   |Ent/ALT|                                 | Tab  |   |BKSP |
 *                    '----------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        | MMB   |                      | PgDn  |
 *                                 ,------|-------|                      |-------|------.
 *                                 | SYMB | NUMB  |                      | SYMB  | NUMB |
 *                                 | Space| Escape|                      | Mod   |Space |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    LT(NUMB, KC_ESC),       KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                          KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_LBRC,
    MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_BTN2,                       TG(PLOV), KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_BTN1, KC_BTN3,     KC_PGDN, KC_BSPC,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
  MT(MOD_LGUI, KC_DEL), MT(MOD_LALT, KC_ENT), LT(SYMB, KC_SPC), LT(NUMB, KC_ESC),    LT(SYMB, KC_ENT), LT(NUMB, KC_SPC), KC_TAB, KC_BSPC
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |      |      |      |      |      |  \ |   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | TXBOLT |  #   |  $   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | GEMINI |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   | DEL |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |   ;  |   =   |                     |   =   |   ;  |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                           _______, _______, _______, _______, _______, KC_BSLS,
    ST_BOLT, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,                          _______, KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
    ST_GEM,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______,        _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                        _______, _______, KC_SCLN, KC_EQL,         KC_EQL,  KC_SCLN, KC_PGUP, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | BTN1 |           |      | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | BTN2 |           |      | MLFT | MDWN | MUP  | MRGHT|Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_VOLU,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,     _______, _______,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY, KC_MNXT,
                                        _______, _______, _______, _______,     _______, _______, _______, _______
    ),

/* Plover
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  #   |  #   |  #   |  #   |  #   |                         |  #   |  #   |  #   |  #   |  #   |  #     |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  S   |  T   |  P   | H    | *    |      |           |QWERTY|  *   |  F   |  P   |  L   |  T   |  D     |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  S   |  K   |  W   | R    | *    |      |           |      |  *   |  R   |  B   |  G   |  S   |  Z     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .------.
 *                        |  A   |   |  O   |                                 |  E   |   | U    |
 *                        '------'   '------'                                 `------.   '------'
 *                                        ,-------.       ,-------.
 *                                        |       |       |  PWR  |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 | RES1 | BKSP  |       | BKSP  | RES2 |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[PLOV] = LAYOUT_gergo(
    _______, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                                              STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
    _______, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, ______,                            _______, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, ______,  _______,         STN_PWR, _______, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                        STN_A,   STN_O,   STN_RE1, KC_BSPC,         KC_BSPC, STN_RE2, STN_E,   STN_U
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT); // or STENO_MODE_GEMINI
};
