#   @b Project: Wump
#   @file        paths_project.inc
#   @author      Szymon Gutaj
#   @brief       Defines project-specific and environment-specific paths
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 11-04-2011
#      - sgutaj
#        - Initial creation

TESTS_DIR_PROJECT_ROOT:=.
TESTS_DIR_BUILD:=$(TESTS_DIR_PROJECT_ROOT)/WMP_BUILD_RnD_OM/bin

# Path to code under test includes/sources ------------------------------------#

TESTS_DIR_MIDDLEWARE_INCLUDES:=includes
TESTS_DIR_UOAM_INCLUDES:=includes
TESTS_DIR_UOAM_SOURCES:=sources
TESTS_DIR_ALL:=$(TESTS_DIR_PROJECT_ROOT)

# Path to all include-searching directories -----------------------------------#
TESTS_DIR_CODE_UNDER_TEST_INCLUDES:=$(TESTS_DIR_MIDDLEWARE_INCLUDES) $(TESTS_DIR_UOAM_INCLUDES) $(TESTS_DIR_UOAM_RHAPSODY)