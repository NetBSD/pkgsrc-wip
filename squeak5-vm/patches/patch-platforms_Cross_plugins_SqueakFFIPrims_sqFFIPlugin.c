$NetBSD$

--- platforms/Cross/plugins/SqueakFFIPrims/sqFFIPlugin.c.orig	2023-12-18 14:41:18.000000000 +0000
+++ platforms/Cross/plugins/SqueakFFIPrims/sqFFIPlugin.c
@@ -11,7 +11,7 @@
 
 #include <stdio.h>
 #include <stdlib.h> /* proto for alloca in MINGW */
-#if !_WIN32 && !__FreeBSD__ && !__OpenBSD__
+#if !_WIN32 && !__FreeBSD__ && !__OpenBSD__ && !__NetBSD__
 # include <alloca.h>
 #endif
 #include <string.h>
