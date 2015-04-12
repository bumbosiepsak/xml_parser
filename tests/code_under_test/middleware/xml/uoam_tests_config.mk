#   @b Project: Wump
#   @file        uoam_tests_config.mk
#   @author      Szymon Gutaj
#   @brief       
#   @date        01-04-2011
#   @version     0.1
#   @b History:
#    - 01-04-2011
#      - sgutaj
#        - Initial creation

TESTS_SRC_CODE_UNDER_TEST+=$(wildcard $(TESTS_DIR_UOAM_SOURCES)/middleware/xml/*$(TESTS_EXT_SRC))
TESTS_SRC_CODE_UNDER_TEST+=$(wildcard $(TESTS_DIR_UOAM_SOURCES)/middleware/xml/impl/*$(TESTS_EXT_SRC))
