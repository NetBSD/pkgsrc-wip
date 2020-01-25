$NetBSD$

* bstring.h is needed for bzero on some platforms

--- storage/ndb/include/ndb_global.h.orig	2020-01-21 17:16:34.989126305 +0000
+++ storage/ndb/include/ndb_global.h
@@ -126,6 +126,10 @@
 #include <strings.h>
 #endif
 
+#ifdef HAVE_BSTRING_H
+#include <bstring.h>  // defines bzero on some platforms
+#endif
+
 #if !defined(bzero) && !defined(HAVE_BZERO)
 #define bzero(A,B) memset((A),0,(B))
 #endif
