#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

static char r_state = 0;
static char g_state = 0;
static char Rdim = 0;
static char Gdim = 0;
static int i = 0;
static int j = 0;
int song[] = {3824,3840,2551,2570,2272,2290,2551,0,
	      2863,2880,3033,3060,3405,3420,3824,0,
	      2551,2570,2863,2880,3033,3060,3405,0,
	      2551,2570,2863,2880,3033,3060,3405,0,
	      3824,3840,2551,2570,2272,2290,2551,0,
	      2863,2880,3033,3060,3405,3420,3824,0};

int song2[] = {3824,3405,3033,2863,2551,2272,2026,0};

void toggle_red()		/* always toggle! */
{
  switch(r_state){
  case 0:
    red_on = 1;
    r_state = 1;
    break;
  case 1:
    red_on = 0;
    r_state = 0;
  }
  led_update();
}

void toggle_green()
{
  switch(g_state){
  case 0:
    green_on = 1;
    g_state = 1;
    break;
  case 1:
    green_on = 0;
    g_state = 0;
    break;
  }
  led_update();
}

char toggle_both()
{
  green_on = 1;
  red_on = 1;
  led_update();
  return led_changed;
}

void dim_r25()
{
  switch(r_state){
  case 0:
    red_on = 0;
    r_state = 1;
    break;
  case 1:
    red_on = 0;
    r_state = 2;
    break;
  case 2:
    red_on = 1;
    r_state = 0;
    break;
  }
  led_update();
}

void dim_r75()
{
  switch(r_state){
  case 0:
    red_on = 1;
    r_state = 1;
    break;
  case 1:
    red_on = 1;
    r_state = 2;
    break;
  case 2:
    red_on = 0;
    r_state = 0;
    break;
  }
  led_update();
}

void dim_red()
{
  switch(Rdim){           //Goes from 25%->50%->75%
  case 0:
    toggle_red();
    toggle_red();
    Rdim = 1;
    break;
  case 1:
    dim_r25();
    dim_r25();
    dim_r25();
    Rdim = 2;
    break;
  case 2:
    dim_r75();
    dim_r75();
    dim_r75();
    Rdim = 0;
    break;
  }
}

void dim_g25()
{
  switch(g_state){
  case 0:
    green_on = 0;
    g_state = 1;
    break;
  case 1:
    green_on = 0;
    g_state = 2;
    break;
  case 2:
    green_on = 1;
    g_state = 0;
    break;
  }
  led_update();
}

void dim_g75()
{
  switch(g_state){
  case 0:
    green_on = 1;
    g_state = 1;
    break;
  case 1:
    green_on = 1;
    g_state = 2;
    break;
  case 2:
    green_on = 0;
    g_state = 0;
    break;
  }
  led_update();
}

void dim_green()
{
  switch(Gdim){
  case 0:
    toggle_green();
    toggle_green();
    Gdim = 1;
    break;
  case 1:
    dim_g25();
    dim_g25();
    dim_g25();
    Gdim = 2;
    break;
  case 2:
    dim_g75();
    dim_g75();
    dim_g75();
    Gdim = 0;
    break;
  }
}

void dim()
{
  static char temp = 0;
  switch(temp){
  case 0:
    buzzer_set_period(5500);
    dim_red();
    temp = 1;
  case 1:
    buzzer_set_period(1000);
    dim_green();
    temp = 0;
  }
}


void tune_one()
{
  if(i == 48){ i = 0;}
  else if((i%2) == 0){
    buzzer_set_period(0);
    toggle_green();
  }
  if(song[i] != 0){
    toggle_red();
  }
  buzzer_set_period(song[i]);
  i++;
}

void tune_two()
{
  if(j == 9){ j == 0;}
  else if((j%2) == 0){buzzer_set_period(0);}
  buzzer_set_period(song2[j]);
  j++;
}

void toggle_off()
{
  green_on = 0;
  red_on = 0;
  g_state = 0;
  r_state = 0;
  i = 0;
  j = 0;
  led_update();
}

