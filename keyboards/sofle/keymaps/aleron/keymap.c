// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_brazilian_abnt2.h"

enum {
    TD_LBRC_LPRN,   // ANSI: [ / (
    TD_RBRC_RPRN,   // ANSI: ] / )
    TD_SCLN_CIRC,   // ANSI: ; / ^ / ç
    TD_BR_LBRC,     // ABNT2: [ / (
    TD_BR_RBRC,     // ABNT2: ] / )
};

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
//    _COLEMAK,
    _ABNT2,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_LITERALDQ,
    KC_LITERALSQ
};

#define KC_QWERTY PDF(_QWERTY)
//#define KC_COLEMAK PDF(_COLEMAK)
#define KC_ABNT2 PDF(_ABNT2)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_LITERALSQ, KC_LITERALDQ, KC_MINS, KC_EQL,  KC_DEL, KC_BSPC,
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   TD(TD_LBRC_LPRN),
  KC_LSFT, KC_A,  KC_S, KC_D,  KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SCLN_CIRC),   RSFT_T(KC_QUOT),
  LCTL_T(KC_TAB),  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   XXXXXXX, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   TD(TD_RBRC_RPRN),
                 KC_LGUI,KC_LALT,KC_LCTL, TL_LOWR, KC_ENT,      KC_SPC,  TL_UPPR, RCTL_T(KC_DEL), RALT_T(KC_BSPC),  KC_RGUI
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-----|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

// [_COLEMAK] = LAYOUT(
//   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//   KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
//   KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                  KC_LGUI,KC_LALT,KC_LCTL,TL_LOWR, KC_ENT,        KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
// ),


/* ABNT2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |  [   |   ]  |   8  |   9  |  Del | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  '   |   Q  |   W  |   E  |   R  |   T  |                    |  Y   |   U  |   I  |   O  |   P  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|  H   |   J  |   K  |   L  |   Ç  |  ~   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|  N   |   M  |   ,  |   .  |   ;  |  /   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [_ABNT2] = LAYOUT(
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      TD(TD_BR_LBRC), TD(TD_BR_RBRC), KC_MINS, KC_EQL,  KC_DEL, KC_BSPC,
  BR_QUOT,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  BR_ACUT,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    BR_CCED, RSFT_T(BR_TILD),
  LCTL_T(KC_TAB),  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX, KC_N,    KC_M, KC_COMM,  KC_DOT, BR_SCLN,  BR_SLSH,
                     KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,  KC_SPC,  TL_UPPR, RCTL_T(KC_DEL), RALT_T(KC_BSPC), KC_RGUI
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,C(KC_BSPC), KC_BSPC,
  _______, C(KC_A),  C(KC_S),  C(KC_D),  C(KC_F), KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  UG_TOGG, UG_HUEU , UG_HUED , UG_NEXT , UG_PREV, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_CLEAR_EEPROM,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_ABNT2,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

void td_scln_circ_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Um toque: ponto e vírgula
        tap_code(KC_SCLN);
    } else if (state->count == 2) {
        // Triplo toque: acento circunflexo
        tap_code16(S(KC_6));  // Shift+6 = ^   
    } else if (state->count == 3) {
        // Captura o estado do Shift ANTES de qualquer ação
        bool shifted = (get_mods() & MOD_MASK_SHIFT);
        
        // Produz ç usando Alt + vírgula
        if (shifted) {
            // Para Ç maiúsculo: Shift + Alt + ,
            register_code(KC_RALT);
            tap_code16(S(KC_COMMA));
            unregister_code(KC_RALT);
        } else {
            // Para ç minúsculo: Alt + ,
            register_code(KC_RALT);
            tap_code(KC_COMMA);
            unregister_code(KC_RALT);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_LITERALDQ:
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code16(S(KC_QUOT));
                unregister_code(KC_RALT);
            }
            break;

        case KC_LITERALSQ:
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code16(KC_QUOT);
                unregister_code(KC_RALT);
            }
            break;
    }
    return true;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRC_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
    [TD_RBRC_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
    [TD_SCLN_CIRC] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL,
        td_scln_circ_finished,
        NULL
    ),
    [TD_BR_LBRC]   = ACTION_TAP_DANCE_DOUBLE(BR_LBRC, BR_LPRN),
    [TD_BR_RBRC]   = ACTION_TAP_DANCE_DOUBLE(BR_RBRC, BR_RPRN),    
};

// #ifdef TAPPING_TERM_PER_KEY
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LCTL_T(KC_A):
//         case LALT_T(KC_S):
//         case LSFT_T(KC_D):
//         case LGUI_T(KC_F):
//         case RGUI_T(KC_J):
//         case RSFT_T(KC_K):
//         case RALT_T(KC_L):
//         case RCTL_T(KC_SCLN):
//             return 220;

//         default:
//             return TAPPING_TERM;
//     }
// }
// #endif

// #ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // Home Row Mods: NÃO usar HOLD_ON_OTHER_KEY_PRESS
//         case LCTL_T(KC_A):
//         case LALT_T(KC_S):
//         case LSFT_T(KC_D):
//         case LGUI_T(KC_F):
//         case RGUI_T(KC_J):
//         case RSFT_T(KC_K):
//         case RALT_T(KC_L):
//         case RCTL_T(KC_SCLN):
//             return false;

//         // Demais Mod-Taps
//         default:
//             return true;
//     }
// }
// #endif

// #ifdef FLOW_TAP_TERM
// bool is_flow_tap_key(uint16_t keycode) {
//     switch (keycode) {
//         case LCTL_T(KC_A):
//         case LALT_T(KC_S):
//         case LSFT_T(KC_D):
//         case LGUI_T(KC_F):
//         case RGUI_T(KC_J):
//         case RSFT_T(KC_K):
//         case RALT_T(KC_L):
//         case RCTL_T(KC_SCLN):
//             return true;

//         default:
//             return false;
//     }
// }
// #endif
