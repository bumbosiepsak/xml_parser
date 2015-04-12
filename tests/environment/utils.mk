#   @b Project: Wump
#   @file        utils.mk
#   @author      Szymon Gutaj
#   @brief       Defines useful stuff
#   @date        30-03-2011
#   @version     0.1
#   @b History:
#    - 30-03-2011
#      - sgutaj
#        - Initial creation

COLON:=,
NEWLINE:=\n
NULLSTRING:=
SPACE:= $(NULLSTRING) #
TAB:=	$(NULLSTRING)

# Convert filename to valid C++ name by substituting any invalid chars to _ (underscore)
TESTS_TO_CXX_NAME=$(subst /,_,$(subst .,_,$(subst -,_,$1)))
