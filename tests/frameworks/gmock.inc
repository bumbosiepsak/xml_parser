#   @b Project: Wump
#   @file        gmock.inc
#   @author      Szymon Gutaj
#   @brief       Makefile add-on (to gtest.mk) for building gmock
#   @date        10-04-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

# Initialize internal variables -----------------------------------------------#

# Input directory
TESTS_DIR_GMOCK:=$(TESTS_DIR_FRAMEWORKS)/gmock

# Output directory
TESTS_DIR_GMOCK_OUT:=$(TESTS_DIR_OUT)/$(TESTS_DIR_GMOCK)

# Sources
TESTS_SRC_GMOCK:=$(TESTS_DIR_GMOCK)/src/gmock-all.cc
TESTS_OBJ_GMOCK:=$(TESTS_DIR_GMOCK_OUT)/gmock-all$(TESTS_EXT_OBJ)
TESTS_DEP_GMOCK:=$(TESTS_DIR_GMOCK)/src/*.cc \
                 $(TESTS_DIR_GMOCK)/include/gmock/*.h \
                 $(TESTS_DIR_GMOCK)/include/gmock/internal/*.h \
                 $(TESTS_HDR_GTEST)

# Append objects to global dependency list
TESTS_OUT_CONTENTS+=$(TESTS_OBJ_GMOCK)

# Gmock-specific flags: append to Gtest
TESTS_GTEST_CPPFLAGS+=-I$(TESTS_DIR_GMOCK)/include -DTESTS_GMOCK_PRESENT
TESTS_GMOCK_CPPFLAGS=$(TESTS_GTEST_CPPFLAGS)

# Gmock headers available for code under test
TESTS_DIR_CODE_UNDER_TEST_INCLUDES+=$(TESTS_DIR_GMOCK)/include

# Rules -----------------------------------------------------------------------#
# Framework
$(TESTS_OBJ_GMOCK): $(TESTS_DEP_GMOCK) | tests_directories_gmock
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_CXX) -c $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
    $(TESTS_GMOCK_CPPFLAGS) \
    -I$(TESTS_DIR_GMOCK) \
    $(TESTS_OPT_OBJ)$@ \
    $(TESTS_SRC_GMOCK)

# Output directories ----------------------------------------------------------#
.PHONY: tests_directories_gmock
# pragma runlocal
tests_directories_gmock:
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CMD_MKDIR,$(sort $(dir $(TESTS_OBJ_GMOCK))))
