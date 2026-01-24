/*#include "incl/MyTools.hpp" */
#include "incl/MyDisplay.hpp"
#include "incl/MyDebug.hpp"

int main ( void )
{
    MyDebug() << "Test DEBUG class" << 1;
    MyDisplay() << "Test DISPLAY class" << 2;

    return 0;
}
