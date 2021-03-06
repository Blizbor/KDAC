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
$Descr A3 16535 11693
encoding utf-8
Sheet 2 4
Title "KDAC - OpenSource USB Audio DAC - Controller & USB"
Date "27.05.2015"
Rev "A"
Comp "Kosyak"
Comment1 "CC BY-SA"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +3.3V #PWR012
U 1 1 55510B16
P 9800 2150
F 0 "#PWR012" H 9800 2000 50  0001 C CNN
F 1 "+3.3V" H 9800 2290 50  0000 C CNN
F 2 "" H 9800 2150 60  0000 C CNN
F 3 "" H 9800 2150 60  0000 C CNN
	1    9800 2150
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR013
U 1 1 55510CAA
P 9600 8300
F 0 "#PWR013" H 9600 8050 50  0001 C CNN
F 1 "GNDD" H 9600 8150 50  0001 C CNN
F 2 "" H 9600 8300 60  0000 C CNN
F 3 "" H 9600 8300 60  0000 C CNN
	1    9600 8300
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR014
U 1 1 55510FEC
P 2800 4150
F 0 "#PWR014" H 2800 4000 50  0001 C CNN
F 1 "+3.3V" V 2800 4400 50  0000 C CNN
F 2 "" H 2800 4150 60  0000 C CNN
F 3 "" H 2800 4150 60  0000 C CNN
	1    2800 4150
	0    1    1    0   
$EndComp
$Comp
L C C7
U 1 1 55511067
P 5050 1500
F 0 "C7" H 5075 1600 50  0000 L CNN
F 1 "0.1µF" H 5075 1400 50  0000 L CNN
F 2 "" H 5088 1350 30  0000 C CNN
F 3 "" H 5050 1500 60  0000 C CNN
	1    5050 1500
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 5551111F
P 5300 1500
F 0 "C8" H 5325 1600 50  0000 L CNN
F 1 "0.1µF" H 5325 1400 50  0000 L CNN
F 2 "" H 5338 1350 30  0000 C CNN
F 3 "" H 5300 1500 60  0000 C CNN
	1    5300 1500
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 5551113F
P 5550 1500
F 0 "C9" H 5575 1600 50  0000 L CNN
F 1 "0.1µF" H 5575 1400 50  0000 L CNN
F 2 "" H 5588 1350 30  0000 C CNN
F 3 "" H 5550 1500 60  0000 C CNN
	1    5550 1500
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 55511179
P 5800 1500
F 0 "C10" H 5825 1600 50  0000 L CNN
F 1 "0.1µF" H 5825 1400 50  0000 L CNN
F 2 "" H 5838 1350 30  0000 C CNN
F 3 "" H 5800 1500 60  0000 C CNN
	1    5800 1500
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 555111A5
P 6050 1500
F 0 "C11" H 6075 1600 50  0000 L CNN
F 1 "0.1µF" H 6075 1400 50  0000 L CNN
F 2 "" H 6088 1350 30  0000 C CNN
F 3 "" H 6050 1500 60  0000 C CNN
	1    6050 1500
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 555111CB
P 6300 1500
F 0 "C12" H 6325 1600 50  0000 L CNN
F 1 "0.1µF" H 6325 1400 50  0000 L CNN
F 2 "" H 6338 1350 30  0000 C CNN
F 3 "" H 6300 1500 60  0000 C CNN
	1    6300 1500
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 555111F3
P 6550 1500
F 0 "C13" H 6575 1600 50  0000 L CNN
F 1 "0.1µF" H 6575 1400 50  0000 L CNN
F 2 "" H 6588 1350 30  0000 C CNN
F 3 "" H 6550 1500 60  0000 C CNN
	1    6550 1500
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 555114D6
P 4750 1500
F 0 "C6" H 4775 1600 50  0000 L CNN
F 1 "4.7µF" H 4775 1400 50  0000 L CNN
F 2 "" H 4788 1350 30  0000 C CNN
F 3 "" H 4750 1500 60  0000 C CNN
	1    4750 1500
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 555116D0
P 5300 3550
F 0 "C15" V 5350 3600 50  0000 L CNN
F 1 "4.7µF" V 5350 3500 50  0000 R CNN
F 2 "" H 5338 3400 30  0000 C CNN
F 3 "" H 5300 3550 60  0000 C CNN
	1    5300 3550
	0    -1   -1   0   
$EndComp
$Comp
L C C16
U 1 1 555119C2
P 5300 3750
F 0 "C16" V 5350 3800 50  0000 L CNN
F 1 "4.7µF" V 5350 3700 50  0000 R CNN
F 2 "" H 5338 3600 30  0000 C CNN
F 3 "" H 5300 3750 60  0000 C CNN
	1    5300 3750
	0    -1   -1   0   
$EndComp
$Comp
L GNDD #PWR015
U 1 1 55511C3B
P 5100 3800
F 0 "#PWR015" H 5100 3550 50  0001 C CNN
F 1 "GNDD" H 5100 3650 50  0001 C CNN
F 2 "" H 5100 3800 60  0000 C CNN
F 3 "" H 5100 3800 60  0000 C CNN
	1    5100 3800
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 55511CE3
P 4700 4250
F 0 "Y1" H 4700 4400 50  0000 C CNN
F 1 "12MHz" H 4700 4100 50  0000 C CNN
F 2 "" H 4700 4250 60  0000 C CNN
F 3 "" H 4700 4250 60  0000 C CNN
	1    4700 4250
	1    0    0    -1  
$EndComp
$Comp
L C C17
U 1 1 55511FA3
P 4450 4500
F 0 "C17" H 4400 4600 50  0000 R CNN
F 1 "22pF" H 4400 4400 50  0000 R CNN
F 2 "" H 4488 4350 30  0000 C CNN
F 3 "" H 4450 4500 60  0000 C CNN
	1    4450 4500
	1    0    0    -1  
$EndComp
$Comp
L C C18
U 1 1 555120A8
P 4900 4500
F 0 "C18" H 4925 4600 50  0000 L CNN
F 1 "22pF" H 4925 4400 50  0000 L CNN
F 2 "" H 4938 4350 30  0000 C CNN
F 3 "" H 4900 4500 60  0000 C CNN
	1    4900 4500
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR016
U 1 1 555122FD
P 4450 4700
F 0 "#PWR016" H 4450 4450 50  0001 C CNN
F 1 "GNDD" H 4450 4550 50  0001 C CNN
F 2 "" H 4450 4700 60  0000 C CNN
F 3 "" H 4450 4700 60  0000 C CNN
	1    4450 4700
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR017
U 1 1 55512324
P 4900 4700
F 0 "#PWR017" H 4900 4450 50  0001 C CNN
F 1 "GNDD" H 4900 4550 50  0001 C CNN
F 2 "" H 4900 4700 60  0000 C CNN
F 3 "" H 4900 4700 60  0000 C CNN
	1    4900 4700
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR018
U 1 1 555128B0
P 5800 1250
F 0 "#PWR018" H 5800 1100 50  0001 C CNN
F 1 "+3.3V" H 5800 1390 50  0000 C CNN
F 2 "" H 5800 1250 60  0000 C CNN
F 3 "" H 5800 1250 60  0000 C CNN
	1    5800 1250
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR019
U 1 1 55512A61
P 5800 1750
F 0 "#PWR019" H 5800 1500 50  0001 C CNN
F 1 "GNDD" H 5800 1600 50  0001 C CNN
F 2 "" H 5800 1750 60  0000 C CNN
F 3 "" H 5800 1750 60  0000 C CNN
	1    5800 1750
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 55512B68
P 6850 1500
F 0 "C14" H 6875 1600 50  0000 L CNN
F 1 "4.7µF" H 6875 1400 50  0000 L CNN
F 2 "" H 6888 1350 30  0000 C CNN
F 3 "" H 6850 1500 60  0000 C CNN
	1    6850 1500
	1    0    0    -1  
$EndComp
Text HLabel 5000 2650 0    50   Output ~ 0
~RST
Text Label 5400 2750 0    50   ~ 0
NRST
$Comp
L CONN_01X04 P4
U 1 1 5551394B
P 4250 5900
F 0 "P4" H 4250 6150 50  0000 C CNN
F 1 "SWDIO" H 4250 5650 50  0000 C CNN
F 2 "" H 4250 5900 60  0000 C CNN
F 3 "" H 4250 5900 60  0000 C CNN
	1    4250 5900
	-1   0    0    -1  
$EndComp
Text Label 4650 5950 2    50   ~ 0
NRST
$Comp
L GNDD #PWR020
U 1 1 55513E79
P 4600 6050
F 0 "#PWR020" H 4600 5800 50  0001 C CNN
F 1 "GNDD" H 4600 5900 50  0001 C CNN
F 2 "" H 4600 6050 60  0000 C CNN
F 3 "" H 4600 6050 60  0000 C CNN
	1    4600 6050
	0    -1   -1   0   
$EndComp
$Comp
L R R7
U 1 1 55514295
P 1800 8800
F 0 "R7" V 1900 8850 50  0000 L CNN
F 1 "1k" V 1900 8750 50  0000 R CNN
F 2 "" V 1730 8800 30  0000 C CNN
F 3 "" H 1800 8800 30  0000 C CNN
	1    1800 8800
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR021
U 1 1 5551450C
P 5100 2200
F 0 "#PWR021" H 5100 2050 50  0001 C CNN
F 1 "+3.3V" H 5100 2340 50  0000 C CNN
F 2 "" H 5100 2200 60  0000 C CNN
F 3 "" H 5100 2200 60  0000 C CNN
	1    5100 2200
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 55514812
P 4250 2950
F 0 "SW2" H 4050 3050 50  0000 C CNN
F 1 "BOOT" H 4450 3050 50  0000 C CNN
F 2 "" H 4250 2950 60  0000 C CNN
F 3 "" H 4250 2950 60  0000 C CNN
	1    4250 2950
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 55514A4E
P 4750 3150
F 0 "R2" H 4800 3200 50  0000 L CNN
F 1 "4.7k" H 4800 3100 50  0000 L CNN
F 2 "" V 4680 3150 30  0000 C CNN
F 3 "" H 4750 3150 30  0000 C CNN
	1    4750 3150
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR022
U 1 1 555151A6
P 4750 3350
F 0 "#PWR022" H 4750 3100 50  0001 C CNN
F 1 "GNDD" H 4750 3200 50  0001 C CNN
F 2 "" H 4750 3350 60  0000 C CNN
F 3 "" H 4750 3350 60  0000 C CNN
	1    4750 3350
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR023
U 1 1 5551523F
P 3850 2950
F 0 "#PWR023" H 3850 2800 50  0001 C CNN
F 1 "+3.3V" V 3850 3200 50  0000 C CNN
F 2 "" H 3850 2950 60  0000 C CNN
F 3 "" H 3850 2950 60  0000 C CNN
	1    3850 2950
	0    -1   -1   0   
$EndComp
$Comp
L USB3300 U4
U 1 1 555164D2
P 3700 9500
F 0 "U4" H 3700 9550 50  0000 C CNN
F 1 "USB3300" H 3700 9450 50  0000 C CNN
F 2 "" H 3700 9500 60  0000 C CNN
F 3 "" H 3700 9500 60  0000 C CNN
	1    3700 9500
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 55517E92
P 3900 1500
F 0 "C3" H 3925 1600 50  0000 L CNN
F 1 "0.1µF" H 3925 1400 50  0000 L CNN
F 2 "" H 3938 1350 30  0000 C CNN
F 3 "" H 3900 1500 60  0000 C CNN
	1    3900 1500
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 55517F12
P 4150 1500
F 0 "C4" H 4175 1600 50  0000 L CNN
F 1 "0.1µF" H 4175 1400 50  0000 L CNN
F 2 "" H 4188 1350 30  0000 C CNN
F 3 "" H 4150 1500 60  0000 C CNN
	1    4150 1500
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 55517F8C
P 4400 1500
F 0 "C5" H 4425 1600 50  0000 L CNN
F 1 "0.1µF" H 4425 1400 50  0000 L CNN
F 2 "" H 4438 1350 30  0000 C CNN
F 3 "" H 4400 1500 60  0000 C CNN
	1    4400 1500
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 55517FF4
P 3350 1500
F 0 "C1" H 3375 1600 50  0000 L CNN
F 1 "4.7µF" H 3375 1400 50  0000 L CNN
F 2 "" H 3388 1350 30  0000 C CNN
F 3 "" H 3350 1500 60  0000 C CNN
	1    3350 1500
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR024
U 1 1 5551807C
P 4150 1250
F 0 "#PWR024" H 4150 1100 50  0001 C CNN
F 1 "+3.3V" H 4150 1390 50  0000 C CNN
F 2 "" H 4150 1250 60  0000 C CNN
F 3 "" H 4150 1250 60  0000 C CNN
	1    4150 1250
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR025
U 1 1 555180B9
P 4150 1750
F 0 "#PWR025" H 4150 1500 50  0001 C CNN
F 1 "GNDD" H 4150 1600 50  0001 C CNN
F 2 "" H 4150 1750 60  0000 C CNN
F 3 "" H 4150 1750 60  0000 C CNN
	1    4150 1750
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR026
U 1 1 5551897B
P 3700 8300
F 0 "#PWR026" H 3700 8150 50  0001 C CNN
F 1 "+3.3V" H 3700 8440 50  0000 C CNN
F 2 "" H 3700 8300 60  0000 C CNN
F 3 "" H 3700 8300 60  0000 C CNN
	1    3700 8300
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR027
U 1 1 55518D9A
P 3700 10700
F 0 "#PWR027" H 3700 10450 50  0001 C CNN
F 1 "GNDD" H 3700 10550 50  0001 C CNN
F 2 "" H 3700 10700 60  0000 C CNN
F 3 "" H 3700 10700 60  0000 C CNN
	1    3700 10700
	1    0    0    -1  
$EndComp
$Comp
L USB_OTG P7
U 1 1 5551921E
P 1150 9000
F 0 "P7" H 1475 8875 50  0000 C CNN
F 1 "USB_OTG" H 1150 9200 50  0000 C CNN
F 2 "" V 1100 8900 60  0000 C CNN
F 3 "" V 1100 8900 60  0000 C CNN
	1    1150 9000
	0    -1   1    0   
$EndComp
$Comp
L GNDD #PWR028
U 1 1 55519EE0
P 1050 9450
F 0 "#PWR028" H 1050 9200 50  0001 C CNN
F 1 "GNDD" H 1050 9300 50  0001 C CNN
F 2 "" H 1050 9450 60  0000 C CNN
F 3 "" H 1050 9450 60  0000 C CNN
	1    1050 9450
	1    0    0    -1  
$EndComp
Text Label 4850 9100 2    50   ~ 0
ULPI_D7
Text Label 4850 9200 2    50   ~ 0
ULPI_D6
Text Label 4850 9300 2    50   ~ 0
ULPI_D5
Text Label 5200 7250 0    50   ~ 0
ULPI_D4
Text Label 4850 9500 2    50   ~ 0
ULPI_D3
Text Label 4850 9600 2    50   ~ 0
ULPI_D2
Text Label 4850 9700 2    50   ~ 0
ULPI_D1
Text Label 4850 9800 2    50   ~ 0
ULPI_D0
Text Label 4850 9900 2    50   ~ 0
ULPI_NXT
Text Label 4850 10000 2    50   ~ 0
ULPI_DIR
Text Label 4850 10100 2    50   ~ 0
ULPI_STP
Text Label 4850 10200 2    50   ~ 0
ULPI_CLK
Text Label 5200 6650 0    50   ~ 0
ULPI_D7
Text Label 4850 9400 2    50   ~ 0
ULPI_D4
Text Label 5200 7350 0    50   ~ 0
ULPI_D5
Text Label 5200 7450 0    50   ~ 0
ULPI_D6
Text Label 5200 4750 0    50   ~ 0
ULPI_D0
Text Label 5200 4950 0    50   ~ 0
ULPI_CLK
Text Label 5200 6150 0    50   ~ 0
ULPI_D1
Text Label 5200 6250 0    50   ~ 0
ULPI_D2
Text Label 5200 7150 0    50   ~ 0
ULPI_D3
Text Label 13950 6450 2    50   ~ 0
ULPI_NXT
Text Label 13950 6350 2    50   ~ 0
ULPI_DIR
Text Label 13950 6150 2    50   ~ 0
ULPI_STP
$Comp
L C C23
U 1 1 5553C08B
P 1600 9350
F 0 "C23" H 1625 9450 50  0000 L CNN
F 1 "4.7µF" H 1625 9250 50  0000 L CNN
F 2 "" H 1638 9200 30  0000 C CNN
F 3 "" H 1600 9350 60  0000 C CNN
	1    1600 9350
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR029
U 1 1 5553C5FF
P 1450 9600
F 0 "#PWR029" H 1450 9350 50  0001 C CNN
F 1 "GNDD" H 1450 9450 50  0001 C CNN
F 2 "" H 1450 9600 60  0000 C CNN
F 3 "" H 1450 9600 60  0000 C CNN
	1    1450 9600
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y2
U 1 1 5553D063
P 2100 9500
F 0 "Y2" H 1950 9600 50  0000 C CNN
F 1 "12MHz" H 2300 9600 50  0000 C CNN
F 2 "" H 2100 9500 60  0000 C CNN
F 3 "" H 2100 9500 60  0000 C CNN
	1    2100 9500
	1    0    0    -1  
$EndComp
$Comp
L C C24
U 1 1 5553D86E
P 1900 10000
F 0 "C24" H 1850 10100 50  0000 R CNN
F 1 "22pF" H 1850 9900 50  0000 R CNN
F 2 "" H 1938 9850 30  0000 C CNN
F 3 "" H 1900 10000 60  0000 C CNN
	1    1900 10000
	1    0    0    -1  
$EndComp
$Comp
L C C25
U 1 1 5553DC88
P 2300 10000
F 0 "C25" H 2325 10100 50  0000 L CNN
F 1 "22pF" H 2325 9900 50  0000 L CNN
F 2 "" H 2338 9850 30  0000 C CNN
F 3 "" H 2300 10000 60  0000 C CNN
	1    2300 10000
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR030
U 1 1 5553E21E
P 1900 10200
F 0 "#PWR030" H 1900 9950 50  0001 C CNN
F 1 "GNDD" H 1900 10050 50  0001 C CNN
F 2 "" H 1900 10200 60  0000 C CNN
F 3 "" H 1900 10200 60  0000 C CNN
	1    1900 10200
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR031
U 1 1 5553E2BF
P 2300 10200
F 0 "#PWR031" H 2300 9950 50  0001 C CNN
F 1 "GNDD" H 2300 10050 50  0001 C CNN
F 2 "" H 2300 10200 60  0000 C CNN
F 3 "" H 2300 10200 60  0000 C CNN
	1    2300 10200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR032
U 1 1 5553EC09
P 2850 10000
F 0 "#PWR032" H 2850 9850 50  0001 C CNN
F 1 "+3.3V" V 2850 10250 50  0000 C CNN
F 2 "" H 2850 10000 60  0000 C CNN
F 3 "" H 2850 10000 60  0000 C CNN
	1    2850 10000
	0    -1   -1   0   
$EndComp
$Comp
L R R8
U 1 1 55540674
P 2100 9700
F 0 "R8" V 2000 9750 50  0000 L CNN
F 1 "1M" V 2000 9650 50  0000 R CNN
F 2 "" V 2030 9700 30  0000 C CNN
F 3 "" H 2100 9700 30  0000 C CNN
	1    2100 9700
	0    -1   -1   0   
$EndComp
$Comp
L R R9
U 1 1 555415AE
P 2800 10450
F 0 "R9" H 2850 10500 50  0000 L CNN
F 1 "12k" H 2850 10400 50  0000 L CNN
F 2 "" V 2730 10450 30  0000 C CNN
F 3 "" H 2800 10450 30  0000 C CNN
	1    2800 10450
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR033
U 1 1 5554193F
P 2800 10700
F 0 "#PWR033" H 2800 10450 50  0001 C CNN
F 1 "GNDD" H 2800 10550 50  0001 C CNN
F 2 "" H 2800 10700 60  0000 C CNN
F 3 "" H 2800 10700 60  0000 C CNN
	1    2800 10700
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 555422D1
P 3650 1500
F 0 "C2" H 3675 1600 50  0000 L CNN
F 1 "0.1µF" H 3675 1400 50  0000 L CNN
F 2 "" H 3688 1350 30  0000 C CNN
F 3 "" H 3650 1500 60  0000 C CNN
	1    3650 1500
	1    0    0    -1  
$EndComp
$Comp
L C C19
U 1 1 55543773
P 4850 8300
F 0 "C19" V 4800 8250 50  0000 R CNN
F 1 "4.7µF" V 4800 8350 50  0000 L CNN
F 2 "" H 4888 8150 30  0000 C CNN
F 3 "" H 4850 8300 60  0000 C CNN
	1    4850 8300
	0    1    1    0   
$EndComp
$Comp
L C C20
U 1 1 5554406D
P 4850 8500
F 0 "C20" V 4800 8450 50  0000 R CNN
F 1 "0.1µF" V 4800 8550 50  0000 L CNN
F 2 "" H 4888 8350 30  0000 C CNN
F 3 "" H 4850 8500 60  0000 C CNN
	1    4850 8500
	0    1    1    0   
$EndComp
$Comp
L C C21
U 1 1 55544262
P 4850 8700
F 0 "C21" V 4800 8650 50  0000 R CNN
F 1 "4.7µF" V 4800 8750 50  0000 L CNN
F 2 "" H 4888 8550 30  0000 C CNN
F 3 "" H 4850 8700 60  0000 C CNN
	1    4850 8700
	0    1    1    0   
$EndComp
$Comp
L C C22
U 1 1 55544268
P 4850 8900
F 0 "C22" V 4800 8850 50  0000 R CNN
F 1 "0.1µF" V 4800 8950 50  0000 L CNN
F 2 "" H 4888 8750 30  0000 C CNN
F 3 "" H 4850 8900 60  0000 C CNN
	1    4850 8900
	0    1    1    0   
$EndComp
$Comp
L GNDD #PWR034
U 1 1 55544FC4
P 5150 9000
F 0 "#PWR034" H 5150 8750 50  0001 C CNN
F 1 "GNDD" H 5150 8850 50  0001 C CNN
F 2 "" H 5150 9000 60  0000 C CNN
F 3 "" H 5150 9000 60  0000 C CNN
	1    5150 9000
	1    0    0    -1  
$EndComp
Text HLabel 14150 7050 2    50   Input ~ 0
I2S_MCK
Text HLabel 14150 7150 2    50   Output ~ 0
I2S_BCK
Text HLabel 14150 7350 2    50   Output ~ 0
I2S_SD
Text HLabel 5250 5950 0    50   Output ~ 0
I2S_LRCK
Text HLabel 3150 6950 0    50   Output ~ 0
I2C_SCL
Text HLabel 3150 7050 0    50   BiDi ~ 0
I2C_SDA
$Comp
L R R3
U 1 1 5554B892
P 3400 6750
F 0 "R3" H 3450 6800 50  0000 L CNN
F 1 "4.7k" H 3450 6700 50  0000 L CNN
F 2 "" V 3330 6750 30  0000 C CNN
F 3 "" H 3400 6750 30  0000 C CNN
	1    3400 6750
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5554BAD3
P 3700 6750
F 0 "R4" H 3750 6800 50  0000 L CNN
F 1 "4.7k" H 3750 6700 50  0000 L CNN
F 2 "" V 3630 6750 30  0000 C CNN
F 3 "" H 3700 6750 30  0000 C CNN
	1    3700 6750
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR035
U 1 1 5554C0E3
P 3550 6500
F 0 "#PWR035" H 3550 6350 50  0001 C CNN
F 1 "+3.3V" H 3550 6640 50  0000 C CNN
F 2 "" H 3550 6500 60  0000 C CNN
F 3 "" H 3550 6500 60  0000 C CNN
	1    3550 6500
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P5
U 1 1 5554C74C
P 4250 6750
F 0 "P5" H 4250 6550 50  0000 C CNN
F 1 "UART" H 4400 6750 50  0000 C CNN
F 2 "" H 4250 6750 60  0000 C CNN
F 3 "" H 4250 6750 60  0000 C CNN
	1    4250 6750
	-1   0    0    1   
$EndComp
$Comp
L GNDD #PWR036
U 1 1 5554D157
P 4600 6650
F 0 "#PWR036" H 4600 6400 50  0001 C CNN
F 1 "GNDD" H 4600 6500 50  0001 C CNN
F 2 "" H 4600 6650 60  0000 C CNN
F 3 "" H 4600 6650 60  0000 C CNN
	1    4600 6650
	0    -1   -1   0   
$EndComp
$Comp
L SD_Card CON1
U 1 1 5554EA85
P 1800 4150
F 0 "CON1" H 1150 4700 50  0000 C CNN
F 1 "SD_Card" H 2400 3600 50  0000 C CNN
F 2 "10067847-001" H 2000 4500 50  0000 C CNN
F 3 "" H 1800 4150 60  0000 C CNN
	1    1800 4150
	-1   0    0    1   
$EndComp
$Comp
L GNDD #PWR037
U 1 1 5554F8F1
P 800 3950
F 0 "#PWR037" H 800 3700 50  0001 C CNN
F 1 "GNDD" H 800 3800 50  0001 C CNN
F 2 "" H 800 3950 60  0000 C CNN
F 3 "" H 800 3950 60  0000 C CNN
	1    800  3950
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5554FE22
P 5100 2400
F 0 "R1" H 5150 2450 50  0000 L CNN
F 1 "4.7k" H 5150 2350 50  0000 L CNN
F 2 "" V 5030 2400 30  0000 C CNN
F 3 "" H 5100 2400 30  0000 C CNN
	1    5100 2400
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR038
U 1 1 555506FB
P 2800 4250
F 0 "#PWR038" H 2800 4000 50  0001 C CNN
F 1 "GNDD" H 2800 4100 50  0001 C CNN
F 2 "" H 2800 4250 60  0000 C CNN
F 3 "" H 2800 4250 60  0000 C CNN
	1    2800 4250
	0    -1   -1   0   
$EndComp
$Comp
L GNDD #PWR039
U 1 1 55550862
P 2800 3950
F 0 "#PWR039" H 2800 3700 50  0001 C CNN
F 1 "GNDD" H 2800 3800 50  0001 C CNN
F 2 "" H 2800 3950 60  0000 C CNN
F 3 "" H 2800 3950 60  0000 C CNN
	1    2800 3950
	0    -1   -1   0   
$EndComp
Text Label 3250 4450 2    50   ~ 0
SPI_CS
Text Label 5200 5050 0    50   ~ 0
SPI_MISO
Text Label 5200 5150 0    50   ~ 0
SPI_MOSI
Text Label 5200 6450 0    50   ~ 0
SPI_SCK
Text Label 3250 4050 2    50   ~ 0
SPI_SCK
Text Label 3250 3850 2    50   ~ 0
SPI_MISO
Text Label 3250 4350 2    50   ~ 0
SPI_MOSI
Text Label 5200 4850 0    50   ~ 0
SPI_CS
Text Label 5200 4650 0    50   ~ 0
CARD
Text Label 700  4350 0    50   ~ 0
CARD
$Comp
L +3.3V #PWR040
U 1 1 55555101
P 5250 3350
F 0 "#PWR040" H 5250 3200 50  0001 C CNN
F 1 "+3.3V" V 5250 3600 50  0000 C CNN
F 2 "" H 5250 3350 60  0000 C CNN
F 3 "" H 5250 3350 60  0000 C CNN
	1    5250 3350
	0    -1   -1   0   
$EndComp
$Comp
L STM32F407VE U1
U 1 1 5555D44C
P 9600 5250
AR Path="/5555D44C" Ref="U1"  Part="1" 
AR Path="/555100F5/5555D44C" Ref="U3"  Part="1" 
F 0 "U3" H 5800 8050 50  0000 C CNN
F 1 "STM32F407VE" H 13200 2450 50  0000 C CNN
F 2 "LQFP-100" H 9650 5250 50  0000 C CNN
F 3 "" H 9600 5250 60  0000 C CNN
	1    9600 5250
	1    0    0    -1  
$EndComp
Text HLabel 14150 7250 2    50   Output ~ 0
I2S_SEL
$Comp
L R R5
U 1 1 5555DFAE
P 13750 7600
F 0 "R5" H 13800 7650 50  0000 L CNN
F 1 "4.7k" H 13800 7550 50  0000 L CNN
F 2 "" V 13680 7600 30  0000 C CNN
F 3 "" H 13750 7600 30  0000 C CNN
	1    13750 7600
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR041
U 1 1 5555E97A
P 13750 7850
F 0 "#PWR041" H 13750 7600 50  0001 C CNN
F 1 "GNDD" H 13750 7700 50  0001 C CNN
F 2 "" H 13750 7850 60  0000 C CNN
F 3 "" H 13750 7850 60  0000 C CNN
	1    13750 7850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P3
U 1 1 55564F07
P 14250 5800
F 0 "P3" H 14250 6050 50  0000 C CNN
F 1 "ENCODER" H 14250 5550 50  0000 C CNN
F 2 "" H 14250 5800 60  0000 C CNN
F 3 "" H 14250 5800 60  0000 C CNN
	1    14250 5800
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR042
U 1 1 5556596E
P 14000 5950
F 0 "#PWR042" H 14000 5700 50  0001 C CNN
F 1 "GNDD" H 14000 5800 50  0001 C CNN
F 2 "" H 14000 5950 60  0000 C CNN
F 3 "" H 14000 5950 60  0000 C CNN
	1    14000 5950
	0    1    1    0   
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 555662E5
P 4250 2750
F 0 "SW1" H 4050 2850 50  0000 C CNN
F 1 "RESET" H 4450 2850 50  0000 C CNN
F 2 "" H 4250 2750 60  0000 C CNN
F 3 "" H 4250 2750 60  0000 C CNN
	1    4250 2750
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR043
U 1 1 555676C9
P 3850 2750
F 0 "#PWR043" H 3850 2500 50  0001 C CNN
F 1 "GNDD" H 3850 2600 50  0001 C CNN
F 2 "" H 3850 2750 60  0000 C CNN
F 3 "" H 3850 2750 60  0000 C CNN
	1    3850 2750
	0    1    1    0   
$EndComp
$Comp
L CONN_01X04 P6
U 1 1 55556EC7
P 4250 7450
F 0 "P6" H 4250 7700 50  0000 C CNN
F 1 "OLED" H 4250 7200 50  0000 C CNN
F 2 "" H 4250 7450 60  0000 C CNN
F 3 "" H 4250 7450 60  0000 C CNN
	1    4250 7450
	-1   0    0    -1  
$EndComp
$Comp
L +3.3V #PWR044
U 1 1 55557772
P 4700 7300
F 0 "#PWR044" H 4700 7150 50  0001 C CNN
F 1 "+3.3V" V 4700 7400 50  0000 L CNN
F 2 "" H 4700 7300 60  0000 C CNN
F 3 "" H 4700 7300 60  0000 C CNN
	1    4700 7300
	0    1    1    0   
$EndComp
$Comp
L GNDD #PWR045
U 1 1 55557F2C
P 4700 7400
F 0 "#PWR045" H 4700 7150 50  0001 C CNN
F 1 "GNDD" H 4700 7250 50  0001 C CNN
F 2 "" H 4700 7400 60  0000 C CNN
F 3 "" H 4700 7400 60  0000 C CNN
	1    4700 7400
	0    -1   -1   0   
$EndComp
Text HLabel 14150 6950 2    50   Input ~ 0
XO_EN
$Comp
L R R6
U 1 1 555652AD
P 14050 7600
F 0 "R6" H 14100 7650 50  0000 L CNN
F 1 "4.7k" H 14100 7550 50  0000 L CNN
F 2 "" V 13980 7600 30  0000 C CNN
F 3 "" H 14050 7600 30  0000 C CNN
	1    14050 7600
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR046
U 1 1 55565519
P 14050 7850
F 0 "#PWR046" H 14050 7600 50  0001 C CNN
F 1 "GNDD" H 14050 7700 50  0001 C CNN
F 2 "" H 14050 7850 60  0000 C CNN
F 3 "" H 14050 7850 60  0000 C CNN
	1    14050 7850
	1    0    0    -1  
$EndComp
Text Label 2150 8900 0    50   ~ 0
D_N
Text Label 2150 9000 0    50   ~ 0
D_P
Text Label 13750 7050 0    50   ~ 0
MCK
Text Label 5200 5650 0    50   ~ 0
MCK
Wire Wire Line
	9000 2350 9000 2250
Wire Wire Line
	9000 2250 10300 2250
Wire Wire Line
	10300 2250 10300 2350
Wire Wire Line
	10000 2350 10000 2250
Connection ~ 10000 2250
Wire Wire Line
	9800 2150 9800 2350
Connection ~ 9800 2250
Wire Wire Line
	9600 2350 9600 2250
Connection ~ 9600 2250
Wire Wire Line
	9400 2350 9400 2250
Connection ~ 9400 2250
Wire Wire Line
	9200 2350 9200 2250
Connection ~ 9200 2250
Wire Wire Line
	9200 8150 9200 8250
Wire Wire Line
	9200 8250 10100 8250
Wire Wire Line
	10100 8250 10100 8150
Wire Wire Line
	9800 8150 9800 8250
Connection ~ 9800 8250
Wire Wire Line
	9600 8150 9600 8300
Connection ~ 9600 8250
Wire Wire Line
	9400 8150 9400 8250
Connection ~ 9400 8250
Wire Wire Line
	5250 3350 5600 3350
Wire Wire Line
	5050 1350 5050 1300
Wire Wire Line
	4750 1300 6850 1300
Wire Wire Line
	6550 1300 6550 1350
Wire Wire Line
	6300 1350 6300 1300
Connection ~ 6300 1300
Wire Wire Line
	6050 1350 6050 1300
Connection ~ 6050 1300
Wire Wire Line
	5800 1250 5800 1350
Connection ~ 5800 1300
Wire Wire Line
	5550 1350 5550 1300
Connection ~ 5550 1300
Wire Wire Line
	5300 1350 5300 1300
Connection ~ 5300 1300
Wire Wire Line
	5050 1650 5050 1700
Wire Wire Line
	4750 1700 6850 1700
Wire Wire Line
	6550 1700 6550 1650
Wire Wire Line
	6300 1650 6300 1700
Connection ~ 6300 1700
Wire Wire Line
	6050 1650 6050 1700
Connection ~ 6050 1700
Wire Wire Line
	5800 1650 5800 1750
Connection ~ 5800 1700
Wire Wire Line
	5550 1700 5550 1650
Connection ~ 5550 1700
Wire Wire Line
	5300 1650 5300 1700
Connection ~ 5300 1700
Wire Wire Line
	4750 1350 4750 1300
Connection ~ 5050 1300
Wire Wire Line
	4750 1700 4750 1650
Connection ~ 5050 1700
Wire Wire Line
	5450 3750 5600 3750
Wire Wire Line
	5600 3550 5450 3550
Wire Wire Line
	5150 3550 5100 3550
Wire Wire Line
	5100 3550 5100 3800
Wire Wire Line
	5150 3750 5100 3750
Connection ~ 5100 3750
Wire Wire Line
	4850 4250 5600 4250
Wire Wire Line
	4550 4250 4450 4250
Wire Wire Line
	4450 4050 4450 4350
Wire Wire Line
	4450 4050 5600 4050
Connection ~ 4450 4250
Wire Wire Line
	4900 4350 4900 4250
Connection ~ 4900 4250
Wire Wire Line
	4900 4650 4900 4700
Wire Wire Line
	4450 4650 4450 4700
Wire Wire Line
	6850 1300 6850 1350
Connection ~ 6550 1300
Wire Wire Line
	6850 1700 6850 1650
Connection ~ 6550 1700
Wire Wire Line
	4550 2750 5600 2750
Wire Wire Line
	4450 5750 5600 5750
Wire Wire Line
	4450 5850 5600 5850
Wire Wire Line
	4650 5950 4450 5950
Wire Wire Line
	4450 6050 4600 6050
Wire Wire Line
	5100 2550 5100 2750
Connection ~ 5100 2750
Wire Wire Line
	5100 2250 5100 2200
Wire Wire Line
	4550 2950 5600 2950
Wire Wire Line
	4750 3000 4750 2950
Connection ~ 4750 2950
Wire Wire Line
	4750 3300 4750 3350
Wire Wire Line
	3850 2950 3950 2950
Wire Wire Line
	3350 1350 3350 1300
Wire Wire Line
	3350 1300 4400 1300
Wire Wire Line
	4400 1300 4400 1350
Wire Wire Line
	4150 1250 4150 1350
Connection ~ 4150 1300
Wire Wire Line
	3900 1350 3900 1300
Connection ~ 3900 1300
Wire Wire Line
	4400 1700 4400 1650
Wire Wire Line
	3350 1700 4400 1700
Wire Wire Line
	3350 1700 3350 1650
Wire Wire Line
	3900 1650 3900 1700
Connection ~ 3900 1700
Wire Wire Line
	4150 1650 4150 1750
Connection ~ 4150 1700
Wire Wire Line
	3500 8400 3500 8350
Wire Wire Line
	3500 8350 3800 8350
Wire Wire Line
	3800 8350 3800 8400
Wire Wire Line
	3700 8300 3700 8400
Connection ~ 3700 8350
Wire Wire Line
	3600 8400 3600 8350
Connection ~ 3600 8350
Wire Wire Line
	3600 10600 3600 10650
Wire Wire Line
	3600 10650 3800 10650
Wire Wire Line
	3800 10650 3800 10600
Wire Wire Line
	3700 10600 3700 10700
Connection ~ 3700 10650
Wire Wire Line
	1450 8900 2900 8900
Wire Wire Line
	1450 9000 2900 9000
Wire Wire Line
	1450 9100 2900 9100
Wire Wire Line
	1050 9400 1050 9450
Wire Wire Line
	4500 9100 4850 9100
Wire Wire Line
	4850 9200 4500 9200
Wire Wire Line
	4500 9300 4850 9300
Wire Wire Line
	4850 9400 4500 9400
Wire Wire Line
	4500 9500 4850 9500
Wire Wire Line
	4850 9600 4500 9600
Wire Wire Line
	4500 9700 4850 9700
Wire Wire Line
	4850 9800 4500 9800
Wire Wire Line
	4500 10100 4850 10100
Wire Wire Line
	4850 10000 4500 10000
Wire Wire Line
	4500 9900 4850 9900
Wire Wire Line
	4500 10200 4850 10200
Wire Wire Line
	5200 6650 5600 6650
Wire Wire Line
	5200 7250 5600 7250
Wire Wire Line
	5200 7350 5600 7350
Wire Wire Line
	5200 7450 5600 7450
Wire Wire Line
	5200 4750 5600 4750
Wire Wire Line
	5200 4950 5600 4950
Wire Wire Line
	5200 6150 5600 6150
Wire Wire Line
	5200 6250 5600 6250
Wire Wire Line
	5200 7150 5600 7150
Wire Wire Line
	13950 6450 13600 6450
Wire Wire Line
	13950 6350 13600 6350
Wire Wire Line
	13950 6150 13600 6150
Wire Wire Line
	1450 8800 1650 8800
Wire Wire Line
	1600 9200 1600 8800
Connection ~ 1600 8800
Wire Wire Line
	1600 9550 1600 9500
Wire Wire Line
	1450 9550 1600 9550
Wire Wire Line
	1450 9200 1450 9600
Connection ~ 1450 9550
Wire Wire Line
	2250 9500 2900 9500
Wire Wire Line
	1900 9300 2900 9300
Wire Wire Line
	1900 9300 1900 9850
Wire Wire Line
	1900 9500 1950 9500
Connection ~ 1900 9500
Wire Wire Line
	2300 9500 2300 9850
Connection ~ 2300 9500
Wire Wire Line
	1900 10150 1900 10200
Wire Wire Line
	2300 10150 2300 10200
Wire Wire Line
	1950 8800 2900 8800
Wire Wire Line
	2850 10000 2900 10000
Wire Wire Line
	1950 9700 1900 9700
Connection ~ 1900 9700
Wire Wire Line
	2250 9700 2300 9700
Connection ~ 2300 9700
Wire Wire Line
	2800 10300 2800 10200
Wire Wire Line
	2800 10200 2900 10200
Wire Wire Line
	2800 10700 2800 10600
Wire Wire Line
	3650 1350 3650 1300
Connection ~ 3650 1300
Wire Wire Line
	3650 1700 3650 1650
Connection ~ 3650 1700
Wire Wire Line
	4550 8800 4500 8800
Wire Wire Line
	4550 8300 4550 8800
Wire Wire Line
	4550 8700 4500 8700
Wire Wire Line
	4550 8300 4700 8300
Connection ~ 4550 8700
Wire Wire Line
	4550 8500 4700 8500
Connection ~ 4550 8500
Wire Wire Line
	4500 8900 4700 8900
Wire Wire Line
	4650 8900 4650 8700
Wire Wire Line
	4650 8700 4700 8700
Connection ~ 4650 8900
Wire Wire Line
	5000 8300 5150 8300
Wire Wire Line
	5150 8300 5150 9000
Wire Wire Line
	5000 8900 5150 8900
Connection ~ 5150 8900
Wire Wire Line
	5000 8700 5150 8700
Connection ~ 5150 8700
Wire Wire Line
	5000 8500 5150 8500
Connection ~ 5150 8500
Wire Wire Line
	13600 7050 14150 7050
Wire Wire Line
	13600 7150 14150 7150
Wire Wire Line
	13600 7350 14150 7350
Wire Wire Line
	5600 5950 5250 5950
Wire Wire Line
	3150 6950 5600 6950
Wire Wire Line
	3150 7050 5600 7050
Wire Wire Line
	3700 7050 3700 6900
Connection ~ 3700 7050
Wire Wire Line
	3400 6900 3400 6950
Connection ~ 3400 6950
Wire Wire Line
	3700 6550 3700 6600
Wire Wire Line
	3400 6550 3700 6550
Wire Wire Line
	3400 6550 3400 6600
Wire Wire Line
	3550 6500 3550 6550
Connection ~ 3550 6550
Wire Wire Line
	4450 6850 5600 6850
Wire Wire Line
	4450 6750 5600 6750
Wire Wire Line
	4600 6650 4450 6650
Wire Wire Line
	800  3950 900  3950
Wire Wire Line
	900  4050 850  4050
Wire Wire Line
	850  4050 850  3950
Connection ~ 850  3950
Wire Wire Line
	2700 4150 2800 4150
Wire Wire Line
	2700 4250 2800 4250
Wire Wire Line
	2700 3950 2800 3950
Wire Wire Line
	2700 4050 3250 4050
Wire Wire Line
	5600 4850 5200 4850
Wire Wire Line
	5200 5050 5600 5050
Wire Wire Line
	5600 5150 5200 5150
Wire Wire Line
	5600 6450 5200 6450
Wire Wire Line
	3250 4450 2700 4450
Wire Wire Line
	3250 3850 2700 3850
Wire Wire Line
	3250 4350 2700 4350
Wire Wire Line
	5200 4650 5600 4650
Wire Wire Line
	900  4350 700  4350
Wire Wire Line
	13600 7250 14150 7250
Wire Wire Line
	13750 7450 13750 7250
Connection ~ 13750 7250
Wire Wire Line
	13750 7750 13750 7850
Wire Wire Line
	13600 5850 14050 5850
Wire Wire Line
	13600 5650 14050 5650
Wire Wire Line
	14050 5750 13600 5750
Wire Wire Line
	14050 5950 14000 5950
Wire Wire Line
	3850 2750 3950 2750
Wire Wire Line
	5000 2650 5100 2650
Connection ~ 5100 2650
Wire Wire Line
	4450 7300 4700 7300
Wire Wire Line
	4450 7400 4700 7400
Wire Wire Line
	4450 7500 4550 7500
Wire Wire Line
	4650 7600 4450 7600
Wire Wire Line
	4550 7500 4550 6950
Connection ~ 4550 6950
Wire Wire Line
	13600 6950 14150 6950
Wire Wire Line
	14050 7450 14050 6950
Connection ~ 14050 6950
Wire Wire Line
	14050 7750 14050 7850
Wire Wire Line
	4650 7600 4650 7050
Connection ~ 4650 7050
Wire Wire Line
	5600 5650 5200 5650
$EndSCHEMATC
