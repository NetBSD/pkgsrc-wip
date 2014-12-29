# by nros@users.sf.net
# public domain (WTFPL license)

cmake_minimum_required(VERSION 3.0)
include(GNUInstallDirs)
project(eps C)

set(INCS line.h buffer.h unfold.h content.h eps.h int_stream.h rfc2822.h 
         misc.h interface.h  header.h email.h boundary.h mime.h 
         address.h base64.h fold.h int_buffer.h qp.h date.h)

set(SRCS line.c buffer.c unfold.c eps.c int_stream.c rfc2822.c misc.c 
         header.c email.c boundary.c mime.c address.c base64.c fold.c
         int_buffer.c qp.c date.c)

include_directories(${CMAKE_SOURCE_DIR})
#add_compile_options(-Wall)
add_library(eps-static STATIC ${SRCS})
add_library(eps-shared SHARED ${SRCS})
set_target_properties(eps-static eps-shared PROPERTIES OUTPUT_NAME eps)

install(TARGETS eps-static eps-shared
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
       )

install(FILES ${INCS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/eps) 
