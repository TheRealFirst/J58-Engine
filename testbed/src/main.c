#include <core/logger.h>
#include <core/asserts.h>

// TODO: Test
#include <platform/platform.h>

int main(void){
    JFATAL("A test message: %f", 3.14f);
    JERROR("A test message: %f", 3.14f);
    JWARN("A test message: %f", 3.14f);
    JINFO("A test message: %f", 3.14f);
    JDEBUG("A test message: %f", 3.14f);
    JTRACE("A test message: %f", 3.14f);

    platform_state state;
    if(platform_startup(&state, "J58 Engine Testbed", 100, 100, 1280, 720)){
        while (TRUE)
        {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}