$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_InfoSink.h,v 1.1 2021/09/08 22:19:50 nia Exp $

* isinf/isnan in make.h is defined as macro. Use non-macro version
  to fix build.

--- gfx/angle/checkout/src/compiler/translator/InfoSink.h.orig	2022-01-06 20:11:53.000000000 +0000
+++ gfx/angle/checkout/src/compiler/translator/InfoSink.h
@@ -7,7 +7,7 @@
 #ifndef COMPILER_TRANSLATOR_INFOSINK_H_
 #define COMPILER_TRANSLATOR_INFOSINK_H_
 
-#include <math.h>
+#include <cmath>
 #include <stdlib.h>
 #include "GLSLANG/ShaderLang.h"
 #include "compiler/translator/Common.h"
