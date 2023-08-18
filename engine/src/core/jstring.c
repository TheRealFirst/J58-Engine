#include "jstring.h"
#include "jmemory.h"

#include <string.h>

u64 string_length(const char* str){
    return strlen(str);
}

char* string_duplicate(const char* str) {
    u64 length = string_length(str);
    char* copy = jallocate(length + 1, MEMORY_TAG_STRING);
    jcopy_memory(copy, str, length + 1);
    return copy;
}

