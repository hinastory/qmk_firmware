#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define EISU LALT(KC_GRV)
#define KC_LSPC LT(MO(_LOWER), KC_SPC)
#define KC_LENT LT(MO(_LOWER), KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | Eisu |                    | Kana |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Alt  |   Z  |   X  |   C  |   V  |   B  | LSpc |                    | Bksp |   N  |   M  |   ,  |   .  |   /  |   \  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |  Gui |  Adj | RAISE|||||||| Shift| LSpc |      ||||||||      | Bksp |LEnter||||||||  =   | Ins  |  Del |  `   |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_LBRC,                KC_RBRC , KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_MINS, \
    KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,  KC_LANG2,               KC_LANG1, KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
    KC_LALT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_LSPC,                 KC_BSPC, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, \
    KC_ESC, KC_LGUI, MO(_ADJUST),RAISE,   KC_LSFT,   KC_LSPC, KC_NO,        KC_NO, KC_BSPC, KC_LENT,  KC_EQL,  KC_INS,  KC_DEL,  KC_GRV \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      | Home | PgUp | PgDn |  End |      | PSCR |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | Left | Down |  Up  | Right|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,_______,_______,               _______,KC_HOME, KC_PGUP, KC_PGDN, KC_END, XXXXXXX, KC_PSCR, \
    _______,_______,_______,_______,_______,_______,_______,               _______,KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,XXXXXXX, XXXXXXX, \
    _______,_______,_______,_______,_______,_______,_______,               _______,_______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,_______,               _______,_______,_______,_______,_______,_______,_______  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |  (   |                    |  )   |   7  |   8  |   9  |   0  |   @  |   $  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |   ,  |                    |   .  |   4  |   5  |   6  |   *  |   !  |   &  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |   1  |   2  |   3  |   #  |   %  |   ^  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    _______,_______,_______,_______,_______,_______,KC_LPRN,               KC_RPRN,   KC_7,   KC_8,   KC_9,   KC_0,  KC_AT,KC_DLR, \
    _______,_______,_______,_______,_______,_______,KC_COMM,               KC_DOT,    KC_4,   KC_5,   KC_6,KC_ASTR,KC_EXLM,KC_AMPR, \
    _______,_______,_______,_______,_______,_______,_______,               _______,   KC_1,   KC_2,   KC_3,KC_HASH,KC_PERC,KC_CIRC, \
    _______,_______,_______,_______,_______,_______,_______,               _______,_______,_______,_______,_______,_______,_______  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  F7  |  F8  |  F9  | F10  |  F11 | F12  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | SAT- | SAT+ | VAL+ |  VAL-|      |                    |      |  F4  |  F5  |  F6  |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |  F1  |  F2  |  F3  |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______,  RESET,RGB_TOG,RGB_MOD,RGB_HUD,RGB_HUI,_______,               _______,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, \
    _______,_______,RGB_SAD,RGB_SAI,RGB_VAD,RGB_VAI,_______,               _______,  KC_F4,  KC_F5,  KC_F6,_______,_______,_______, \
    _______,_______,BL_TOGG,BL_BRTG, BL_INC, BL_DEC,_______,               _______,  KC_F1,  KC_F2,  KC_F3,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,_______,               _______,_______,_______,_______,_______,_______,_______ \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
