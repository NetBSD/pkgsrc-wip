$NetBSD$

--- third_party/angle/src/compiler/translator/InfoSink.h.orig	2020-07-15 19:01:32.000000000 +0000
+++ third_party/angle/src/compiler/translator/InfoSink.h
@@ -7,7 +7,7 @@
 #ifndef COMPILER_TRANSLATOR_INFOSINK_H_
 #define COMPILER_TRANSLATOR_INFOSINK_H_
 
-#include <math.h>
+#include <cmath>
 #include <stdlib.h>
 #include "compiler/translator/Common.h"
 #include "compiler/translator/Severity.h"
