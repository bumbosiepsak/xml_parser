/**
    @b Project: Wump
    @file        encoding_specific_ascii.cpp
    @author      Szymon Gutaj
    @brief
    @date        03-04-2011
    @b History:
     - 03-04-2011 (sgutaj)
      - Initial creation
*/

#include <middleware/xml/impl/encoding_specific_ascii.h>

using namespace ::middleware::xml;
using namespace ::middleware::xml::impl;

xml_decl const encoding_specific<ascii>::decl = {'<','?','x','m'};

xml_encoding_name const encoding_specific<ascii>::encoding_name = {'U','T','F','-','8'}; // FIXME (sgutaj)! What's the tag for ASCII?
