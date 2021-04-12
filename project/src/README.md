## Blinky-Buzzy Toy

## Description:

This program transforms an MSP430 into a childs toy. So each button will have
a diffrent effect. 

## How to Compile / Run 

1. Make your way into to the src directory inside the projects directory
(proj2-blinky-toy-iarivas\project\src\). Once there you can type in "make all".
2. Next you can plug in your MSP430 into your computer and enter "make load".
So now whenever you plug in your MSP430 it will be loaded with this toy program.
3. When finished playing, to clean the src/ directory enter, "make clean".

## Buttons

On the MSP430 there are four buttons(s1, s2, s3, s4) each of which cause a diffrent reaction
when pressed.

* s1: This button will play twinkle twinkle little star and flash the red and
* green leds in tune.
* s2: This button will cause the red and green led to turn on an play an intro
* noise.
* s3: This button will cause the red and green leds to blink very fast and
* sounds a panic noise.
* s4: This button will turn off any tunes playing and turn both leds
 off. Leaving the toy in an idle state untill another button is pressed.









