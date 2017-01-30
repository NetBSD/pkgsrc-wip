--- ./source/gmqcc/gmqcc.h.old	2017-01-29 00:50:17.690470085 -0800
+++ ./source/gmqcc/gmqcc.h	2017-01-29 00:50:41.735428133 -0800
@@ -104,7 +104,7 @@
 #define GMQCC_BYTE_ORDER_BIG    4321
 
 #if defined (__GNUC__) || defined (__GNU_LIBRARY__)
-#   if defined (__FreeBSD__) || defined (__OpenBSD__)
+#   if defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__)
 #       include <sys/endian.h>
 #   elif defined (BSD) && (BSD >= 199103) || defined (__DJGPP__) || defined (__CYGWIN32__)
 #       include <machine/endian.h>
