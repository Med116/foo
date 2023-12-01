#include QMK_KEYBOARD_H
#define HSV_VAL 145
#define HSV_NORTHERN_LIGHTS_PURPLE 189,56,145
#define HSV_NORTHERN_LIGHTS_GREEN 70,40,145
#define HSV_NORTHERN_LIGHTS_BLUE 189,56,145
#define HSV_NORTHERN_LIGHTS_YELLOW 123,67,145
#define HSV_DNKN_ORANGE 22,249,155
#define HSV_DNKN_MAJENTA 234,193,155

//default light layer
const rgblight_segment_t PROGMEM base_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    
	{0,1, HSV_MAGENTA },
	{16,1, HSV_MAGENTA },
	{32,1, HSV_MAGENTA },
	{48,8, HSV_MAGENTA },
	{13,1, HSV_MAGENTA },
	{28,1, HSV_MAGENTA },
	{43,1, HSV_MAGENTA },
	{1,12, 54, 255,145 },
	{17,11, 87, 255,145 },
	{33,10, 174, 255,145 },
	{56, 3, HSV_RED},
	{44, 1, HSV_RED},
    {14,2, HSV_GREEN},
	{45,3, HSV_GREEN},
	{29,3, HSV_GREEN},
	{59,5, HSV_GREEN}
);

//caps lock layer
const rgblight_segment_t PROGMEM caps_lock_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{16,1, HSV_GREEN },
	{1,10, HSV_RED },
	{17,9, HSV_RED},
	{33,7, HSV_RED}
	
);

const rgblight_segment_t PROGMEM fn_keys_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {14,2, HSV_RED},
	{45,3, HSV_RED},
	{29,3, HSV_RED},
	{59,5, HSV_RED},
	{56, 3, HSV_GREEN},
	{44, 1, HSV_GREEN}
	
);

const rgblight_segment_t PROGMEM dnkn_colors_layer_keys_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0,16, HSV_DNKN_ORANGE },
	{16,16, HSV_DNKN_ORANGE },
	{32,16, HSV_DNKN_MAJENTA },
	{48,16, HSV_DNKN_MAJENTA },
	// NUM PAD
	   // TOP ROW 7 8 9
	//{15,1, HSV_GREEN },
	//{//46,2, HSV_GREEN },
	   // MID ROW 4 5 6
	//{30,2, HSV_GREEN },
	//{63,1, HSV_GREEN },
	   // BOT ROW 1 2 3
	//{61,2, HSV_GREEN },
	//{45,1, HSV_GREEN },
	
	   // ARROWS
    {56, 3, HSV_CYAN},
	{44, 1, HSV_CYAN},
	// ALL RIGHT SIDE NUM PAD PLUS MINUS PLUS DEL
	{14,2, HSV_GREEN},
	{45,3, HSV_GREEN},
	{29,3, HSV_GREEN},
	{59,5, HSV_GREEN}
	
	
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM user_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	//base_light_layer,
	dnkn_colors_layer_keys_light_layer,
	fn_keys_light_layer,
	caps_lock_light_layer
	);
	

void keyboard_post_init_user(void) {
    rgblight_layers = user_rgb_layers;
    rgblight_set_layer_state(0, true);

}

enum layer_names {
    _BASE,
    _FN_KEY,
	_FN_NUMS
};

enum custom_keycodes {
  CODE_JAVA,
  SCREENSHOT,
  BACKTICKS_AROUND_CLIPBOARD,
  SEMI_COLON_RETURN,
  LBRACK,
  RBRACK,
  LPAR,
  RPAR,
  CAPS_TAB,
  ACTIVATE_DNKN_COLOR_LAYER,
  SPOTLIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LPAR, RPAR, KC_BSPC, KC_MINS, KC_7, KC_8,  KC_9, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_EQL, KC_4, KC_5, KC_6,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,KC_RSFT,   KC_UP,        KC_1, KC_2, KC_3, 
		KC_LCTL, KC_LALT, KC_LCMD, KC_HOME, MO(_FN_KEY), KC_BSLS,   KC_SPC, KC_END,       KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, KC_0
		
	),
	[_FN_KEY] = LAYOUT(
		KC_GRAVE, KC_Q, KC_W, KC_E, RCS(KC_R), RCS(KC_T), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, RGB_VAD, TG(_FN_NUMS), KC_1,  KC_2, 
		KC_CAPS, KC_A, LCMD(LSFT(KC_4)), KC_D, KC_F, KC_GRAVE, KC_H, CODE_JAVA, KC_K, LCMD(KC_L), KC_SCLN, KC_QUOT, SEMI_COLON_RETURN, KC_CALC, KC_4, KC_F5, KC_6,
		KC_CAPS, KC_SLEP, KC_X, KC_C, KC_V, BACKTICKS_AROUND_CLIPBOARD, KC_N, DM_REC1, DM_RSTP, DM_PLY1, SCREENSHOT ,KC_RSFT,   RGB_VAI,       KC_F1, KC_F2, KC_F3, 
		KC_CAPS, KC_LALT, SPOTLIGHT, KC_TILDE, KC_GRAVE, KC_ENT,   TG(_FN_NUMS), KC_GRAVE,       LCTL(KC_A), RGB_TOG, LCTL(KC_E), KC_INS, TG(_FN_NUMS)
			
		),
	[_FN_NUMS] = LAYOUT(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_MINS, KC_F7, KC_F8,  KC_F9, 
		KC_CAPS, KC_A, KC_S, KC_D, TG(_FN_NUMS), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_EQL, KC_F4, KC_F5, KC_F6,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,TG(_FN_NUMS),   KC_UP,        KC_F1, KC_F2, KC_F3, 
		KC_LCTL, KC_LALT, KC_LCMD, KC_TILDE, KC_GRAVE, KC_ENT,   TG(_FN_NUMS), KC_RCTL,       TG(_FN_NUMS), RGB_TOG, TG(_FN_NUMS), KC_F9, TG(_FN_NUMS)
		)
		
};

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN_NUMS));
    return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
  case CODE_JAVA:
    if (record->event.pressed) {
      SEND_STRING("```java");
	  SEND_STRING(SS_TAP(X_ENTER));		 		 
	  SEND_STRING(SS_LCTL("v"));
	  SEND_STRING(SS_TAP(X_ENTER));		
	  SEND_STRING("```");
    }
    return false;
   case SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCMD(SS_LSFT("s")));
        return false;
      }
      break;
   case BACKTICKS_AROUND_CLIPBOARD:
     
	   if (record->event.pressed) {
		SEND_STRING("`");
		SEND_STRING(SS_LCTL("v"));
		SEND_STRING("`");
		return false;
	   }
	break;
   case SEMI_COLON_RETURN:
	   if (record->event.pressed) {
		SEND_STRING(";");
		SEND_STRING(SS_TAP(X_ENTER));
		return false;
	   }
	break;
   case LBRACK:
	   if (record->event.pressed) {
		SEND_STRING("[");
		return false;
	   }
	break;
   case RBRACK:
	   if (record->event.pressed) {
		SEND_STRING("]");
		return false;
	   }
	break;
   case CAPS_TAB:
	   if (record->event.pressed) {
		bool caps_lock_on = host_keyboard_led_state().caps_lock;
		if (!caps_lock_on){
			SEND_STRING(SS_TAP(X_TAB));
		}else{
			SEND_STRING(SS_TAP(X_CAPS));
		}
		
		return false;
	   }
	break;
	case LPAR: 
	if (record->event.pressed) {
		 if (get_mods() & MOD_MASK_SHIFT) {
		  SEND_STRING("{");
		  return false;
        } else {
		  SEND_STRING("(");
		  return false;
        }
	}
	break;
	case RPAR: 
	if (record->event.pressed) {
		 if (get_mods() & MOD_MASK_SHIFT) {
		 SEND_STRING("}");
		 return false;
        } else {
		  SEND_STRING(")");
		  return false;
        }
	}
	break;
	case SPOTLIGHT: 
	if (record->event.pressed) {
         SEND_STRING(SS_LCMD(SS_TAP(X_SPC)));
	     return false;
        
	}
	break;
  }
  return true;				
  
}



