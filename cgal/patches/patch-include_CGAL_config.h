$NetBSD$

--- include/CGAL/config.h.orig	2017-09-20 19:00:13.000000000 +0000
+++ include/CGAL/config.h
@@ -325,6 +325,15 @@
 #  else
 #    error Unknown endianness
 #  endif
+#elif defined(__NetBSD__)
+#  include <sys/endian.h>
+#  if _BYTE_ORDER == _LITTLE_ENDIAN
+#    define CGAL_LITTLE_ENDIAN
+#  elif _BYTE_ORDER == _BIG_ENDIAN
+#    define CGAL_BIG_ENDIAN
+#  else
+#  error Unknown endianness
+#  endif
 #elif defined(__sparc) || defined(__sparc__) \
    || defined(_POWER) || defined(__powerpc__) \
    || defined(__ppc__) || defined(__hppa) \
