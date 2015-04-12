#   @b Project: Wump
#   @file        shell.mk
#   @author      Szymon Gutaj
#   @brief       Defines the shell-specific settings
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

ifneq ($(windir),)
# Windows (ComSpec variable should be used, but it's suppressed by emake)
  ifneq ($(wildcard $(TESTS_DIR_CYGWIN)),$(TESTS_DIR_CYGWIN))
    $(error ERROR (UNIT TESTS):   Posix shell (Cygwin) not found under path: "$(TESTS_DIR_CYGWIN)"! Please customize TESTS_DIR_CYGWIN in "tests/environment/paths_custom.inc") 
  endif

  TESTS_CMD_CAT="$(TESTS_DIR_CYGWIN)cat" $1
  TESTS_CMD_CD="$(TESTS_DIR_CYGWIN)cd" $1
  TESTS_CMD_CP="$(TESTS_DIR_CYGWIN)cp" -f -R -u $1 $2
  TESTS_CMD_ECHO="$(TESTS_DIR_CYGWIN)echo" $1
  TESTS_CMD_MKDIR="$(TESTS_DIR_CYGWIN)mkdir" -p $1
  TESTS_CMD_PRINTF="$(TESTS_DIR_CYGWIN)printf" "$1"
  TESTS_CMD_RM="$(TESTS_DIR_CYGWIN)rm" -rf $1
  TESTS_CMD_TOUCH="$(TESTS_DIR_CYGWIN)touch" $1
else
# Unix
  TESTS_CMD_CAT=cat $1
  TESTS_CMD_CD=cd $1
  TESTS_CMD_COPY=cp -f -R -u $1 $2
  TESTS_CMD_ECHO=echo $1
  TESTS_CMD_MD=mkdir -p $1
  TESTS_CMD_PRINTF=printf $1
  TESTS_CMD_RM=rm -rf $1
  TESTS_CMD_TOUCH=touch $1
endif
