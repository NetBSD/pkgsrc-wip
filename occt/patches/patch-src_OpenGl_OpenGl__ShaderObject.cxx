$NetBSD$

Needs alloca.h on SunOS.

--- src/OpenGl/OpenGl_ShaderObject.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/OpenGl/OpenGl_ShaderObject.cxx
@@ -26,6 +26,10 @@
   #include <malloc.h> // for alloca()
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 IMPLEMENT_STANDARD_RTTIEXT(OpenGl_ShaderObject,OpenGl_Resource)
 
 //! Puts line numbers to the output of GLSL program source code.
