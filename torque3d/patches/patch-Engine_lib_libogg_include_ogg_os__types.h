$NetBSD$

--- Engine/lib/libogg/include/ogg/os_types.h.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/lib/libogg/include/ogg/os_types.h
@@ -138,6 +138,15 @@
    typedef unsigned int ogg_uint32_t;
    typedef long long int ogg_int64_t;
 
+#elif defined(__NetBSD__)
+
+#  include <stdint.h>
+   typedef int16_t ogg_int16_t;
+   typedef uint16_t ogg_uint16_t;
+   typedef int32_t ogg_int32_t;
+   typedef uint32_t ogg_uint32_t;
+   typedef int64_t ogg_int64_t;
+
 #else
 
 #  include <ogg/config_types.h>
