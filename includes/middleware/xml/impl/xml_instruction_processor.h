/**
    @b Project: Wump
    @file        xml_instruction_processor.h
    @author      Szymon Gutaj
    @brief       Processes XML instructions, returning OK/NOK status.
    @date        19-03-2011
    @b History:
     - 19-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_INSTRUCTION_PROCESSOR_H_INCLUDED_
#define MIDDLEWARE_XML_XML_INSTRUCTION_PROCESSOR_H_INCLUDED_

#include <middleware/xml/fwd/rt/assoc_vector.h>
#include <middleware/xml/fwd/rt/from_table.h>

#include <middleware/xml/impl/xml_buffer_raw_utf.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Processes XML instructions, returning OK/NOK status.
 * \tparam Context Type of internal state of parser.
 */
template<class Context>
class xml_instruction_processor
{
public:
	/**
	 * Processes instruction.
	 * @param c Input data/context.
	 * @return Returns true if processing OK.
	 */
    static bool process_instruction(Context &c)
    {
        // TODO (sgutaj): Add instruction processing
        c.instruction.clear();
        return true;
    }

	/**
	 * Processes entity reference.
	 * @param c Input data/context.
	 * @return Returns true if processing OK.
	 */
    static bool process_entity_reference(Context &c)
    {
        bool r = (!c.instruction.empty())
              && (c.instruction.front() == '#') ?
                 (to_numeral(c.instruction, c.out)) :
                 (to_entity(c.instruction, c.out));

        c.instruction.clear();
        return r;
    }

private:
    typedef fwd::rt::assoc_vector<xml_buffer_raw_utf, code_point> entities_t;

    template<class In, class OutStream>
    static bool to_entity(In &in, OutStream &out)
    {
        entities_t::iterator e = entities.find(in);

        return ((e != entities.end()) ? (out.put(e->second), true) : false);
    }

    template<class In, class OutStream>
    static bool to_numeral(In &in, OutStream &out)
    {
        typename In::iterator i = ++in.begin(); // Skip the '#'

        code_point const base = (*i == 'x') ? (++i, 16U) : 10U;
        code_point p = 0U;

        for(;i != in.end(); ++i)
        {
            code_point lsd = *i;

            lsd -= (base == 10U) ? '0' : (lsd >= 'a') ? ('a'-0xA) : (lsd >= 'A') ? ('A'-0xA) : '0';

            if(base <= lsd) return false;

            p *= base; 
            p += lsd;
        }
        return ((p != 0U) ? (out.put(p), true) : false);
    }

private:
    static entities_t entities;
};

typedef fwd::rt::from_table<xml_buffer_raw_utf,1U> r2e;

template<class Context>
typename xml_instruction_processor<Context>::entities_t xml_instruction_processor<Context>::entities =
    xml_instruction_processor<Context>::entities_t()(r2e("amp"),'&')(r2e("apos"),'\'')(r2e("gt"),'>')(r2e("lt"),'<')(r2e("quot"),'\"').sort();

}}}

#endif /* MIDDLEWARE_XML_XML_INSTRUCTION_PROCESSOR_H_INCLUDED_ */
