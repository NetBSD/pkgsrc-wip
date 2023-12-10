$NetBSD$

Needs alloca.h on SunOS.

--- src/Standard/Standard_Failure.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/Standard/Standard_Failure.cxx
@@ -23,6 +23,10 @@
 
 #include <string.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 IMPLEMENT_STANDARD_RTTIEXT(Standard_Failure,Standard_Transient)
 
 namespace
