s,^#include <sys/io\.h>,#ifndef __sun\
#include <sys/io.h>\
#endif,g
