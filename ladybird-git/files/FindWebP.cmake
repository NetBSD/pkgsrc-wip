# XXXTNN I could not find the canonical source for this file,
# so I hacked up something loosely based on this:
# https://raw.githubusercontent.com/WebKit/WebKit/refs/heads/main/Source/cmake/FindWebP.cmake

find_package(PkgConfig QUIET)
pkg_check_modules(PC_WEBP QUIET libwebp)
pkg_check_modules(PC_WEBPDECODER QUIET libwebpdecoder)
pkg_check_modules(PC_WEBPDECODER QUIET libwebpdemux)
pkg_check_modules(PC_WEBPDECODER QUIET libwebpmux)
set(WebP_COMPILE_OPTIONS ${PC_WEBP_CFLAGS_OTHER})

find_path(WebP_INCLUDE_DIR
    NAMES webp/decode.h
    HINTS ${PC_WEBP_INCLUDEDIR} ${PC_WEBP_INCLUDE_DIRS}
)

find_library(WebP_LIBRARY
    NAMES ${WebP_NAMES} webp libwebp
    HINTS ${PC_WEBP_LIBDIR} ${PC_WEBP_LIBRARY_DIRS}
)

find_library(WebP_DECODER_LIBRARY
    NAMES ${WebP_DECODER_NAMES} webpdecoder
    HINTS ${PC_WEBPDECODER_LIBDIR} ${PC_WEBPDECODER_LIBRARY_DIRS}
)

find_library(WebP_DEMUX_LIBRARY
    NAMES ${WebP_DEMUX_NAMES} webpdemux
    HINTS ${PC_WEBPDEMUX_LIBDIR} ${PC_WEBPDEMUX_LIBRARY_DIRS}
)

find_library(WebP_MUX_LIBRARY
    NAMES ${WebP_MUX_NAMES} webpmux
    HINTS ${PC_WEBPMUX_LIBDIR} ${PC_WEBPMUX_LIBRARY_DIRS}
)

message(WARNING "${WebP_LIBRARY}")
message(WARNING "${WebP_DECODER_LIBRARY}")
message(WARNING "${WebP_DEMUX_LIBRARY}")
message(WARNING "${WebP_MUX_LIBRARY}")

if (WebP_LIBRARY AND NOT TARGET WebP::webp)
    add_library(WebP::webp UNKNOWN IMPORTED GLOBAL)
    set_target_properties(WebP::webp PROPERTIES
        IMPORTED_LOCATION "${WebP_LIBRARY}"
        INTERFACE_COMPILE_OPTIONS "${WebP_COMPILE_OPTIONS}"
        INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}"
    )
endif ()

if (WebP_DECODER_LIBRARY AND NOT TARGET WebP::webpdecoder)
    add_library(WebP::webpdecoder UNKNOWN IMPORTED GLOBAL)
    set_target_properties(WebP::webpdecoder PROPERTIES
        IMPORTED_LOCATION "${WebP_DECODER_LIBRARY}"
        INTERFACE_COMPILE_OPTIONS "${WebP_COMPILE_OPTIONS}"
        INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}"
    )
    target_link_libraries(WebP::webpdecoder INTERFACE WebP::webp)
endif ()

if (WebP_DEMUX_LIBRARY AND NOT TARGET WebP::webpdemux)
    add_library(WebP::webpdemux UNKNOWN IMPORTED GLOBAL)
    set_target_properties(WebP::webpdemux PROPERTIES
        IMPORTED_LOCATION "${WebP_DEMUX_LIBRARY}"
        INTERFACE_COMPILE_OPTIONS "${WebP_COMPILE_OPTIONS}"
        INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}"
    )
    target_link_libraries(WebP::webpdemux INTERFACE WebP::webp)
endif ()

if (WebP_MUX_LIBRARY AND NOT TARGET WebP::libwebpmux)
    add_library(WebP::libwebpmux UNKNOWN IMPORTED GLOBAL)
    set_target_properties(WebP::libwebpmux PROPERTIES
        IMPORTED_LOCATION "${WebP_MUX_LIBRARY}"
        INTERFACE_COMPILE_OPTIONS "${WebP_COMPILE_OPTIONS}"
        INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}"
    )
    target_link_libraries(WebP::libwebpmux INTERFACE WebP::webp)
endif ()

if (WebP_FOUND)
    set(WebP_LIBRARIES ${WebP_LIBRARY} ${WebP_DECODER_LIBRARY} ${WebP_DEMUX_LIBRARY} ${WebP_MUX_LIBRARY})
    set(WebP_INCLUDE_DIRS ${WebP_INCLUDE_DIR})
endif ()
