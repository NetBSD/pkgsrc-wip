$NetBSD$

pkgsrc specific tcl header inclusion path

--- kernel/tclapi.cc.orig	2025-01-04 08:43:33.097801805 +0000
+++ kernel/tclapi.cc
@@ -23,8 +23,8 @@
 
 #ifdef YOSYS_ENABLE_TCL
 #include <tcl.h>
-#include <tclTomMath.h>
-#include <tclTomMathDecls.h>
+#include <tcl/generic/tclTomMath.h>
+#include <tcl/generic/tclTomMathDecls.h>
 #endif
 
 YOSYS_NAMESPACE_BEGIN
