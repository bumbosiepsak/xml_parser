#   @b Project: Wump
#   @file        custom.mk
#   @author      Szymon Gutaj
#   @brief       Makefile for building custom targets
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 09-04-2011
#      - sgutaj
#        - Initial creation

ifeq ($(UNIT_TESTS),Yes)

# Initialize internal variables -----------------------------------------------#

# Input directory
TESTS_DIR_UOAM_TESTS_CUSTOM:=$(TESTS_DIR_UOAM_TESTS)/custom

# Import custmized makefiles
TESTS_INC_UOAM_TESTS_CUSTOM:=$(wildcard $(TESTS_DIR_UOAM_TESTS_CUSTOM)/*.mk)
TESTS_INC_UOAM_TESTS_CUSTOM+=$(wildcard $(TESTS_DIR_UOAM_TESTS_CUSTOM)/**/*.mk)
TESTS_INC_UOAM_TESTS_CUSTOM+=$(wildcard $(TESTS_DIR_UOAM_TESTS_CUSTOM)/**/**/*.mk)
TESTS_INC_UOAM_TESTS_CUSTOM+=$(wildcard $(TESTS_DIR_UOAM_TESTS_CUSTOM)/**/**/**/*.mk)
TESTS_INC_UOAM_TESTS_CUSTOM+=$(wildcard $(TESTS_DIR_UOAM_TESTS_CUSTOM)/**/**/**/**/*.mk)
TESTS_INC_UOAM_TESTS_CUSTOM+=$(wildcard $(TESTS_DIR_UOAM_TESTS_CUSTOM)/**/**/**/**/**/*.mk)
include $(TESTS_INC_UOAM_TESTS_CUSTOM)

endif # ifeq ($(UNIT_TESTS),Yes)
