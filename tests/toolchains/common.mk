#   @b Project: Wump
#   @file        common.mk
#   @author      Szymon Gutaj
#   @brief       Common data for all toolchains
#   @date        01-04-2011
#   @version     0.1
#   @b History:
#    - 01-04-2011
#      - sgutaj
#        - Initial creation


TESTS_PY:=$(TESTS_DIR_PYTHON)python

TESTS_CPPFLAGS+= -I. -I./tests $(addprefix -I,$(TESTS_DIR_CODE_UNDER_TEST_INCLUDES))

TESTS_EXT_HDR:=.h
TESTS_EXT_SRC:=.cpp
