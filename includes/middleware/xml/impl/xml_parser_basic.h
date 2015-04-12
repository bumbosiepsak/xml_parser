/**
    @b Project: Wump
    @file        xml_parser_basic.h
    @author      Szymon Gutaj
    @brief       Core XML parser implementation. Builds an XML tree from input stream.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
         - Initial creation
     - 21-05-2011 (sgutaj)
         - Comments allowed at the beginning of XML
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_PARSER_BASIC_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_PARSER_BASIC_H_INCLUDED_

#include <middleware/xml/xml_node_type.h>
#include <middleware/xml/impl/code_point.h>
#include <middleware/xml/impl/xml_specific.h>
#include <middleware/xml/impl/xml_error_detail.h>
#include <middleware/xml/impl/xml_instruction_processor.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Implementation of XML parser (core engine).
 * \tparam Context Context (internal state) of processing.
 */
template<class Context>
class xml_parser_basic
{
public:
	/**
	 * Performs parsing, operating on data contained in context.
	 * @param context Internal state of computations.
	 */
    inline void parse(Context &context)
    {
        try
        {
            (void)root::at_beginning(context);
        }
        catch(std::bad_alloc &e)
        {
			(void)e;
            xml_parser_basic::internal_error(context, xml_error_detail::memory_allocation_failed);
        }
        catch(...)
        {
            xml_parser_basic::internal_error(context, xml_error_detail::no_details);
        }
    }
// ----------------------------------------------------------------------------
private:
    typedef xml_instruction_processor<Context> instruction_processor;


    /// Internal status used in traversing.
    enum status_t
    {
        ok  //!< All OK
       ,stay//!< All OK, stay on current nesting level
       ,err //!< Error
    };


    /// Process root level of XML.
    struct root
    {
    	/// At beginning of processing.
        static status_t at_beginning(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case '<':{
                        status_t s = root::at_opening_angle_bracket(c);
                        if(s != ok) return s;
                        return content::at_content(c);
                    }
                    case '\n': // Intentionally pass through
                    case '\r': // Intentionally pass through
                    case ' ' : // Intentionally pass through
                    case '\t': continue;
                }
                return xml_parser_basic::input_malformed(c, p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<"
        static status_t at_opening_angle_bracket(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case '?': return xml_declaration::at_xml_declaration(c);
                case '!': return any::at_exclamation_mark(c);
            }
            if(xml_specific::is_name_start_char(p)){
                xml_parser_basic::push_node(c, xml_node_type::element, p);
                return start_tag::at_tag(c);                
            }
            return xml_parser_basic::input_malformed(c, p);
        }
    };


    /// Process XML declaration.
    struct xml_declaration
    {
    	/// At "<?"
        static status_t at_xml_declaration(Context &c)
        {
            status_t s = processing_instruction::at_instruction(c);
            if(s != ok) return s;

            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case '<': return any::at_opening_angle_bracket(c);
                    case '\n': // Intentionally pass through
                    case '\r': // Intentionally pass through
                    case ' ' : // Intentionally pass through
                    case '\t': continue;
                }
                return xml_parser_basic::input_malformed(c, p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }
    };


    /// Process common XML bits.
    struct any
    {
    	/// At "<"
        static status_t at_opening_angle_bracket(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case '?': return processing_instruction::at_instruction(c);
                case '!': return any::at_exclamation_mark(c);
                case '/':{
                    xml_parser_basic::dump_value(c);
                    return end_tag::at_tag(c);
                }
            }
            if(xml_specific::is_name_start_char(p)){
                xml_parser_basic::dump_value(c);
                xml_parser_basic::push_node(c, xml_node_type::element, p);
                return start_tag::at_tag(c);
            }
            return xml_parser_basic::input_malformed(c, p);
        }

        /// At "<!"
        static status_t at_exclamation_mark(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case '-': return any::at_first_hyphen(c);
                case '[': return any::at_opening_square_bracket(c);
            }
            return xml_parser_basic::input_malformed(c, p);
        }

        /// At "<!-"
        static status_t at_first_hyphen(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case '-': return comment::at_comment(c);
            }
            return xml_parser_basic::input_malformed(c, p);
        }

        /// At "<!["
        static status_t at_opening_square_bracket(Context &c)
        {
            for(code_point const *r = cdata_markup; *r != 0x0; ++r)
            {
                code_point const p = c.in.get();
                switch(p){
                    case 0x0: // Intentionally pass through
                    case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
                }
                if(p != *r) return xml_parser_basic::input_malformed(c, p);
            }

            return CDATA_section::at_content(c);
        }
        static code_point const cdata_markup[];
    };


    /// Process instruction.
    struct processing_instruction
    {
    	/// At "<?"
        static status_t at_instruction(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case '?':{
                        status_t const s = processing_instruction::at_question_mark(c);
                        if(s != stay) return s;
                        continue;
                    }
                    case '&':{
                        status_t s = entity::at_entity(c);
                        if(s != stay) return s;
                        continue;
                    }
                    case 0x0: // Intentionally pass through
                    case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
                }
                c.instruction.push_back(p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<?Instruction ?"
        static status_t at_question_mark(Context &c)
        {
            code_point const p = c.in.get();
            if(p == '>'){
                return instruction_processor::process_instruction(c) ?
                       ok : xml_parser_basic::input_malformed(c, p);
            }
            switch(p){
                case '&': return entity::at_entity(c);
                case 0x0: // Intentionally pass through
                case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
            }

            c.instruction.push_back('?');
            c.instruction.push_back(p);
            return stay;
        }
    };


    /// Process start tag.
    struct start_tag
    {
    	/// At "<N"
        static status_t at_tag(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                if(xml_specific::is_name_char(p)){
                    c.out.put(p);
                    continue;
                }
                switch(p){
                    case ' ':{
                        xml_parser_basic::dump_name(c);
                        return attributes::at_attributes(c);
                    }
                    case '>':{
                        xml_parser_basic::dump_name(c);
                        return ok;
                    }
                    case '/':{
                        xml_parser_basic::dump_name(c);
                        return start_tag::at_tag_closing_slash(c);
                    }
                    case '&':{
                        status_t s = entity::at_entity(c);
                        if(s != stay) return s;
                        continue;
                    }
                }
                return xml_parser_basic::input_malformed(c, p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<Name /"
        static status_t at_tag_closing_slash(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case '>':{
                    xml_parser_basic::pop_node(c);
                    return ok;
                }
            }
            return xml_parser_basic::input_malformed(c, p);
        }
    };


    /// Process attributes.
    struct attributes
    {
    	/// At "<Name A"
        static status_t at_attributes(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                if(xml_specific::is_name_start_char(p)){
                    xml_parser_basic::push_node(c, xml_node_type::attribute, p);
                    status_t const s = attributes::at_tag(c);
                    if(s != stay) return s;
                    continue;
                }
                switch(p){
                    case '\n': // Intentionally pass through
                    case '\r': // Intentionally pass through
                    case ' ' : // Intentionally pass through
                    case '\t': continue;
                    case '/' : return start_tag::at_tag_closing_slash(c);
                    case '>' : return ok;
                    case '&':{
                        status_t s = entity::at_entity(c);
                        if(s != stay) return s;
                        continue;
                    }
                }
                return xml_parser_basic::input_malformed(c, p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<Name AttributeName"
        static status_t at_tag(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                if(xml_specific::is_name_char(p)){
                    c.out.put(p);
                    continue;
                }
                switch(p){
                    case '=':{
                        xml_parser_basic::dump_name(c);
                        return attributes::at_tag_equals(c);
                    }
                    case '&':{
                        status_t s = entity::at_entity(c);
                        if(s != stay) return s;
                        continue;
                    }
                }
                return xml_parser_basic::input_malformed(c, p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<Name AttributeName="
        static status_t at_tag_equals(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case '\'': // Intentionally pass through
                    case '\"': return attributes::at_content(c, p);
                }
                return xml_parser_basic::input_malformed(c, p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<Name AttributeName='"
        static status_t at_content(Context &c, code_point const quote)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                if(quote == p){
                    xml_parser_basic::dump_value(c);
                    xml_parser_basic::pop_node(c);
                    return stay;
                }
                switch(p){
                    case '&':{
                        status_t s = entity::at_entity(c);
                        if(s != stay) return s;
                        continue;
                    }
                    case 0x0: // Intentionally pass through
                    case '<': // Intentionally pass through
                    case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
                }
                c.out.put(p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }
    };


    /// Process end tag.
    struct end_tag
    {
    	/// At "<Name>Value</"
        static status_t at_tag(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                if(xml_specific::is_name_char(p)){
                    c.out.put(p);
                    continue;
                }
                switch(p){
                    case '&':{
                        status_t s = entity::at_entity(c);
                        if(s != stay) return s;
                        continue;
                    }
                    case '>':{
                        return (xml_parser_basic::compare_name(c) ? 
                               (xml_parser_basic::clear_buffer(c), xml_parser_basic::pop_node(c), ok) :
                                xml_parser_basic::input_malformed(c, p));
                    }
                }
                return xml_parser_basic::input_malformed(c, p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }
    };


    /// Process content.
    struct content
    {
    	/// Normalise newline to LFLF
        inline static code_point normalise_newline(Context &c, code_point const pp)
        {
            // LFLF -> LFLF, CRLF -> LF, LFCR -> LFLF, CRCR -> LFLF
            code_point const p = c.in.get();
            if(p == pp || p != '\n') c.out.put(static_cast<code_point>('\n'));
            return p;
        }

        /// Skip white space after newline
        inline static code_point skip_indentation(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case '\n': // Intentionally pass through
                    case '\r': // Intentionally pass through
                    case ' ' : // Intentionally pass through
                    case '\t': continue;
                }
                return p;
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<Name>Value"
        static status_t at_content(Context &c)
        {
            for(code_point p = c.in.get();;)
            {
                switch(p){
                    case '<':{
                        status_t const s = any::at_opening_angle_bracket(c);
                        if(s != ok) return s;
                        p = c.in.get();
                        continue;
                    }
                    case '&':{
                        status_t s = entity::at_entity(c);
                        if(s != stay) return s;
                        p = c.in.get();
                        continue;
                    }
                    case '\n': // Intentionally pass through
                    case '\r':{
                        if(c.preserve_whitespace){
                            p = content::normalise_newline(c, p); break;
                        }
                        else{
                            p = content::skip_indentation(c); continue;
                        }
                    }
                    case 0x0: // Intentionally pass through
                    case invalid_code_point:{
                        return (is_root(*c.path.back()) ?
                                ok : xml_parser_basic::input_malformed(c, p));
                    }
                }
                c.out.put(p);
                p = c.in.get();
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }
    };


    /// Process comment.
    struct comment
    {
    	/// At "<Name>Value<!--"
        static status_t at_comment(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case '-':{
                        status_t const s = comment::at_first_hyphen(c);
                        if(s != stay) return s;
                        continue;
                    }
                    case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
                }
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<Name>Value<!-- Comment -"
        static status_t at_first_hyphen(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case '-': return comment::at_second_hyphen(c);
            }
            return stay;
        }

        /// At "<Name>Value<!-- Comment --"
        static status_t at_second_hyphen(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case '-': return xml_parser_basic::input_malformed(c, p);
                case '>': return ok;
            }
            return stay;
        }
    };


    /// Process entities.
    struct entity
    {
    	/// At "<Name>Value&"
        static status_t at_entity(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case ';':{
                        return (instruction_processor::process_entity_reference(c) ?
                                stay : xml_parser_basic::input_malformed(c, p));
                    }
                    case 0x0:  // Intentionally pass through
                    case '<':  // Intentionally pass through
                    case '>':  // Intentionally pass through
                    case '&':  // Intentionally pass through
                    case '\"': // Intentionally pass through
                    case '\'': // Intentionally pass through
                    case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
                }
                c.instruction.push_back(p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }
    };


    /// Process CDATA section.
    struct CDATA_section
    {
    	/// At "<Name>Value<![CDATA["
        static status_t at_content(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case ']':{
                        status_t const s = CDATA_section::at_first_square_bracket(c);
                        if(s != stay) return s;
                        continue;
                    }
                    case 0x0:  // Intentionally pass through
                    case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
                }
                c.out.put(p);
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }

        /// At "<Name>Value<![CDATA[ cdata ]"
        static status_t at_first_square_bracket(Context &c)
        {
            code_point const p = c.in.get();
            switch(p){
                case ']': return CDATA_section::at_second_square_bracket(c);
                case 0x0:  // Intentionally pass through
                case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
            }
            c.out.put(']');
            c.out.put(p);
            return stay;
        }

        /// At "<Name>Value<![CDATA[ cdata ]]"
        static status_t at_second_square_bracket(Context &c)
        {
            for(;;)
            {
                code_point const p = c.in.get();
                switch(p){
                    case '>': return ok;
                    case ']':{
                        c.out.put(p);
                        continue;
                    }
                    case 0x0:  // Intentionally pass through
                    case invalid_code_point: return xml_parser_basic::input_malformed(c, p);
                }
                c.out.put(']');
                c.out.put(']');
                c.out.put(p);
                return stay;
            }
            return xml_parser_basic::internal_error(c, xml_error_detail::unexpected_control_flow);
        }
    };

// ----------------------------------------------------------------------------
private:
    static void push_node(Context &c, xml_node_type::value_type const t, code_point const p)
    {
        typedef typename Context::type node_type;

        c.out.put(p);
        // Add new child node to currently processed node
        c.path.back()->set_children().push_back(node_type(t));
        // Set new child node as currently processed
        c.path.push_back(&(c.path.back()->set_children().back()));
    }

    static void pop_node(Context &c)
    {
        c.path.pop_back();
    }

    static void dump_name(Context &c)
    {
        c.out.get_buffer().assign_to(c.path.back()->set_name());
        c.out.get_buffer().clear();
    }

    static bool compare_name(Context &c)
    {
        return c.out.get_buffer().compare(c.path.back()->get_name());
    }

    static void clear_buffer(Context &c)
    {
        c.out.get_buffer().clear();
    }

    static void dump_value(Context &c)
    {
        c.out.get_buffer().append_to(c.path.back()->set_value());
        c.out.get_buffer().clear();
    }

    // TODO (sgutaj): Add error details
    inline static status_t input_malformed(Context &c, code_point rotten, xml_error_detail::value_type error_detail = xml_error_detail::no_details)
    {
        c.out.put(rotten);
        c.error_detail = error_detail;

        return (c.status = xml_parser_status::input_malformed, err);
    }

    inline static status_t internal_error(Context &c, xml_error_detail::value_type error_detail)
    {
        c.error_detail = error_detail;

        return (c.status = xml_parser_status::internal_error, err);
    }
};

template<class Context>
code_point const xml_parser_basic<Context>::any::cdata_markup[] = {'C','D','A','T','A','[',0x0};

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_PARSER_BASIC_H_INCLUDED_ */
