$NetBSD$

Needs alloca.h on SunOS.

--- src/OpenGl/OpenGl_ShaderProgram.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/OpenGl/OpenGl_ShaderProgram.cxx
@@ -30,6 +30,10 @@
   #include <malloc.h> // for alloca()
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 IMPLEMENT_STANDARD_RTTIEXT(OpenGl_ShaderProgram, OpenGl_NamedResource)
 
 OpenGl_VariableSetterSelector OpenGl_ShaderProgram::mySetterSelector = OpenGl_VariableSetterSelector();
