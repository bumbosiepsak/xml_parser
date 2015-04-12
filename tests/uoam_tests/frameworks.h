/**
    @b Project: Wump
    @file        frameworks.h
    @author      Szymon Gutaj
    @brief       
    @date        28-03-2011
    @version     0.1
    @b History:
     - 28-03-2011
       - sgutaj
         - Initial creation
*/

#ifndef TESTS_FRAMEWORKS_H_INCLUDED_
#define TESTS_FRAMEWORKS_H_INCLUDED_

#include <vector>

namespace uoam_tests {

class frameworks
{
    typedef int (*framework_main)(int argc, char **argv);
    typedef std::vector<framework_main> framework_main_collection;

private:
    frameworks() : bound_frameworks() {}

    static frameworks &instance()
    {
        static frameworks f;
        return f;
    }

public:
    inline static void bind(framework_main main)
    {
        frameworks::instance().bound_frameworks.push_back(main);
    }

    static int run(int argc, char **argv)
    {
        framework_main_collection &f = frameworks::instance().bound_frameworks;

        for(framework_main_collection::iterator main = f.begin(); main != f.end(); ++main)
        {
            (void)(*main)(argc, argv);
        }

        return 0;
    }

private:
     framework_main_collection bound_frameworks;

public:
    struct binder
    {
        explicit binder(framework_main main)
        {
            frameworks::bind(main);
        }
    };
};

}

#endif /* TESTS_FRAMEWORKS_H_INCLUDED_ */
