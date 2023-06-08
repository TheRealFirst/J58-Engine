#include <core/logger.h>
#include <core/asserts.h>

int main(void){
    JFATAL("A test message: %f", 3.14f);
    JERROR("A test message: %f", 3.14f);
    JWARN("A test message: %f", 3.14f);
    JINFO("A test message: %f", 3.14f);
    JDEBUG("A test message: %f", 3.14f);
    JTRACE("A test message: %f", 3.14f);

    JASSERT(1 == 0);

    return 0;
}