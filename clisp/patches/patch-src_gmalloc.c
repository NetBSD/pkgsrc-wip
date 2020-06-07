$NetBSD$

--- src/gmalloc.c.orig	2019-11-03 21:40:38.000000000 +0000
+++ src/gmalloc.c
@@ -1911,7 +1911,14 @@ Fifth Floor, Boston, MA 02110-1301, USA.
 extern size_t __getpagesize PP ((void));
 #endif
 #else
+#ifdef __NetBSD__
+/* XXX can't include <unistd.h> as one should,
+ * since that will pull in gllib/unistd.h instead!
+ */
+extern int getpagesize();
+#else
 #include "getpagesize.h"
+#endif
 #define	 __getpagesize()	getpagesize()
 #endif
 
