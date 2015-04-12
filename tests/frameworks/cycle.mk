#   @b Project: Wump
#   @file        cycle.mk
#   @author      Szymon Gutaj
#   @brief       Makefile for running tests on local target (radiomodule)
#   @date        10-04-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

TESTS_VAR_GOALS_SUPPORTED+=cycle

TESTS_DIR_CYCLE:=$(TESTS_DIR_FRAMEWORKS)/cycle

TESTS_VAR_REMOTE_BINARY:=FRM_RT_SW.bin
TESTS_VAR_REMOTE_BINARY_FLASH:=MON1
TESTS_VAR_LOCAL_BINARY:=$(TESTS_DIR_BUILD)/$(TESTS_VAR_REMOTE_BINARY)

TESTS_VAR_REMOTE_CYCLE_OUTPUT:=cycle_output.txt
TESTS_VAR_LOCAL_CYCLE_OUTPUT:=$(TESTS_DIR_OUT)/$(TESTS_VAR_REMOTE_CYCLE_OUTPUT)

# Main target
.PHONY: cycle
cycle: $(TESTS_VAR_LOCAL_CYCLE_OUTPUT)

# Connect via FTP, transfer tests results
# pragma runlocal
$(TESTS_VAR_LOCAL_CYCLE_OUTPUT): telnet_tests_run
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_PY) $(TESTS_DIR_CYCLE)/ftp_retrieve.py $(TESTS_VAR_REMOTE_CYCLE_OUTPUT) $(TESTS_VAR_LOCAL_CYCLE_OUTPUT)
	@$(call TESTS_CMD_ECHO,INFO (UNIT TESTS):    All done)

# Connect via telnet, run unit tests, dump to file
.PHONY: telnet_tests_run
# pragma runlocal
telnet_tests_run: ping
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_PY) $(TESTS_DIR_CYCLE)/telnet_tests_run.py $(TESTS_VAR_REMOTE_CYCLE_OUTPUT)

# Wait for boot-up
.PHONY: ping
#pragma runlocal
ping: telnet_reboot
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_PY) $(TESTS_DIR_CYCLE)/ping.py

# Reboot the system after flashing
.PHONY: telnet_reboot
# pragma runlocal
telnet_reboot: telnet_flash
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_PY) $(TESTS_DIR_CYCLE)/telnet_reboot.py

# Connect via telnet, flash file
.PHONY: telnet_flash
# pragma runlocal
telnet_flash: ftp_store
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_PY) $(TESTS_DIR_CYCLE)/telnet_flash.py $(TESTS_VAR_REMOTE_BINARY_FLASH) $(TESTS_VAR_REMOTE_BINARY)

# Connect via FTP, transfer file
.PHONY: ftp_store
# pragma runlocal
ftp_store: frm_running
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_PY) $(TESTS_DIR_CYCLE)/ftp_store.py $(TESTS_VAR_LOCAL_BINARY) $(TESTS_VAR_REMOTE_BINARY)

.PHONY: frm_running
# pragma runlocal
frm_running:
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_PY) $(TESTS_DIR_CYCLE)/ping.py
