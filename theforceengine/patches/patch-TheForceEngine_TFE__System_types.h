$NetBSD$

Include stddef.h for size_t

--- TheForceEngine/TFE_System/types.h.orig	2023-05-27 05:02:04.000000000 +0000
+++ TheForceEngine/TFE_System/types.h
@@ -1,5 +1,6 @@
 #pragma once
 
+#include <stddef.h>
 #include <stdint.h>
 #include <math.h>
 #include <float.h>
@@ -137,4 +138,4 @@ enum AssetPool
 	POOL_GAME = 0,
 	POOL_LEVEL,
 	POOL_COUNT
-};
\ No newline at end of file
+};
