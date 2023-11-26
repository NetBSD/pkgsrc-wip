$NetBSD$

Include cmath for round() (exposed by turning pre-compiled headers off).

--- source/common/engine/palettecontainer.cpp.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/common/engine/palettecontainer.cpp
@@ -32,6 +32,7 @@
 **
 */
 
+#include <cmath>
 #include "palutil.h"
 #include "sc_man.h"
 #include "m_crc32.h"
