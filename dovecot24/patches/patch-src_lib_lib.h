$NetBSD$

Fix re-definition warnings like

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

--- src/lib/lib.h.orig	2026-02-03 17:35:03.025316093 +0000
+++ src/lib/lib.h
@@ -76,6 +76,7 @@ static inline void *i_memcpy(void *dest,
 	return memcpy(dest, src, n);
 }
 #ifndef __cplusplus
+#  undef memcpy /* /usr/include/ssp/string.h:95 already defined this; the above i_memcpy() will use that definition. */
 #  define memcpy(dest, src, n) i_memcpy(dest, src, n)
 #endif
 
