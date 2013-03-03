$NetBSD: patch-opennurbs__memory.c,v 1.1 2013/03/03 21:15:03 othyro Exp $

Needs line terminator.

--- opennurbs_memory.c.orig	2012-10-23 08:33:46.000000000 +0000
+++ opennurbs_memory.c
@@ -113,7 +113,7 @@ size_t onmsize( const void* memblock )
     // platform, then report it to the support
     // contact on http://opennurbs.org and
     // the code will be added in the next release.
-    ON_ERROR("onmsize not implemented on this compiler or platform.")
+    ON_ERROR("onmsize not implemented on this compiler or platform.");
     sz = 0;
 #endif
   }
