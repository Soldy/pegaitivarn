C = g++
CFLAGS = -Wall -Wextra -std=c++23
CFLAGS_DEBUG = -g ${CFLAGS}
CFLAGS_RELEASE = -O2 ${CFLAGS}

BUILD_DIR = build

TEST_BUILD = ${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/test_$(2) test/$(1)/$(2).cpp
TEST_BUILD_TEXT = $(call TEST_BUILD,text,$(1))
EXAMPLE_BUILD = ${C} ${CFLAGS_DEBUG} -o ${BUILD_DIR}/$(2) example/$(1)/$(2).cpp
EXAMPLE_BUILD_TEXT = $(call EXAMPLE_BUILD,text,$(1))
EXAMPLE_BUILD_TOOLS = $(call EXAMPLE_BUILD,tools,$(1))
EXAMPLE_BUILD_TOOLS_RANDOM = $(call EXAMPLE_BUILD,toos/random,$(1))
EXAMPLE_BUILD_HWMON = $(call EXAMPLE_BUILD,hwmon,$(1))
EXAMPLE_BUILD_BUFFER = $(call EXAMPLE_BUILD,buffer,$(1))
EXAMPLE_BUILD_FILE = $(call EXAMPLE_BUILD,file,$(1))

test_text_xml:
	$(call TEST_BUILD_TEXT,xml)

test_text_safe:
	$(call TEST_BUILD_TEXT,safe)

example_time:
	$(call EXAMPLE_BUILD_TOOLS,time)

example_text_safe:
	$(call EXAMPLE_BUILD_TEXT,safe)

example_text_xml:
	$(call EXAMPLE_BUILD_TEXT,xml)

example_text_join:
	$(call EXAMPLE_BUILD_TEXT,join)

example_text_onelinebar:
	$(call EXAMPLE_BUILD_TEXT,onelinebar)

example_text_quotebar:
	$(call EXAMPLE_BUILD_TEXT,quotebar)

example_file_path:
	$(call EXAMPLE_BUILD_FILE,path)

example_input_editor:
	$(call EXAMPLE_BUILD_TOOLS,input_editor)

example_input_string:
	$(call EXAMPLE_BUILD_TOOLS,input_string)

example_input_integer:
	$(call EXAMPLE_BUILD_TOOLS,input_integer)

example_console_helper_termios:
	$(call EXAMPLE_BUILD_TOOLS,console_helper_termios)

example_verbose:
	$(call EXAMPLE_BUILD_TOOLS,verbose)

example_menu:
	$(call EXAMPLE_BUILD_TOOLS,menu)

example_random_string:
	$(call EXAMPLE_BUILD_TOOLS_RANDOM,string)

example_random_integer:
	$(call EXAMPLE_BUILD_TOOLS_RANDOM,integer)

example_memusage:
	$(call EXAMPLE_BUILD_HWMON,memusage)

example_battery:
	$(call EXAMPLE_BUILD_HWMON,battery)

example_cpuusage:
	$(call EXAMPLE_BUILD_HWMON,cpuusage)

example_cputemp:
	$(call EXAMPLE_BUILD_HWMON,cputemp)

example_cpufreq:
	$(call EXAMPLE_BUILD_HWMON,cpufreq)

example_serial:
	$(call EXAMPLE_BUILD_BUFFER,serial)

example_salted_serial:
	$(call EXAMPLE_BUILD_BUFFER,salted_serial)

example_one_time_pin:
	$(call EXAMPLE_BUILD_BUFFER,one_time_pin)

example_config:
	$(call EXAMPLE_BUILD_BUFFER,config)

example_ini:
	$(call EXAMPLE_BUILD_FILE,ini)

example_csv:
	$(call EXAMPLE_BUILD_FILE,csv)

examples: example_memusage example_battery \
 example_text_xml \
 example_time \
 example_text_safe \
 example_cpuusage \
 example_serial example_salted_serial\
 example_one_time_pin \
 example_input_editor \
 example_input_string \
 example_input_integer \
 example_verbose \
 example_console_helper_termios \
 example_ini

# Ensure the build directory exists
${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

# Clean up
example_time example_input_string example_input_integer example_console_helper_termios example_random_string example_random_integer example_memusage example_battery example_cpuusage example_serial example_salted_serial example_one_time_pin example_config example_verbose example_console_helper_termios example_ini: ${BUILD_DIR}
