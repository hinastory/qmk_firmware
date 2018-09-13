#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _META   1
#define _NUMPAD 2
#define _ADJUST 3

enum custom_keycodes {
   KANA1 = SAFE_RANGE
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_RST RESET
#define KC_DBUG DEBUG

#define KC_LORW KC_LANG2
#define KC_RASE KC_LANG1
#define KC_NUM MO(_NUMPAD)
#define KC_MSPC LT(MO(_META), KC_SPC)
#define KC_GGRV GUI_T(KC_GRV)
#define KC_MAC MAGIC_UNSWAP_RALT_RGUI
#define KC_WIN MAGIC_SWAP_RALT_RGUI
#define KC_CAD ALTG(KC_DEL)
#define KC_CAI ALTG(KC_INS)
#define KC_AESC LT(MO(_ADJUST), KC_ESC)

#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     AESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , EQL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB, Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LALT, Z  , X  , C  , V  , B  ,LORW,     RASE, N  , M  ,COMM,DOT ,SLSH,BSLS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       NUM,LSFT,MSPC,          BSPC,ENT,GGRV
  //                  `----+----+----'        `----+----+----'
  ),

  [_META] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2,  F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,F11 ,F12 ,    ,LOCK,BTN3,                   ,HOME,PGDN,PGUP,END ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,BTN2,               BSPC,LEFT,DOWN, UP ,RGHT,DEL ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,BTN1,CAI ,     CAD ,WH_D,MS_L,MS_D,MS_U,MS_R,WH_U,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,               HASH, 7  , 8  , 9  , 0  ,ASTR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               LPRN, 4  , 5  , 6  ,RPRN,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               LBRC, 1  , 2  , 3  ,RBRC,PLUS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,LCBR,PERC,COMM,DOT ,RCBR,MINS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),


  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,RST ,    ,    ,    ,DBUG,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               RTOG,RHUI,RSAI,RVAI,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               RMOD,RHUD,RSAD,RVAD,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,MAC ,     WIN ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KANA1:
    if (record->event.pressed) {
      if(keymap_config.swap_ralt_rgui==false){
        register_code(KC_LANG1);
      }else{
        SEND_STRING(SS_LALT("`"));
      }
    } else {
      unregister_code(KC_LANG1);
    }
    return false;
    break;
  }
  return true;
}
