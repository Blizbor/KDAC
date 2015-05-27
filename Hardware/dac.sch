EESchema Schematic File Version 2
LIBS:dac-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:dac
LIBS:Oscillators
LIBS:stm32
LIBS:logo
LIBS:dac-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title "KDAC - OpenSource USB Audio DAC"
Date "27.05.2015"
Rev "A"
Comp "Kosyak"
Comment1 "CC BY-SA"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74LS157 U1
U 1 1 554F7FFF
P 5600 2850
F 0 "U1" H 5650 3000 60  0000 C CNN
F 1 "74LS157" H 5650 2700 60  0000 C CNN
F 2 "" H 5600 2850 60  0000 C CNN
F 3 "" H 5600 2850 60  0000 C CNN
	1    5600 2850
	1    0    0    -1  
$EndComp
$Sheet
S 2750 2800 1000 1100
U 555100F5
F0 "MCU" 50
F1 "mcu.sch" 50
F2 "~RST" O R 3750 3600 50 
F3 "I2S_MCK" O R 3750 3200 50 
F4 "I2S_BCK" O R 3750 3000 50 
F5 "I2S_SD" O R 3750 2900 50 
F6 "I2S_LRCK" O R 3750 3100 50 
F7 "I2C_SCL" O R 3750 3800 50 
F8 "I2C_SDA" B R 3750 3700 50 
F9 "I2S_SEL" O R 3750 3300 50 
F10 "XO_EN" O R 3750 3500 50 
$EndSheet
$Sheet
S 6850 2400 1000 900 
U 55523198
F0 "DAC" 50
F1 "converter.sch" 50
F2 "I2S_SD" I L 6850 2500 50 
F3 "I2S_BCK" I L 6850 2600 50 
F4 "I2S_LRCK" I L 6850 2700 50 
F5 "I2S_MCK" I L 6850 2800 50 
F6 "~RST" I L 6850 3000 50 
F7 "SDA" B L 6850 3100 50 
F8 "SCL" I L 6850 3200 50 
$EndSheet
$Sheet
S 2750 1250 1000 1300
U 554DF9E3
F0 "SPDIF Receiver" 50
F1 "spdif.sch" 50
F2 "~RST" I R 3750 2250 50 
F3 "SCL" I R 3750 2450 50 
F4 "SDA" B R 3750 2350 50 
F5 "I2S_SD" O R 3750 1350 50 
F6 "I2S_BCK" O R 3750 1450 50 
F7 "I2S_LRCK" O R 3750 1550 50 
F8 "I2S_MCK" B R 3750 1650 50 
F9 "GPO0" O R 3750 1850 50 
F10 "GPO1" O R 3750 1950 50 
F11 "GPO2" O R 3750 2050 50 
$EndSheet
Wire Wire Line
	3750 1450 4450 1450
Wire Wire Line
	4450 1450 4450 2550
Wire Wire Line
	4450 2550 4850 2550
Wire Wire Line
	3750 1550 4350 1550
Wire Wire Line
	4350 1550 4350 2800
Wire Wire Line
	4350 2800 4850 2800
Wire Wire Line
	6350 2600 6850 2600
Wire Wire Line
	6450 2700 6450 2850
Wire Wire Line
	6450 2850 6350 2850
Wire Wire Line
	6350 2350 6450 2350
Wire Wire Line
	6450 2500 6850 2500
Wire Wire Line
	6450 2350 6450 2500
Wire Wire Line
	6450 2700 6850 2700
Wire Wire Line
	3750 2250 4250 2250
Wire Wire Line
	4250 2250 4250 3600
Wire Wire Line
	3750 3600 6450 3600
Wire Wire Line
	6450 3600 6450 3000
Wire Wire Line
	6450 3000 6850 3000
Wire Wire Line
	6550 3100 6850 3100
Wire Wire Line
	6550 3700 6550 3100
Wire Wire Line
	3750 3700 6550 3700
Wire Wire Line
	4150 3700 4150 2350
Wire Wire Line
	4150 2350 3750 2350
Wire Wire Line
	6650 3200 6850 3200
Wire Wire Line
	6650 3800 6650 3200
Wire Wire Line
	3750 3800 6650 3800
Wire Wire Line
	3750 2450 4050 2450
Wire Wire Line
	4050 2450 4050 3800
Wire Wire Line
	4850 2300 4550 2300
Wire Wire Line
	4550 2300 4550 1350
Wire Wire Line
	4550 1350 3750 1350
Wire Wire Line
	3750 2900 4550 2900
Wire Wire Line
	4550 2900 4550 2400
Wire Wire Line
	4550 2400 4850 2400
Wire Wire Line
	3750 3000 4650 3000
Wire Wire Line
	4650 3000 4650 2650
Wire Wire Line
	4650 2650 4850 2650
Wire Wire Line
	3750 3100 4750 3100
Wire Wire Line
	4750 3100 4750 2900
Wire Wire Line
	4750 2900 4850 2900
Wire Wire Line
	3750 3300 4850 3300
$Comp
L GNDD #PWR01
U 1 1 55561545
P 4800 3400
F 0 "#PWR01" H 4800 3150 50  0001 C CNN
F 1 "GNDD" H 4800 3250 50  0001 C CNN
F 2 "" H 4800 3400 60  0000 C CNN
F 3 "" H 4800 3400 60  0000 C CNN
	1    4800 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 3400 4850 3400
$Comp
L CONN_01X05 P1
U 1 1 5555D410
P 2900 4800
F 0 "P1" H 2900 5100 50  0000 C CNN
F 1 "ANALOG_POWER" H 2900 4500 50  0000 C CNN
F 2 "" H 2900 4800 60  0000 C CNN
F 3 "" H 2900 4800 60  0000 C CNN
	1    2900 4800
	-1   0    0    -1  
$EndComp
$Comp
L GNDA #PWR02
U 1 1 5555D417
P 3300 4800
F 0 "#PWR02" H 3300 4550 50  0001 C CNN
F 1 "GNDA" H 3300 4650 50  0001 C CNN
F 2 "" H 3300 4800 60  0000 C CNN
F 3 "" H 3300 4800 60  0000 C CNN
	1    3300 4800
	0    -1   -1   0   
$EndComp
$Comp
L +12V #PWR03
U 1 1 5555D41D
P 3300 4600
F 0 "#PWR03" H 3300 4450 50  0001 C CNN
F 1 "+12V" V 3300 4700 50  0000 L CNN
F 2 "" H 3300 4600 60  0000 C CNN
F 3 "" H 3300 4600 60  0000 C CNN
	1    3300 4600
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR04
U 1 1 5555D423
P 3300 4700
F 0 "#PWR04" H 3300 4550 50  0001 C CNN
F 1 "+5V" V 3300 4800 50  0000 L CNN
F 2 "" H 3300 4700 60  0000 C CNN
F 3 "" H 3300 4700 60  0000 C CNN
	1    3300 4700
	0    1    1    0   
$EndComp
$Comp
L -12V #PWR9
U 1 1 5555D429
P 3300 5000
F 0 "#PWR9" H 3300 5100 50  0001 C CNN
F 1 "-12V" V 3300 5100 50  0000 L CNN
F 2 "" H 3300 5000 60  0000 C CNN
F 3 "" H 3300 5000 60  0000 C CNN
	1    3300 5000
	0    1    1    0   
$EndComp
$Comp
L -5V #PWR8
U 1 1 5555D42F
P 3300 4900
F 0 "#PWR8" H 3300 5000 50  0001 C CNN
F 1 "-5V" V 3300 5050 50  0000 L CNN
F 2 "" H 3300 4900 60  0000 C CNN
F 3 "" H 3300 4900 60  0000 C CNN
	1    3300 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 4600 3300 4600
Wire Wire Line
	3300 4700 3100 4700
Wire Wire Line
	3100 4800 3300 4800
Wire Wire Line
	3300 4900 3100 4900
Wire Wire Line
	3100 5000 3300 5000
$Comp
L CONN_01X02 P2
U 1 1 5555D43A
P 2900 5400
F 0 "P2" H 2900 5550 50  0000 C CNN
F 1 "DIGITAL_POWER" H 2900 5250 50  0000 C CNN
F 2 "" H 2900 5400 60  0000 C CNN
F 3 "" H 2900 5400 60  0000 C CNN
	1    2900 5400
	-1   0    0    -1  
$EndComp
$Comp
L +3.3V #PWR05
U 1 1 5555D441
P 3300 5350
F 0 "#PWR05" H 3300 5200 50  0001 C CNN
F 1 "+3.3V" V 3300 5450 50  0000 L CNN
F 2 "" H 3300 5350 60  0000 C CNN
F 3 "" H 3300 5350 60  0000 C CNN
	1    3300 5350
	0    1    1    0   
$EndComp
$Comp
L GNDD #PWR06
U 1 1 5555D447
P 3300 5450
F 0 "#PWR06" H 3300 5200 50  0001 C CNN
F 1 "GNDD" H 3300 5300 50  0001 C CNN
F 2 "" H 3300 5450 60  0000 C CNN
F 3 "" H 3300 5450 60  0000 C CNN
	1    3300 5450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3100 5350 3300 5350
Wire Wire Line
	3100 5450 3300 5450
Wire Wire Line
	3750 3200 3950 3200
Wire Wire Line
	3950 1650 3950 3900
Wire Wire Line
	3950 3900 6750 3900
Wire Wire Line
	6750 3900 6750 2800
Wire Wire Line
	6750 2800 6850 2800
Wire Wire Line
	3750 1650 3950 1650
Connection ~ 3950 3200
$Comp
L XO U2
U 1 1 55561FA9
P 5500 4250
F 0 "U2" H 5500 4500 50  0000 C CNN
F 1 "49.152MHz" H 5500 4000 50  0000 C CNN
F 2 "" H 5500 4250 60  0000 C CNN
F 3 "" H 5500 4250 60  0000 C CNN
	1    5500 4250
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR07
U 1 1 55561FC1
P 4900 4150
F 0 "#PWR07" H 4900 4000 50  0001 C CNN
F 1 "+3.3V" V 4900 4400 50  0000 C CNN
F 2 "" H 4900 4150 60  0000 C CNN
F 3 "" H 4900 4150 60  0000 C CNN
	1    4900 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4900 4150 5100 4150
$Comp
L GNDD #PWR08
U 1 1 55561FCB
P 5950 4350
F 0 "#PWR08" H 5950 4100 50  0001 C CNN
F 1 "GNDD" H 5950 4200 50  0001 C CNN
F 2 "" H 5950 4350 60  0000 C CNN
F 3 "" H 5950 4350 60  0000 C CNN
	1    5950 4350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5900 4350 5950 4350
Wire Wire Line
	6000 4150 5900 4150
Wire Wire Line
	6000 3900 6000 4150
Connection ~ 6000 3900
Connection ~ 4250 3600
Connection ~ 4150 3700
Connection ~ 4050 3800
Wire Wire Line
	3750 3500 3850 3500
Wire Wire Line
	3850 3500 3850 4350
Wire Wire Line
	3850 4350 5100 4350
$Comp
L C C26
U 1 1 5557833E
P 5000 4600
F 0 "C26" H 5025 4700 50  0000 L CNN
F 1 "0.1µF" H 5025 4500 50  0000 L CNN
F 2 "" H 5038 4450 30  0000 C CNN
F 3 "" H 5000 4600 60  0000 C CNN
	1    5000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4450 5000 4150
Connection ~ 5000 4150
$Comp
L GNDD #PWR09
U 1 1 5557855F
P 5000 4800
F 0 "#PWR09" H 5000 4550 50  0001 C CNN
F 1 "GNDD" H 5000 4650 50  0001 C CNN
F 2 "" H 5000 4800 60  0000 C CNN
F 3 "" H 5000 4800 60  0000 C CNN
	1    5000 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4750 5000 4800
$Comp
L +3.3V #PWR010
U 1 1 5557F771
P 4000 5050
F 0 "#PWR010" H 4000 4900 50  0001 C CNN
F 1 "+3.3V" H 4000 5190 50  0000 C CNN
F 2 "" H 4000 5050 60  0000 C CNN
F 3 "" H 4000 5050 60  0000 C CNN
	1    4000 5050
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR011
U 1 1 5557F87E
P 4200 5050
F 0 "#PWR011" H 4200 4900 50  0001 C CNN
F 1 "VCC" H 4200 5200 50  0000 C CNN
F 2 "" H 4200 5050 60  0000 C CNN
F 3 "" H 4200 5050 60  0000 C CNN
	1    4200 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 5050 4000 5100
Wire Wire Line
	4000 5100 4200 5100
Wire Wire Line
	4200 5100 4200 5050
$EndSCHEMATC
