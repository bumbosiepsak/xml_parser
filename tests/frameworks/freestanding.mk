#   @b Project: Wump
#   @file        freestanding.mk
#   @author      Szymon Gutaj
#   @brief       Makefile for building freestanding (not framework-related) code
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 09-04-2011
#      - sgutaj
#        - Initial creation

ifeq ($(UNIT_TESTS),Yes)

# Initialize internal variables -----------------------------------------------#

# Input directory
TESTS_DIR_UOAM_TESTS_FREESTANDING:=$(TESTS_DIR_UOAM_TESTS)/freestanding

# Hacks file
TESTS_SRC_UOAM_TESTS_FREESTANDING_HACKS:=$(TESTS_DIR_LIBRARY)/uoam_tests_freestanding_hacks$(TESTS_EXT_CXXHACKS)

# Sources
TESTS_SRC_UOAM_TESTS_FREESTANDING:=$(wildcard $(TESTS_DIR_UOAM_TESTS_FREESTANDING)/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_FREESTANDING+=$(wildcard $(TESTS_DIR_UOAM_TESTS_FREESTANDING)/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_FREESTANDING+=$(wildcard $(TESTS_DIR_UOAM_TESTS_FREESTANDING)/**/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_FREESTANDING+=$(wildcard $(TESTS_DIR_UOAM_TESTS_FREESTANDING)/**/**/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_FREESTANDING+=$(wildcard $(TESTS_DIR_UOAM_TESTS_FREESTANDING)/**/**/**/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_FREESTANDING+=$(wildcard $(TESTS_DIR_UOAM_TESTS_FREESTANDING)/**/**/**/**/**/*$(TESTS_EXT_SRC))

TESTS_OBJ_UOAM_TESTS_FREESTANDING:=$(subst $(TESTS_EXT_SRC),$(TESTS_EXT_OBJ),$(addprefix $(TESTS_DIR_OUT)/,$(TESTS_SRC_UOAM_TESTS_FREESTANDING)))
TESTS_DEP_UOAM_TESTS_FREESTANDING:=$(subst $(TESTS_EXT_OBJ),$(TESTS_EXT_DEP),$(TESTS_OBJ_UOAM_TESTS_FREESTANDING))

# Append objects to global dependency list
TESTS_OUT_CONTENTS+=$(TESTS_OBJ_UOAM_TESTS_FREESTANDING)

# Rules -----------------------------------------------------------------------#
# Testing code freestanding: objects
$(TESTS_OBJ_UOAM_TESTS_FREESTANDING): $(TESTS_DIR_OUT)/%$(TESTS_EXT_OBJ): $(TESTS_DIR_OUT)/%$(TESTS_EXT_DEP)
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_CXX) -c $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
    $(TESTS_OPT_OBJ)$@ \
    $*$(TESTS_EXT_SRC)

-include $(TESTS_DEP_UOAM_TESTS_FREESTANDING)

# Testing code freestanding: dependencies
$(TESTS_DEP_UOAM_TESTS_FREESTANDING): $(TESTS_DIR_OUT)/%$(TESTS_EXT_DEP): %$(TESTS_EXT_SRC) | tests_directories_uoam_tests_freestanding
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_DEP) $(TESTS_CPPFLAGS) $(TESTS_DEPFLAGS) \
    $(TESTS_OPT_DEP)$@ \
    $*$(TESTS_EXT_SRC)

# Output directories ----------------------------------------------------------#
.PHONY: tests_directories_uoam_tests_freestanding
# pragma runlocal
tests_directories_uoam_tests_freestanding:
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CMD_MKDIR,$(sort $(dir $(TESTS_OBJ_UOAM_TESTS_FREESTANDING))))	

endif # ifeq ($(UNIT_TESTS),Yes)