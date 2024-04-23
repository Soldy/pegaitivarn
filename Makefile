C = g++
CFLAGS = -Wall -Wextra -std=c++23
CFLAGS_DEBUG = -g ${CFLAGS}
CFLAGS_RELEASE = -O2 ${CFLAGS}

BUILD_DIR = build

example_time:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/time example/tools/time.cpp

example_input_string:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/input_string example/tools/input_string.cpp

example_input_integer:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/input_integer example/tools/input_integer.cpp

example_console_helper_termios:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/console_helper_termios example/tools/console_helper_termios.cpp

example_random_string:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/random_string example/tools/random/string.cpp

example_random_integer:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/random_integer example/tools/random/integer.cpp

example_memusage:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/memusage example/hwmon/memusage.cpp

example_battery:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/battery example/hwmon/battery.cpp

example_cpuusage:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/cpuusage example/hwmon/cpuusage.cpp

example_serial:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/serial example/buffer/serial.cpp

example_salted_serial:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/salted_serial example/buffer/salted_serial.cpp

example_one_time_pin:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/onetimepin example/buffer/one_time_pin.cpp

example_config:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/config example/buffer/config.cpp

example_verbose:
	${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/verbose example/tools/verbose.cpp

examples: example_memusage example_battery \
 example_time \
 example_cpuusage \
 example_serial example_salted_serial\
 example_one_time_pin \
 example_input_string example_input_integer \
 example_config \
 example_verbose \
 example_console_helper_termios

# Ensure the build directory exists
${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

# Clean up
example_time example_input_string example_input_integer example_console_helper_termios example_random_string example_random_integer example_memusage example_battery example_cpuusage example_serial example_salted_serial example_one_time_pin example_config example_verbose: ${BUILD_DIR}
