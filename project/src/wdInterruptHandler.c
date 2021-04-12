#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
char last_Switch = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if((++blink_count == 87) && (last_Switch == 0)){
    tune_one();
    blink_count = 0;
  }
  else if((blink_count == 50) && (last_Switch == 1)){
    tune_two();
    toggle_both();
    blink_count = 0;
  }
  else if((blink_count == 36) && (last_Switch == 2)){
    dim();
    blink_count = 0;
  }
  else if((blink_count == 125) && (last_Switch == 3)){
    buzzer_set_period(0);
    toggle_off();
    blink_count = 0;
  }
}
