# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\psoc\theory\i2c\i2c.cydsn\i2c.cyprj
# Date: Tue, 23 Aug 2022 03:40:49 GMT
#set_units -time ns
create_clock -name {i2c_SCBCLK(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {uart_SCBCLK(FFB)} -period 708.33333333333326 -waveform {0 354.166666666667} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {i2c_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 15 31} [list]
create_generated_clock -name {uart_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 35} -nominal_period 708.33333333333326 [list]


# Component constraints for D:\psoc\theory\i2c\i2c.cydsn\TopDesign\TopDesign.cysch
# Project: D:\psoc\theory\i2c\i2c.cydsn\i2c.cyprj
# Date: Tue, 23 Aug 2022 03:40:46 GMT
