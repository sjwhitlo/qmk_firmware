/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers { _QWERTY, _QWERTY_NUM, _NUMPAD, _SELECTION, _STENO, _TEAMS, _KEYBOARD_SETTINGS, _MEDIA, _LAYER_SELECT, _QWERTY_CODE };

enum planck_keycodes { QWERTY = SAFE_RANGE, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, R_INTENT, G_INTENT, B_INTENT };

#define LAYERS  MO(_LAYER_SELECT)
#define MEDIA   MO(_MEDIA)
#define SFT_CAP SFT_T(KC_CAPS)
#define NUM_SPC LT(_QWERTY_NUM, KC_SPC)
// shortcuts for _TEAMS
#define PSH_TLK LALT(KC_SPC)
#define TGL_HND SGUI(KC_K)
#define TGL_MIC SGUI(KC_M)
#define TGL_VID SGUI(KC_O)
#define OPN_CHT SGUI(KC_R)
#define TM_SAFE OSM(MOD_LSFT | MOD_LGUI)


/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Esc   |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   ;    |   '    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  ⇧/⇪   |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   ,    |   .    |   /    |  ⇧/⏎   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |   Alt  |  Cmd   | LAYERS | Space  | Space  | Space  | NUM/SP | MEDIA  |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    SFT_CAP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
    KC_LCTL, KC_LALT, KC_LGUI, LAYERS,  KC_SPC,  KC_SPC,  KC_SPC,  NUM_SPC, MEDIA,   XXXXXXX, XXXXXXX, XXXXXXX
),

/* QWERTY Numbers
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        |   !    |   @    |   #    |   $    |   %    |   ^    |   &    |   *    |   (    |   )    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY_NUM] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* QWERTY Code
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        |        |   @    |   (    |   )    |        |   \    |   *    |   /    |   %    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   `    |   $    |   {    |   }    |        |   !    |   +    |   -    |   =    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |   &    |   [    |   ]    |        |   |    |   _    |   <    |   >    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY_CODE] = LAYOUT_planck_grid(
    _______, XXXXXXX, KC_AT,   KC_LPRN, KC_RPRN, XXXXXXX, KC_BSLS, KC_ASTR, KC_SLSH, KC_PERC, XXXXXXX, _______,
    _______, KC_GRV,  KC_DLR,  KC_LCBR, KC_RCBR, XXXXXXX, KC_EXLM, KC_PLUS, KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX,
    _______, XXXXXXX, KC_AMPR, KC_LBRC, KC_RBRC, XXXXXXX, KC_PIPE, KC_UNDS, KC_LT,   KC_GT,   XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Number Pad
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |        |        |   ^    |        |        |        |   7    |   8    |   9    |   *    |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Esc   |        |   <    |   v    |   >    |        |        |   4    |   5    |   6    |   -    |   /    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        |        |        |        |        |   1    |   2    |   3    |   +    | Enter  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |   Alt  |  Cmd   | LAYERS |        |        |   0    |   .    | MEDIA  |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    KC_TAB,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_BSPC,
    KC_ESC,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PSLS,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PENT,
    KC_LCTL, KC_LALT, KC_LGUI, LAYERS,  XXXXXXX, XXXXXXX, KC_P0,   KC_PDOT, MEDIA,   XXXXXXX, XXXXXXX, XXXXXXX
),

/* Stenography
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |   #    |   #    |   #    |   #    |        |        |   #    |   #    |   #    |   #    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Esc   |   S    |   T    |   P    |   H    |        |   *    |   F    |   P    |   L    |   T    |   D    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   S    |   K    |   W    |   R    |        |   *    |   R    |   B    |   G    |   S    |   Z    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |  Cmd   | LAYERS |   A    |   E    |   O    |   U    | MEDIA  |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_STENO] = LAYOUT_planck_grid(
    KC_TAB,  STN_N1,  STN_N1,  STN_N1,  STN_N1,  XXXXXXX, XXXXXXX, STN_N1,  STN_N1,  STN_N1,  STN_N1,  XXXXXXX,
    KC_ESC,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  XXXXXXX, STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  XXXXXXX, STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    XXXXXXX, XXXXXXX, KC_LGUI, LAYERS,  STN_A,   STN_E,   STN_O,   STN_U,   MEDIA,   XXXXXXX, XXXXXXX, XXXXXXX
),

/* Teams
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |        |        |        |        |        |        |        |        |        |        |End Call|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Esc   |        |        |        |        |        |        |Opn Chat|Tog Vid |Tog Mic |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |Tog Hand|        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |  Alt   |  Cmd   | LAYERS |        |        |  Talk  | Safety | MEDIA  |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_TEAMS] = LAYOUT_planck_grid(
    KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_H,
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OPN_CHT, TGL_VID, TGL_MIC, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TGL_HND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LALT, KC_LGUI, LAYERS,  XXXXXXX, XXXXXXX, PSH_TLK, TM_SAFE, MEDIA,   XXXXXXX, XXXXXXX, XXXXXXX
),

/* Selection
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |   ⌘Y   |        |   ⌘A   |   ⌘D   |        |        |        |   ^    |        |        |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Esc   |   ⌘Z   |   ⌘X   |   ⌘C   |   ⌘V   |        |        |   <    |   v    |   >    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |   Alt  |  Cmd   | LAYERS |        |        |        |        | MEDIA  |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_SELECTION] = LAYOUT_planck_grid(
    KC_TAB,  G(KC_Y), XXXXXXX, G(KC_A), G(KC_D), XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSPC,
    KC_ESC,  G(KC_Z), G(KC_X), G(KC_C), G(KC_V), XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LALT, KC_LGUI, LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MEDIA,   XXXXXXX, XXXXXXX, XXXXXXX
),

/* Keyboard Settings
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | LAYERS |        |        |        |        | MEDIA  |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_KEYBOARD_SETTINGS] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MEDIA,   XXXXXXX, XXXXXXX, XXXXXXX
),


/* Media
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        |        | BkLt - |Tog BkLt| BkLt + |        |        |  Mute  | Vol -  | Vol +  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | Brt -  | Brt +  |        |        |  Prev  |  Play  |  Next  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |KB Brt -|KBBrtTog|KB Brt +|        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | LAYERS |        |        |        |        | -hold- |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, BL_DOWN, BL_TOGG, BL_UP,   XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, RGB_VAD, RGB_TOG, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Layer Selection
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        |        |  CYAN  |MAGENTA | YELLOW |        |        |        |   ^    |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |  RED   | GREEN  |  BLUE  |        |        |   <    |   v    |   >    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |  Play  | Vol -  | Vol +  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | -hold- |        |        |        |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_LAYER_SELECT] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, CYAN,    MAGENTA, YELLOW,  XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, RED,     GREEN,   BLUE,    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};
/* clang-format on */

void set_underglow_lighting(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            rgblight_setrgb(RGB_RED);
            break;
        case _NUMPAD:
            rgblight_setrgb(RGB_GREEN);
            break;
        case _STENO:
            rgblight_setrgb(RGB_BLUE);
            break;
        case _KEYBOARD_SETTINGS:
            rgblight_setrgb(RGB_CYAN);
            break;
        case _TEAMS:
            rgblight_setrgb(RGB_MAGENTA);
            break;
        case _SELECTION:
            rgblight_setrgb(RGB_YELLOW);
            break;
        case _MEDIA:
            rgblight_setrgb(RGB_PURPLE);
            break;
        case _LAYER_SELECT:
            rgblight_setrgb(RGB_WHITE);
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _QWERTY_NUM, _LAYER_SELECT, _QWERTY_CODE);
    set_underglow_lighting(state);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RED:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case GREEN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NUMPAD);
            }
            return false;
            break;
        case BLUE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_STENO);
            }
            return false;
            break;
        case CYAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_KEYBOARD_SETTINGS);
            }
            return false;
            break;
        case MAGENTA:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_TEAMS);
            }
            return false;
            break;
        case YELLOW:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SELECTION);
            }
            return false;
            break;
//        case MEDIA:
//            if (record->event.pressed) {
//                break;
//            }
//            return false;
//            break;
//        case LAYERS:
//            if (record->event.pressed) {
//                break;
//            }
//            return false;
//            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307	

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

//const rgblight_segment_t PROGMEM qwerty_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_RED} );
//const rgblight_segment_t PROGMEM numpad_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_GREEN} );
//const rgblight_segment_t PROGMEM steno_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_BLUE} );
//const rgblight_segment_t PROGMEM kb_settings_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_CYAN} );
//const rgblight_segment_t PROGMEM teams_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_MAGENTA} );
//const rgblight_segment_t PROGMEM selection_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_YELLOW} );
//const rgblight_segment_t PROGMEM layers_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_WHITE} );
//const rgblight_segment_t PROGMEM media_light[] = RGBLIGHT_lAYER_SEGMENTS( {0, 9, RGB_PURPLE} );
//
//const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//    qwerty_light,
//    numpad_light,
//    steno_light,
//    kb_settings_light,
//    teams_light,
//    selection_light,
//    layers_light,
//    media_light
//);
//
//void keyboard_post_init_user(void) {
//    rgblight_layers = my_rgb_layers;
//}
