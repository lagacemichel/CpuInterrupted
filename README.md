# CpuInterrupted
Arduino sketch demonstrating CPU interrupts from a digital input pin.
The sketch uses four LEDs connected to digital I/O pins 8, 9, 10, and 11
to demonstrate how interrupts work. The LEDs are lit one after the other,
once a second, as well as when the switch is depressed. When the switch is
depressed, it causes an interrupt that calls an interrupt routine that
increments the count and then displays the LED corresponding to the count.
