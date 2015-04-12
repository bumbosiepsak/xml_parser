#   @b Project: Wump
#   @file        paths.mk
#   @author      Szymon Gutaj
#   @brief       Defines project-specific and environment-specific paths
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

# Environment-dependent -------------------------------------------------------#
# Path to Diab compiler
TESTS_DIR_DIAB:=C:/APPS/diab/5.3.2/WIN32/bin/

# Path to gcc compiler
TESTS_DIR_GCC:=C:/Apps/MinGW/bin/

# Path to Microsoft Visual C compiler
TESTS_DIR_MSVC8:=c:/Apps/msvs/

# Path to python interpreter
TESTS_DIR_PYTHON:=C:/Apps/Python/

# Target-dependent ------------------------------------------------------------#
ifeq (Host,$(TARGET))
  # Host targets: use paths sacred in NSN
  
  # Path to Cygwin executables
  TESTS_DIR_CYGWIN:=C:/Apps/MinGW/msys/1.0/bin/

  # Path to OSE files
  TESTS_DIR_OSE:=C:/Apps/OSE/OSE5.3/

else

  # Local/Kyllikki targets: use standard, relative paths
  TESTS_DIR_CYGWIN=$(TESTS_DIR_PROJECT_ROOT)/cygwin/bin/
  TESTS_DIR_OSE=$(TESTS_DIR_PROJECT_ROOT)/OSE5.3/

endif
  
# Override paths if necessary
ifeq (Yes,$(PATHS_CUSTOM))
TESTS_VAR_ENTRY_MESSAGE+=$(info [UNIT TESTS] INFO:    Using custom paths, defined in "tests/environment/paths_custom.inc")
-include $(TESTS_DIR_ENVIRONMENT)/paths_custom.inc
endif

# Include project-specific paths
include $(TESTS_DIR_ENVIRONMENT)/paths_project.inc
