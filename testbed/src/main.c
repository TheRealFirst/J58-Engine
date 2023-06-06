#include <core/logger.h>

int main(void){
    JFATAL("A test message: %f", 3.14f);
    JERROR("A test message: %f", 3.14f);
    JWARN("A test message: %f", 3.14f);
    JINFO("A test message: %f", 3.14f);
    JDEBUG("A test message: %f", 3.14f);
    JTRACE("A test message: %f", 3.14f);
    return 0; // 24:14
}