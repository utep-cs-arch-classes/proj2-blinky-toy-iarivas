#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  red_on = 1;
  green_on = 0;
  led_update();
  return led_changed;
}

char toggle_red_Max()
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 2;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  case 2:
    red_on = 1;
    state = 3;
    break;
  case 3:
    red_on = 1;
    state = 1;
    break;
  }
  led_update();
  return 1;
}

char toggle_green()
{
  green_on = 1;
  red_on = 0;
  led_update();
  return led_changed;
}


