#   @b Project: Wump
#   @file        Kyllikki_msvc8.mk
#   @author      Szymon Gutaj
#   @brief       Target/toolchain-specific data for i386/msvc8
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

ifeq ($(TARGET),Kyllikki)
  TESTS_VAR_TOOLCHAIN:=Kyllikki_msvc8
  TESTS_VAR_TOOLCHAIN_OK:=1
endif

ifeq ($(TESTS_VAR_TOOLCHAIN),Kyllikki_msvc8)
  ifneq ($(wildcard $(TESTS_DIR_MSVC8)),$(TESTS_DIR_MSVC8))
    $(error ERROR:   MSVC8 compiler not found under path: "$(TESTS_DIR_MSVC8)"! Please fix the "tests/environment/paths.mk : TESTS_DIR_MSVC8" variable.)
  endif

  TESTS_DIR_MSVC8_BIN:=$(TESTS_DIR_MSVC8)VC/bin/
  TESTS_DIR_MSVC8_COMMON:=$(TESTS_DIR_MSVC8)Common7/IDE/
  TESTS_DIR_MSVC8_STD_LIB:=$(TESTS_DIR_MSVC8)VC/include/ $(TESTS_DIR_MSVC8)VC/PlatformSDK/Include/
  TESTS_DIR_MSVC8_RT_LIB:=$(TESTS_DIR_MSVC8)VC/lib/

  # Compiler
  TESTS_CXX:=$(TESTS_DIR_MSVC8_BIN)cl.exe

  TESTS_CXXFLAGS+=-EHsc /EHsc /GT /MDd /Od /TP /ZI /c /nologo
  TESTS_CPPFLAGS+=-DBSP_CACHE -DBSP_FLASH -DBSP_INTERNAL_TIMER=8 -DCCS_LITTLE_ENDIAN -DGLO_PRINT_USE_ADV_DBGPRINTF -DHOST_COMPILATION -DIP_TARGET_WIN32 -DLITTLE_ENDIAN -DMPC8XX -DOM_NO_FRAMEWORK_MEMORY_MANAGER -DOM_USE_STL -DOS_DEBUG -DR2_WINDOWS -DSCCETH_UNIT1 -DUSE_GLO_PRINT -DWIN32 -DWINDOWS -DWINDOWS_STACK -D_MBCS -D_M_IX86 -D_OM_NO_IOSTREAM -D_WIN32 -D__CCS_INLINE__= -D__MSC__ -Dsnprintf=_snprintf -Dvsnprintf=_vsnprintf
  TESTS_CPPFLAGS+=-DTESTS_OS_WINDOWS
  TESTS_CPPFLAGS+=$(addprefix -I,$(TESTS_DIR_MSVC8_STD_LIB))

  TESTS_OPT_INC:=/FI

  # Linker
  TESTS_LNK:=$(TESTS_DIR_MSVC8_BIN)link.exe
  TESTS_LNKFLAGS+=/NOLOGO /DEBUG /SUBSYSTEM:console /MACHINE:I386 /nodefaultlib:"libcimt.lib" /INCREMENTAL /IGNORE:4221 /ERRORREPORT:NONE /LIBPATH:$(TESTS_DIR_MSVC8_RT_LIB)
  
  TESTS_OPT_EXE:=/OUT:
  TESTS_EXT_EXE:=.exe

  TESTS_OPT_OBJ:=/Fo
  TESTS_EXT_OBJ:=.obj

  # Archiver
  TESTS_AR:=$(TESTS_DIR_MSVC8_BIN)link.exe -lib
  TESTS_ARFLAGS+= /NOLOGO /SUBSYSTEM:console /MACHINE:I386 /nodefaultlib:"libcimt.lib" /IGNORE:4221

  TESTS_OPT_LIB:=/OUT:
  TESTS_EXT_LIB:=.lib

  # Dependency generator
  TESTS_DEP=$(TESTS_PY) $(TESTS_DIR_TOOLCHAINS)/i386_msvc8.py $(TESTS_DIR_MSVC8_BIN)cl.exe
  TESTS_DEPFLAGS+=/showIncludes /Zs /nologo -EHsc /EHsc /GT /MDd /TP

  TESTS_OPT_DEP:=
  TESTS_EXT_DEP:=.d
  
  # Debugger
  TESTS_DBG:=$(TESTS_DIR_MSVC8_COMMON)devenv.exe /debugexe
  TESTS_DBGFLAGS+=

  TESTS_IGNORE_4191=/IGNORE:4191

endif