$NetBSD$

- Include csstdarg for NetBSD

diff --git include/tsutil/DbgCtl.h include/tsutil/DbgCtl.h
index d20cf31b09..f143433fab 100644
--- include/tsutil/DbgCtl.h
+++ include/tsutil/DbgCtl.h
@@ -29,6 +29,9 @@
 #include <atomic>
 #include <utility>
 #include <functional>
+#if defined(__NetBSD__)
+#include <cstdarg>
+#endif
 
 #include <ts/apidefs.h> // For TS_PRINTFLIKE
 
