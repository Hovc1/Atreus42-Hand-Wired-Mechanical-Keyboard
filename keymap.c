#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2

#define cad LCTL(LALT(KC_DEL))  //  LCTL(LALT(KC_DEL)) makes a key that sends Control+Alt+Delete with a single keypress.
#define mac_3 C(KC_F5)


//  emojies  //
enum unicode_names {
    rolf,
    thumbup,
    scream
};

const uint32_t PROGMEM unicode_map[] = {
    [rolf]  = 0x1F923,  // rolf and crying
    [thumbup] = 0x1F44D,  // thumbs up
    [scream]  = 0x1F631, // face screaming in fear
};


//  Macro section  //
enum custom_keycodes {  // the safe_range is 100% needed for the first enum/ macro
  mac_1  = SAFE_RANGE,
  mac_2,
  mac_4
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //case QMKBEST:
    //    if (record->event.pressed) {
    //    // when keycode QMKBEST is pressed
    //    SEND_STRING("QMK is the best thing ever!");
    //    } else {
    //    // when keycode QMKBEST is released
    //    }
    //    break;
    case mac_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("k")SS_LCTRL("u"));  //  uncomments code
      }
      break;
    case mac_2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("k")SS_LCTRL("c"));  //  comments code
      }
      break;
    case mac_4:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_RIGHT) "{\n");  //  makes new brackets  // should be SEND_STRING(SS_TAP(X_RIGHT) "{\n");
                                                                    //  the send string keycodes don't have the 4-char aliases (they really should though)
                                                                   //   and there aren't any shifted ones  // SEND_STRING(SS_TAP(X_RIGHT) "{" SS_TAP(X_ENTER)); 
      }
      break;
  }
  return true;
};






/*  Layer 0  (Base Layer) (_QW)
    ┌────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┐
    │ Q  │ W  │ E  │ R  │ T  │              │ Y  │ U  │ I  │ O  │ P  │
    ├────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┤
    │ A  │ S  │ D  │ F  │ G  │              │ H  │ J  │ K  │ L  │ ;: │
    ├────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┤
    │ Z  │ X  │ C  │ V  │ B  ├────┐    ┌────┤ N  │ M  │, < │. > │ /? │
    ├────┼────┼────┼────┼────┤    │    │    ├────┼────┼────┼────┼────┤
    │Ctrl│Lalt│Del │shif│ BS │MO1 │    │MO2 │spac│ent │ESC │' " │tab │
    └────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,   KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_RCTL, KC_LALT, KC_DEL,  KC_LSFT, KC_BSPC, MO(_RS),   MO(_LW), KC_SPC, KC_ENT,  KC_ESC,  KC_QUOT, KC_TAB   ),



/*  Layer 1   (_RS)
    ┌────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┐
    │Vol+│    │    │    │    │              │    │    │ up │    │P/S │
    ├────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┤
    │Vol-│    │shif│ctrl│    │              │home│left│down│righ│end │
    ├────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┤
    │Mute│    │    │    │    ├────┐    ┌────┤    │    │    │    │Del │
    ├────┼────┼────┼────┼────┤    │    │    ├────┼────┼────┼────┼────┤
    │    │    │    │    │    │ XX │    │    │    │    │    │Caps│INS │
    └────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
*/
  [_RS] = LAYOUT( 
    KC_VOLU,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_PSCR ,
    KC_VOLD,  KC_NO,   KC_LSFT, KC_LCTL, KC_NO,                     KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,
    KC_MUTE,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL ,
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_CAPS, KC_INS  ),



/*  Layer 2  (F keys and Reset) (_LW)          
        ┌────┬────┬────┬────┬────┐                              ┌────┬────┬────┬────┬────┐
        │1 ! │2 @ │3 # │4 $ │5 % │                              │6 ^ │7 & │8 * │9 ( │0 ) │
        ├────┼────┼────┼────┼────┤                              ├────┼────┼────┼────┼────┤
        │    │    │    │    │    │                              │    │ LC │ U  │ RC │S U │ Mouse Controle
        ├────┼────┼────┼────┼────┤                              ├────┼────┼────┼────┼────┤
        │    │    │    │    │    ├────┐                    ┌────┤    │ R  │ D  │ L  │S D │ Mouse Controle
        ├────┼────┼────┼────┼────┤    │                    │    ├────┼────┼────┼────┼────┤
        │    │    │    │    │    │    │                    │ XX │    │    │    │    │    │
        └────┴────┴────┴────┴────┴────┘                    └────┴────┴────┴────┴────┴────┘
*/
  [_LW] = LAYOUT( 
    KC_1,    KC_2,     KC_3,      KC_4,    KC_5,                      KC_6,  KC_7,    KC_8,    KC_9,    KC_0 ,
    KC_NO,   KC_NO,    KC_MPRV,   KC_MPLY, KC_MNXT,                   KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U ,
    KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,                     KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D ,
    KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO )
}; 
