#   @b Project: Wump
#   @file        gtest.mk
#   @author      Szymon Gutaj
#   @brief       Makefile for building gtest
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

ifeq ($(UNIT_TESTS),Yes)

# Initialize internal variables -----------------------------------------------#

# Input directory
TESTS_DIR_GTEST:=$(TESTS_DIR_FRAMEWORKS)/gtest
TESTS_DIR_GTEST_EXTRA:=$(TESTS_DIR_FRAMEWORKS)/gtest_extra
TESTS_DIR_UOAM_TESTS_GTEST:=$(TESTS_DIR_UOAM_TESTS)/gtest

# Output directory
TESTS_DIR_GTEST_OUT:=$(TESTS_DIR_OUT)/$(TESTS_DIR_GTEST)

TESTS_DIR_UOAM_TESTS_GTEST_OUT:=$(TESTS_DIR_OUT)/$(TESTS_DIR_UOAM_TESTS_GTEST)

# Sources
TESTS_SRC_GTEST:=$(TESTS_DIR_GTEST)/src/gtest-all.cc
TESTS_OBJ_GTEST:=$(TESTS_DIR_GTEST_OUT)/gtest-all$(TESTS_EXT_OBJ)
TESTS_HDR_GTEST:=$(TESTS_DIR_GTEST)/include/gtest/*.h \
                 $(TESTS_DIR_GTEST)/include/gtest/internal/*.h
TESTS_DEP_GTEST:=$(TESTS_DIR_GTEST)/src/*.cc \
                 $(TESTS_DIR_GTEST)/src/*.h \
                 $(TESTS_HDR_GTEST) 

TESTS_SRC_GTEST_EXTRA:=$(wildcard $(TESTS_DIR_GTEST_EXTRA)/*$(TESTS_EXT_SRC))
TESTS_OBJ_GTEST_EXTRA:=$(subst $(TESTS_EXT_SRC),$(TESTS_EXT_OBJ),$(subst $(TESTS_DIR_GTEST_EXTRA),$(TESTS_DIR_GTEST_OUT),$(TESTS_SRC_GTEST_EXTRA)))
TESTS_DEP_GTEST_EXTRA:=$(subst $(TESTS_EXT_OBJ),$(TESTS_EXT_DEP),$(TESTS_OBJ_GTEST_EXTRA))
TESTS_HCK_GTEST_EXTRA:=$(call TESTS_CXXHACKS_DEFINE,$(TESTS_DIR_LIBRARY)/hack_gtest_extra$(TESTS_EXT_CXXHACKS))

TESTS_SRC_UOAM_TESTS_GTEST:=$(wildcard $(TESTS_DIR_UOAM_TESTS_GTEST)/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_GTEST+=$(wildcard $(TESTS_DIR_UOAM_TESTS_GTEST)/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_GTEST+=$(wildcard $(TESTS_DIR_UOAM_TESTS_GTEST)/**/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_GTEST+=$(wildcard $(TESTS_DIR_UOAM_TESTS_GTEST)/**/**/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_GTEST+=$(wildcard $(TESTS_DIR_UOAM_TESTS_GTEST)/**/**/**/**/*$(TESTS_EXT_SRC))
TESTS_SRC_UOAM_TESTS_GTEST+=$(wildcard $(TESTS_DIR_UOAM_TESTS_GTEST)/**/**/**/**/**/*$(TESTS_EXT_SRC))

TESTS_OBJ_UOAM_TESTS_GTEST:=$(subst $(TESTS_EXT_SRC),$(TESTS_EXT_OBJ),$(addprefix $(TESTS_DIR_OUT)/,$(TESTS_SRC_UOAM_TESTS_GTEST)))
TESTS_DEP_UOAM_TESTS_GTEST:=$(subst $(TESTS_EXT_OBJ),$(TESTS_EXT_DEP),$(TESTS_OBJ_UOAM_TESTS_GTEST))
TESTS_HCK_UOAM_TESTS_GTEST:=$(call TESTS_CXXHACKS_DEFINE,$(TESTS_DIR_LIBRARY)/hack_uoam_tests_gtest$(TESTS_EXT_CXXHACKS))

# Append objects to global dependency list
TESTS_OUT_CONTENTS+=$(TESTS_OBJ_GTEST)
TESTS_OUT_CONTENTS+=$(TESTS_OBJ_GTEST_EXTRA)
TESTS_OUT_CONTENTS+=$(TESTS_OBJ_UOAM_TESTS_GTEST)

TESTS_OUT_PREREQUISITES+=$(TESTS_HCK_GTEST_EXTRA)
TESTS_OUT_PREREQUISITES+=$(TESTS_HCK_UOAM_TESTS_GTEST)

# Googletest-specific flags
TESTS_GTEST_CPPFLAGS+= -I$(TESTS_DIR_GTEST)/include -DGTEST_HAS_STD_WSTRING=0 $(TESTS_OPT_INC)$(TESTS_DIR_GTEST_EXTRA)/gtest-port-ose.h

# Googletest headers available for code under test
TESTS_DIR_CODE_UNDER_TEST_INCLUDES+=$(TESTS_DIR_GTEST)/include

# Include googlemock add-on
-include $(TESTS_DIR_FRAMEWORKS)/gmock.inc

# Rules -----------------------------------------------------------------------#
# Framework
$(TESTS_OBJ_GTEST): $(TESTS_DEP_GTEST) | tests_directories_gtest
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_CXX) -c $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
    $(TESTS_GTEST_CPPFLAGS) \
    -I$(TESTS_DIR_GTEST) \
    $(TESTS_OPT_OBJ)$@ \
    $(TESTS_SRC_GTEST)

# Extras
$(TESTS_OBJ_GTEST_EXTRA): $(TESTS_DIR_GTEST_OUT)/%$(TESTS_EXT_OBJ): $(TESTS_DIR_GTEST_OUT)/%$(TESTS_EXT_DEP)
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_CXX) -c $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
    $(TESTS_GTEST_CPPFLAGS) \
    $(call TESTS_CXXHACKS_APPLY_1,$@) \
    $(TESTS_OPT_OBJ)$@ \
    $(TESTS_DIR_GTEST_EXTRA)/$*$(TESTS_EXT_SRC)

$(TESTS_HCK_GTEST_EXTRA): $(TESTS_OBJ_GTEST_EXTRA)
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CXXHACKS_APPLY_2,$@,$^)

-include $(TESTS_DEP_GTEST_EXTRA)

$(TESTS_DEP_GTEST_EXTRA): $(TESTS_DIR_GTEST_OUT)/%$(TESTS_EXT_DEP): $(TESTS_DIR_GTEST_EXTRA)/%$(TESTS_EXT_SRC) | tests_directories_gtest
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_DEP) $(TESTS_CPPFLAGS) $(TESTS_DEPFLAGS) \
    $(TESTS_GTEST_CPPFLAGS) \
    $(TESTS_OPT_DEP)$@ \
    $(TESTS_DIR_GTEST_EXTRA)/$*$(TESTS_EXT_SRC)

# Tests
$(TESTS_OBJ_UOAM_TESTS_GTEST): $(TESTS_DIR_UOAM_TESTS_GTEST_OUT)/%$(TESTS_EXT_OBJ): $(TESTS_DIR_UOAM_TESTS_GTEST_OUT)/%$(TESTS_EXT_DEP)
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_CXX) -c $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
    $(TESTS_GTEST_CPPFLAGS) \
    $(call TESTS_CXXHACKS_APPLY_1,$@) \
    $(TESTS_OPT_OBJ)$@ \
    $(TESTS_DIR_UOAM_TESTS_GTEST)/$*$(TESTS_EXT_SRC)

$(TESTS_HCK_UOAM_TESTS_GTEST): $(TESTS_OBJ_UOAM_TESTS_GTEST)
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CXXHACKS_APPLY_2,$@,$^)

-include $(TESTS_DEP_UOAM_TESTS_GTEST)

$(TESTS_DEP_UOAM_TESTS_GTEST): $(TESTS_DIR_UOAM_TESTS_GTEST_OUT)/%$(TESTS_EXT_DEP): $(TESTS_DIR_UOAM_TESTS_GTEST)/%$(TESTS_EXT_SRC) | tests_directories_gtest
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_DEP) $(TESTS_CPPFLAGS) $(TESTS_DEPFLAGS) \
    $(TESTS_GTEST_CPPFLAGS) \
    $(TESTS_OPT_DEP)$@ \
    $(TESTS_DIR_UOAM_TESTS_GTEST)/$*$(TESTS_EXT_SRC)

# Output directories ----------------------------------------------------------#
.PHONY: tests_directories_gtest
# pragma runlocal
tests_directories_gtest:
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CMD_MKDIR,$(sort $(dir $(TESTS_OBJ_GTEST_EXTRA) $(TESTS_OBJ_UOAM_TESTS_GTEST))))

endif # ifeq ($(UNIT_TESTS),Yes)
