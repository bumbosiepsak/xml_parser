#   @b Project: Wump
#   @file        PPC8347EH_diab532.mk
#   @author      Szymon Gutaj
#   @brief       Target/toolchain-specific data for PPC8347EH/diab532
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

ifeq ($(TARGET),Local)
  ifeq ($(TOOLCHAIN),diab532)
    TESTS_VAR_TOOLCHAIN:=PPC8347EH_diab532
    TESTS_VAR_TOOLCHAIN_OK:=1
  endif
endif

ifeq ($(TESTS_VAR_TOOLCHAIN),PPC8347EH_diab532)
  ifneq ($(wildcard $(TESTS_DIR_DIAB)),$(TESTS_DIR_DIAB))
    $(error ERROR:   DIAB 5.3.2 compiler not found under path: "$(TESTS_DIR_DIAB)"! Please fix the "tests/environment/paths.mk : TESTS_DIR_DIAB" variable.)
  endif

  # Compiler
  TESTS_CXX:=$(TESTS_DIR_DIAB)dplus.exe

  TESTS_CXXFLAGS+=-tPPC8347EH:cross -Xexceptions -Xenum-is-int -Xconst-in-text=0 -Xsmall-data=0 -Xsmall-const=0 -W:c++:.c
  TESTS_CPPFLAGS+=-DAASOCKET_BSD_STACK -DAUTONEGOTIATE -DBIG_ENDIAN -DBSP_CACHE -DCCS_BIG_ENDIAN -DDBG_PRN_NO_DBSERV_MSG_CHNL -DDCC_PRES_UNTRASHED -DDCM_LTE -DDCM_OAM -DGLO_PRINT_USE_ADV_DBGPRINTF -DIP_TARGET_POWERPC -DMMS_MAP_VECTOR_AREA -DMPC834X -DOM_NO_FRAMEWORK_MEMORY_MANAGER -DOSE_DELTA -DOSE_H_CLASSIC -DOSE_H_SPI -DPOWERPC -DSCRIPTING_ENGINE -DUSE_GLO_PRINT -D__DIAB -D__IEEE_BIG_ENDIAN
  TESTS_CPPFLAGS+=-DTESTS_OS_OSE -DTESTS_APPEND_WCHAR_FUNCTIONS_TO_OSE_CLIB -DSTDOUT_FILENO=1 -DSTDERR_FILENO=2 -DGTEST_NEEDS_IS_POINTER_=1
  TESTS_CPPFLAGS+=-I$(TESTS_DIR_DIAB)include/diab
  TESTS_CPPFLAGS+=-I$(TESTS_DIR_OSE)include

  TESTS_OPT_INC:=-i =

  # Linker
  TESTS_LNK:=$(TESTS_DIR_DIAB)dplus.exe
  TESTS_LNKFLAGS+=-tPPC8347EH:cross -W:c++:.c

  TESTS_OPT_EXE:=
  TESTS_EXT_EXE:=

  TESTS_OPT_OBJ:=-o
  TESTS_EXT_OBJ:=.o

  # Archiver
  TESTS_AR:=$(TESTS_DIR_DIAB)dar.exe
  TESTS_ARFLAGS+=-rc -s

  TESTS_OPT_LIB:=
  TESTS_EXT_LIB:=.a

  # Dependency generator
  TESTS_DEP:=$(TESTS_DIR_DIAB)dplus.exe
  TESTS_DEPFLAGS+=-Xmake-dependency $(TESTS_CXXFLAGS) -Xmake-dependency-target=$@

  TESTS_OPT_DEP:=-Xmake-dependency-savefile=
  TESTS_EXT_DEP:=.d

  # Debugger
  TESTS_DBG:=
  TESTS_DBGFLAGS+=
  
  # Linker commands generation (symbols injection)
  TESTS_OPT_SYM:=-u

  TESTS_CXXHACKS_DEFINE=$1
  TESTS_CXXHACKS_APPLY_1=-DARTIFICIAL_SYMBOL=$(call TESTS_TO_CXX_NAME,$1) $(TESTS_OPT_INC)$(TESTS_DIR_TOOLCHAINS)/PPC8347EH_diab532.h
  TESTS_CXXHACKS_APPLY_2=$(call TESTS_CMD_PRINTF,$(addprefix $(NEWLINE)$(TESTS_OPT_SYM),$(call TESTS_TO_CXX_NAME,$2))$(SPACE)) > $1
  
  TESTS_EXT_CXXHACKS:=.linkercmd.txt

  TESTS_IGNORE_4191:=-ei4191
  
endif