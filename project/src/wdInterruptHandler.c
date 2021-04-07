#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
char last_Switch = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if ((++blink_count == 125) && (last_Switch == 0)) {
    toggle_red();
    buzzer_set_period(1000);
    blink_count = 0;
  }
  else if((++blink_count == 100) && (last_Switch == 1)){
    toggle_green();
    buzzer_set_period(0);
    blink_count = 0;
  }
}
