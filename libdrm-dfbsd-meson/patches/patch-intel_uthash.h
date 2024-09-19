$NetBSD$

--- intel/uthash.h.orig	2019-03-12 11:55:31.000000000 +0000
+++ intel/uthash.h
@@ -71,7 +71,7 @@ do {                                    
 typedef unsigned int uint32_t;
 typedef unsigned char uint8_t;
 #endif
-#elif defined(__GNUC__) && !defined(__VXWORKS__)
+#elif ((defined(STRICT_XSRC_NETBSD) && defined(__lint__)) || defined(__GNUC__)) && !defined(__VXWORKS__)
 #include <stdint.h>
 #else
 typedef unsigned int uint32_t;
