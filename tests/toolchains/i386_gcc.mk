#   @b Project: Wump
#   @file        i386_gcc.mk
#   @author      Szymon Gutaj
#   @brief       Target/toolchain-specific data for i386/gcc
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

ifeq ($(TARGET),Host)
  ifeq ($(TOOLCHAIN),gcc)
    TESTS_VAR_TOOLCHAIN:=i386_gcc
    TESTS_VAR_TOOLCHAIN_OK:=1
  endif
endif

ifeq ($(TESTS_VAR_TOOLCHAIN),i386_gcc)
  ifneq ($(wildcard $(TESTS_DIR_GCC)),$(TESTS_DIR_GCC))
    $(error ERROR:   GCC compiler not found under path: "$(TESTS_DIR_GCC)"! Please fix the "tests/environment/paths.mk : TESTS_DIR_GCC" variable.)
  endif

  # Compiler
  TESTS_CXX:=$(TESTS_DIR_GCC)g++

  TESTS_CXXFLAGS+=-ggdb -Wall -Wextra -Wno-unknown-pragmas
  TESTS_CPPFLAGS+= -DTESTS_OS_WINDOWS -DCCS_LITTLE_ENDIAN -DHOST_COMPILATION

  TESTS_OPT_INC:=-include

  # Linker
  TESTS_LNK:=$(TESTS_DIR_GCC)g++
  TESTS_LNKFLAGS+=

  TESTS_OPT_EXE:=-o
  TESTS_EXT_EXE:=.exe

  TESTS_OPT_OBJ:=-o
  TESTS_EXT_OBJ:=.o

  # Archiver
  TESTS_AR:=$(TESTS_DIR_GCC)g++
  TESTS_ARFLAGS+=

  TESTS_OPT_LIB:=
  TESTS_EXT_LIB:=.a

  # Dependency generator
  TESTS_DEP:=$(TESTS_DIR_GCC)g++
  TESTS_DEPFLAGS+=-MM $(TESTS_CXXFLAGS) -MT $@

  TESTS_OPT_DEP:=-MF
  TESTS_EXT_DEP:=.d
  
  # Debugger
  TESTS_DBG:=
  TESTS_DBGFLAGS+=

  TESTS_IGNORE_4191=-ei4191
endif
