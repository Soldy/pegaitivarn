C = g++
CFLAGS = -Wall -Wextra -std=c++23 -o 
CFLAGS_DEBUG = -g ${CFLAGS}
CFLAGS_RELASE = -O2 ${CFLAGS} 

example_time:
	${C} ${CFLAGS_DEBUG} time example/tools/time.cpp

example_input_string:
	${C} ${CFLAGS_DEBUG} input_string example/tools/input_string.cpp 

example_input_integer:
	${C} ${CFLAGS_DEBUG} input_integer example/tools/input_integer.cpp 

example_console_helper_termios:
	${C} ${CFLAGS_DEBUG} console_helper_termios example/tools/console_helper_termios.cpp 

example_random_string:
	${C} ${CFLAGS_DEBUG} random_string example/tools/random/string.cpp 

example_random_integer:
	${C} ${CFLAGS_DEBUG} random_integer example/tools/random/integer.cpp 

example_memusage:
	${C} ${CFLAGS_DEBUG} memusage example/hwmon/memusage.cpp 

example_battery:
	${C} ${CFLAGS_DEBUG} battery example/hwmon/battery.cpp 

example_cpuusage:
	${C} ${CFLAGS_DEBUG} cpuusage example/hwmon/cpuusage.cpp 

example_serial:
	${C} ${CFLAGS_DEBUG} serial example/buffer/serial.cpp 

example_salted_serial:
	${C} ${CFLAGS_DEBUG} salted_serial example/buffer/salted_serial.cpp 

example_one_time_pin:
	${C} ${CFLAGS_DEBUG} onetimepin example/buffer/one_time_pin.cpp 

example_verbose:
	${C} ${CFLAGS_DEBUG} verbose example/tools/verbose.cpp 

example_ini:
	${C} ${CFLAGS_DEBUG} ini example/file/ini.cpp 

examples: example_memusage example_battery \
 example_time \
 example_cpuusage \
 example_serial example_salted_serial\
 example_one_time_pin \
 example_input_string example_input_integer \
 example_verbose \
 example_console_helper_termios \
 example_ini
