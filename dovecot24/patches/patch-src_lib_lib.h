$NetBSD$

- Fix needing to define _NETBSD_SOURCE by disabling the whole dubious lot
  of visibility defines.

- Fix re-definition warnings like

CC       welcome-plugin.lo
In file included from welcome-plugin.c:3:
../../../src/lib/lib.h:79: warning: "memcpy" redefined
   79 | #  define memcpy(dest, src, n) i_memcpy(dest, src, n)
      |
In file included from /usr/include/string.h:127,
                 from ../../../src/lib/lib.h:22:
/usr/include/ssp/string.h:95: note: this is the location of the previous definition
   95 | #define memcpy(dst, src, len) __ssp_bos_check3(memcpy, dst, src, len)
      |

--- ./src/lib/lib.h.orig	2025-10-29 06:58:41.000000000 +0000
+++ ./src/lib/lib.h
@@ -1,15 +1,15 @@
 #ifndef LIB_H
 #define LIB_H
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
-#  define __BSD_VISIBLE 1
-#elif defined(__APPLE__)
-#  define _DARWIN_C_SOURCE 1
-#endif
-#define _BSD_SOURCE 1
-#define _DEFAULT_SOURCE 1
-#define _POSIX_C_SOURCE 200809L
-#define _XOPEN_SOURCE 700
+//#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+//#  define __BSD_VISIBLE 1
+//#elif defined(__APPLE__)
+//#  define _DARWIN_C_SOURCE 1
+//#endif
+//#define _BSD_SOURCE 1
+//#define _DEFAULT_SOURCE 1
+//#define _POSIX_C_SOURCE 200809L
+//#define _XOPEN_SOURCE 700
 
 /* default lib includes */
 #ifdef HAVE_CONFIG_H
@@ -76,6 +76,7 @@ static inline void *i_memcpy(void *dest,
 	return memcpy(dest, src, n);
 }
 #ifndef __cplusplus
+#  undef memcpy /* /usr/include/ssp/string.h:95 already defined this; the above i_memcpy() will use that definition. */
 #  define memcpy(dest, src, n) i_memcpy(dest, src, n)
 #endif
 
