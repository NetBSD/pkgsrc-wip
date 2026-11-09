$NetBSD$

- stdarg required for NetBSD build.

diff --git include/tsutil/DbgCtl.h include/tsutil/DbgCtl.h
index d20cf31b09..910e7d4971 100644
--- include/tsutil/DbgCtl.h
+++ include/tsutil/DbgCtl.h
@@ -29,6 +29,9 @@
 #include <atomic>
 #include <utility>
 #include <functional>
+#if !defined(_SYS_STDARG_H_)
+#include <cstdarg>
+#endif

 #include <ts/apidefs.h> // For TS_PRINTFLIKE
