#   @b Project: Wump
#   @file        code_under_test.mk
#   @author      Szymon Gutaj
#   @brief       Makefile for building code under test
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 09-04-2011
#      - sgutaj
#        - Initial creation

TESTS_DIR_CODE_UNDER_TEST:=$(TESTS_DIR_TESTS)/code_under_test

# Import code under test info
TESTS_INC_CODE_UNDER_TEST:=$(wildcard $(TESTS_DIR_CODE_UNDER_TEST)/*.mk)
TESTS_INC_CODE_UNDER_TEST+=$(wildcard $(TESTS_DIR_CODE_UNDER_TEST)/**/*.mk)
TESTS_INC_CODE_UNDER_TEST+=$(wildcard $(TESTS_DIR_CODE_UNDER_TEST)/**/**/*.mk)
TESTS_INC_CODE_UNDER_TEST+=$(wildcard $(TESTS_DIR_CODE_UNDER_TEST)/**/**/**/*.mk)
TESTS_INC_CODE_UNDER_TEST+=$(wildcard $(TESTS_DIR_CODE_UNDER_TEST)/**/**/**/**/*.mk)
TESTS_INC_CODE_UNDER_TEST+=$(wildcard $(TESTS_DIR_CODE_UNDER_TEST)/**/**/**/**/**/*.mk)
include $(TESTS_INC_CODE_UNDER_TEST)

# Code under test
TESTS_OBJ_CODE_UNDER_TEST+=$(subst $(TESTS_EXT_SRC),$(TESTS_EXT_OBJ),$(addprefix $(TESTS_DIR_OUT)/,$(TESTS_SRC_CODE_UNDER_TEST)))
TESTS_DEP_CODE_UNDER_TEST:=$(subst $(TESTS_EXT_OBJ),$(TESTS_EXT_DEP),$(TESTS_OBJ_CODE_UNDER_TEST))

# Append objects to global dependency list
TESTS_OUT_CODE_UNDER_TEST+=$(TESTS_OBJ_CODE_UNDER_TEST)

# Code under test: objects
$(TESTS_OBJ_CODE_UNDER_TEST): $(TESTS_DIR_OUT)/%$(TESTS_EXT_OBJ): $(TESTS_DIR_OUT)/%$(TESTS_EXT_DEP)
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_CXX) -c $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
    $(TESTS_OPT_OBJ)$@ \
    $*$(TESTS_EXT_SRC)

-include $(TESTS_DEP_CODE_UNDER_TEST)

# Code under test: dependencies
$(TESTS_DEP_CODE_UNDER_TEST): $(TESTS_DIR_OUT)/%$(TESTS_EXT_DEP): %$(TESTS_EXT_SRC) | tests_directories_code_under_test
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_DEP) $(TESTS_CPPFLAGS) $(TESTS_DEPFLAGS) \
    $(TESTS_OPT_DEP)$@ \
    $*$(TESTS_EXT_SRC)

# Output directories ----------------------------------------------------------#
.PHONY: tests_directories_code_under_test
# pragma runlocal
tests_directories_code_under_test:
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CMD_MKDIR,$(sort $(dir $(TESTS_OBJ_CODE_UNDER_TEST))))	