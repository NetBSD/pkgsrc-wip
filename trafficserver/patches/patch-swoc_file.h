$NetBSD$

- Need to include climits for NetBSD

diff --git lib/swoc/include/swoc/swoc_file.h lib/swoc/include/swoc/swoc_file.h
index 7e9423969b..52b586ef7f 100644
--- lib/swoc/include/swoc/swoc_file.h
+++ lib/swoc/include/swoc/swoc_file.h
@@ -7,6 +7,10 @@
 
 #pragma once
 
+#if defined(__NetBSD__)
+#include <climits>
+#endif
+
 #include <unistd.h>
 #include <sys/stat.h>
 
