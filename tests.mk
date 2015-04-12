#   @b Project: Wump
#   @file        tests.mk
#   @author      Szymon Gutaj
#   @brief       Main makefile for building unit tests
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

# Initialize command-line parameters to defaults ------------------------------#
.DEFAULT_GOAL:=all

EXE_PARAMS?=# Parameters list to invoke the executable with
PATHS_CUSTOM?=No# Forces usage of custom paths
TARGET?=Local# Build target: Local/Host/Kyllikki
TOOLCHAIN?=diab532# Used toolchain
UNIT_TESTS?=No# Include unit tests switch: Yes/No
VERBOSE?=1# Verbose mode: 0, 1, 2, 3

# Basic define for test builds (keep it first) --------------------------------#

ifeq (Yes,$(UNIT_TESTS))
  TESTS_CPPFLAGS+= -DTESTS_BUILDING_FOR_TESTS
else
  TESTS_CPPFLAGS+= -DTESTS_BUILDING_FOR_PRODUCTION
endif

# Set verbose level -----------------------------------------------------------#

ifeq ($(VERBOSE),0)
  # 0: Print nothing
  TESTS_VAR_VERBOSE=@
endif
ifeq ($(VERBOSE),1)
  # 1: Print "echo [UNIT TESTS] ~~       target"
  TESTS_VAR_VERBOSE=@$(info [UNIT TESTS] ~~       $@) $(TESTS_VAR_RECIPEPREFIX)@
endif
ifeq ($(VERBOSE),2)
  # 2: Print "command"
  TESTS_VAR_VERBOSE=
endif
ifeq ($(VERBOSE),3)
  # 3: Print "echo [UNIT TESTS] ~~       target" and "command" 
  TESTS_VAR_VERBOSE=$(info [UNIT TESTS] ~~       $@) $(TESTS_VAR_RECIPEPREFIX)
endif

# Initialize internal variables -----------------------------------------------#
TESTS_DIR_TESTS:=tests
TESTS_DIR_ENVIRONMENT:=$(TESTS_DIR_TESTS)/environment
TESTS_DIR_TARGETS:=$(TESTS_DIR_TESTS)/targets
TESTS_DIR_TOOLCHAINS:=$(TESTS_DIR_TESTS)/toolchains
TESTS_DIR_FRAMEWORKS:=$(TESTS_DIR_TESTS)/frameworks
TESTS_DIR_UOAM_TESTS:=$(TESTS_DIR_TESTS)/uoam_tests

TESTS_DIR_OUT=$(TESTS_DIR_TARGETS)/$(TESTS_VAR_TOOLCHAIN)

TESTS_VAR_SEPARATOR_MESSAGE=@$(call TESTS_CMD_ECHO,------------------------------------------------------------------------------)
TESTS_VAR_ENTRY_MESSAGE+=$(info [UNIT TESTS] INFO:    Building for TARGET / TOOLCHAIN: "$(TESTS_VAR_TOOLCHAIN)", UNIT_TESTS: $(UNIT_TESTS))
TESTS_VAR_EXIT_MESSAGE+=@$(call TESTS_CMD_ECHO,[UNIT TESTS] INFO:    All done!)
TESTS_VAR_RUN_MESSAGE+=$(info [UNIT TESTS] INFO:    Running tests)

# Browse for pluggable stuff --------------------------------------------------#

#  Import the build environment
include $(wildcard $(TESTS_DIR_ENVIRONMENT)/*.mk)

# GNU Make has RECIPEPREFIX, emake has a colon
ifeq ($(TAB),$(.RECIPEPREFIX))
  TESTS_VAR_RECIPEPREFIX=$(.RECIPEPREFIX)
else
  TESTS_VAR_RECIPEPREFIX=;
endif

#  Import avaliable toolchains
include $(wildcard $(TESTS_DIR_TOOLCHAINS)/*.mk)

# Nice printing ---------------------------------------------------------------#
$(TESTS_VAR_ENTRY_MESSAGE)

# Parse build switches and configure the build process ------------------------#
TESTS_VAR_GOALS_SUPPORTED+=all build clean cycle
ifeq (,$(findstring $(MAKECMDGOALS),$(TESTS_VAR_GOALS_SUPPORTED)))
  $(error ERROR [UNIT TESTS]:   Unsupported goal: "$(MAKECMDGOALS)". Supported values: $(TESTS_VAR_GOALS_SUPPORTED))
endif

TESTS_VAR_TARGET_SUPPORTED:=Local Kyllikki Host
ifeq (,$(findstring $(TARGET),$(TESTS_VAR_TARGET_SUPPORTED)))
  $(error ERROR [UNIT TESTS]:   Unsupported TARGET: "$(TARGET)". Supported values: $(TESTS_VAR_TARGET_SUPPORTED))
endif
 
TESTS_VAR_UNIT_TESTS_SUPPORTED:=Yes No
ifeq (,$(findstring $(UNIT_TESTS),$(TESTS_VAR_UNIT_TESTS_SUPPORTED)))
  $(error ERROR [UNIT TESTS]:   Unsupported UNIT_TESTS: "$(UNIT_TESTS)". Supported values: $(TESTS_VAR_UNIT_TESTS_SUPPORTED))
endif

TESTS_VAR_UNIT_PATHS_CUSTOM_SUPPORTED:=Yes No
ifeq (,$(findstring $(PATHS_CUSTOM),$(TESTS_VAR_UNIT_PATHS_CUSTOM_SUPPORTED)))
  $(error ERROR [UNIT TESTS]:   Unsupported PATHS_CUSTOM: "$(PATHS_CUSTOM)". Supported values: $(TESTS_VAR_UNIT_PATHS_CUSTOM_SUPPORTED))
endif

ifneq ($(TESTS_VAR_TOOLCHAIN_OK),1)
$(error ERROR [UNIT TESTS]:   Invalid TARGET / TOOLCHAIN pair: "$(TARGET) / $(TOOLCHAIN)")
endif

TESTS_VAR_VERBOSE_SUPPORTED:=0 1 2 3
ifeq (,$(findstring $(VERBOSE),$(TESTS_VAR_VERBOSE_SUPPORTED)))
  $(error ERROR [UNIT TESTS]:   Unsupported VERBOSE: "$(VERBOSE)". Supported values: $(TESTS_VAR_VERBOSE_SUPPORTED))
endif

# -----------------------------------------------------------------------------#

#  Import available test frameworks/plugins/extensions
include $(wildcard $(TESTS_DIR_FRAMEWORKS)/*.mk)

#  Import code under test
include $(TESTS_DIR_TESTS)/code_under_test.mk

# Calculate internal variables ------------------------------------------------#

# Library name, executable name
TESTS_LIB_LIBRARY:=$(TESTS_DIR_LIBRARY)/sample_code_szymon_gutaj_unit_tests$(TESTS_EXT_LIB)
TESTS_EXE_EXECUTABLE:=$(TESTS_DIR_OUT)/sample_code_szymon_gutaj_unit_tests$(TESTS_EXT_EXE)

# Main function: compose name (mainLocalUnitTestsYes, mainLocalUnitTestsNo, mainHostUnitTestsYes)
TESTS_VAR_MAIN_FUNCTION_NAME:=main$(TARGET)UnitTests$(UNIT_TESTS)

# Main function
TESTS_SRC_MAIN_FUNCTION:=$(TESTS_DIR_UOAM_TESTS)/$(TESTS_VAR_MAIN_FUNCTION_NAME)$(TESTS_EXT_SRC)
TESTS_OBJ_MAIN_FUNCTION:=$(TESTS_DIR_OUT)/main$(TESTS_EXT_OBJ)
TESTS_DEP_MAIN_FUNCTION:=$(subst $(TESTS_EXT_OBJ),$(TESTS_EXT_DEP),$(TESTS_OBJ_MAIN_FUNCTION))

# Main target -----------------------------------------------------------------#
.PHONY: all Debug
all: $(TARGET)
	$(TESTS_VAR_EXIT_MESSAGE)

.PHONY: build
build:
	$(info [UNIT TESTS] INFO:    build: TODO!)
	$(TESTS_VAR_EXIT_MESSAGE)

# Make a local target ---------------------------------------------------------#
.PHONY: Local Kyllikki
Local Kyllikki: $(TESTS_LIB_LIBRARY)

ifeq ($(UNIT_TESTS),Yes)
TESTS_OBJ_LIBRARY_CONTENTS:=$(TESTS_OBJ_MAIN_FUNCTION) \
                            $(TESTS_LIB_EXTRA_LIBS) \
                            $(TESTS_OUT_CONTENTS)
                            
TESTS_XXX_LIBRARY_PREREQUISITES:=$(TESTS_OUT_PREREQUISITES)
else
TESTS_OBJ_LIBRARY_CONTENTS:=$(TESTS_OBJ_MAIN_FUNCTION) \
                            $(TESTS_LIB_EXTRA_LIBS)
endif

$(TESTS_LIB_LIBRARY): $(TESTS_OBJ_LIBRARY_CONTENTS) \
                      $(TESTS_XXX_LIBRARY_PREREQUISITES)
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_AR) $(TESTS_ARFLAGS)$(TESTS_OPT_LIB) \
	$@ \
	$(TESTS_OBJ_LIBRARY_CONTENTS)

# Make a host target: ---------------------------------------------------------#
.PHONY: Host
Host: tests_run

.PHONY: tests_run
# pragma runlocal
tests_run: $(TESTS_EXE_EXECUTABLE)
	$(TESTS_VAR_RUN_MESSAGE)
	$(TESTS_VAR_SEPARATOR_MESSAGE)
	$(TESTS_EXE_EXECUTABLE) $(EXE_PARAMS)
	$(TESTS_VAR_SEPARATOR_MESSAGE)

# Executable: link and create
$(TESTS_EXE_EXECUTABLE): $(TESTS_OBJ_MAIN_FUNCTION) \
                         $(TESTS_LIB_EXTRA_LIBS) \
                         $(TESTS_OUT_CONTENTS) \
                         $(TESTS_OUT_CODE_UNDER_TEST) \
                         $(TESTS_OUT_PREREQUISITES)
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_LNK) $(TESTS_LNKFLAGS) \
    $(TESTS_OPT_EXE)$@ \
    $(TESTS_OBJ_MAIN_FUNCTION) \
    $(TESTS_LIB_EXTRA_LIBS) \
    $(TESTS_OUT_CONTENTS) \
    $(TESTS_OUT_CODE_UNDER_TEST)

# Common to all targets -------------------------------------------------------#
# Main function: object
$(TESTS_OBJ_MAIN_FUNCTION): $(TESTS_DEP_MAIN_FUNCTION)
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_CXX) -c $(TESTS_CPPFLAGS) $(TESTS_CXXFLAGS) \
    $(TESTS_OPT_OBJ)$@ \
    $(TESTS_SRC_MAIN_FUNCTION)

-include $(TESTS_DEP_MAIN_FUNCTION)

# Main function: dependencies
$(TESTS_DEP_MAIN_FUNCTION): $(TESTS_SRC_MAIN_FUNCTION) | tests_directories
	$(TESTS_VAR_VERBOSE)\
    $(TESTS_DEP) $(TESTS_CPPFLAGS) $(TESTS_DEPFLAGS) \
    $(TESTS_OPT_DEP)$@ \
    $<

# Output directories ----------------------------------------------------------#
.PHONY: tests_directories
# pragma runlocal
tests_directories:
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CMD_MKDIR,$(sort $(dir $(TESTS_OBJ_MAIN_FUNCTION))))	

# Clean target ----------------------------------------------------------------#
.PHONY: clean
# pragma runlocal
clean:
	$(TESTS_VAR_VERBOSE)\
    $(call TESTS_CMD_RM,$(TESTS_DIR_OUT))
	$(TESTS_VAR_EXIT_MESSAGE)

.PHONY: debug
debug:
	$(info TESTS_OUT_CONTENTS: $(TESTS_OUT_CONTENTS))
