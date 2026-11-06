$NetBSD$

- Include sysctl.h for NetBSD

diff --git src/tscore/ink_inet.cc src/tscore/ink_inet.cc
index 6d8f9eda5e..8134a6e0f3 100644
--- src/tscore/ink_inet.cc
+++ src/tscore/ink_inet.cc
@@ -34,6 +34,9 @@
 #include "tscore/ink_assert.h"
 #include "ts/apidefs.h"
 #include "tscore/ink_inet.h"
+#if defined(__NetBSD__)
+#include "sys/sysctl.h"
+#endif
 
 IpAddr const IpAddr::INVALID;
 
