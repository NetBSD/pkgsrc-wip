$NetBSD: patch-Source_JavaScriptCore_assembler_MacroAssemblerARM.cpp,v 1.1 2014/12/30 17:23:47 adam Exp $

* Add NetBSD support

--- Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp.orig	2017-06-04 20:16:05.000000000 +0000
+++ Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp
@@ -42,6 +42,15 @@
 #include <asm/hwcap.h>
 #endif
 
+#if OS(NETBSD)
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/sysctl.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include <asm/hwcap.h>
+#endif
+
 namespace JSC {
 
 static bool isVFPPresent()
@@ -60,6 +69,16 @@ static bool isVFPPresent()
     }
 #endif // OS(LINUX)
 
+#if OS(NETBSD)
+    size_t len;
+    int flag;
+
+    len = sizeof(flag);
+    if (sysctlbyname("machdep.fpu_present", &flag, &len, NULL, 0) == 0) {
+        return flag == 1;
+    }
+#endif
+
 #if (COMPILER(GCC_OR_CLANG) && defined(__VFP_FP__))
     return true;
 #else
