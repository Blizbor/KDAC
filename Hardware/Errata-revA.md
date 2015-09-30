# Known issues in rev.A

1. MCK feedback routed to TIM1_ETR, but STM32's USB SOF signal is connected to TIM2 trigger input. 
   Timers can be configured in chain, so TIM2 event can be passed to TIM1. Another problem - TIM1 is 16-bit timer.

2. CS8416 AD2 pin left floated, AD0 & AD1 tied to DGND without any resistors. Also, it responses to address 0x14 (AD2 = VDD)

3. CS8416 SDOUT pin left floated, SDOUT pulled to 1 means SW mode, SDOUT pulled to 0 - HW mode. 
   Without resistor, CS8416 runs in HW mode in most of cases.
