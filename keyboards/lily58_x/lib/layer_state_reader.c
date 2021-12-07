
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58_x.h"

#define L_BASE 0
#define L_LOWER (1 << 1)
#define L_RAISE (1 << 2)
#define L_RGB (1 << 3)
#define L_GAMING (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_RGB:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RGB");
  case L_GAMING:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: GAMING");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }
  return layer_state_str;
}
