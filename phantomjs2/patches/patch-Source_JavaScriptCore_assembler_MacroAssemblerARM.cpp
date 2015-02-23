$NetBSD: patch-Source_JavaScriptCore_assembler_MacroAssemblerARM.cpp,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Add NetBSD support

--- src/qt/qtwebkit/Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp
@@ -51,6 +51,15 @@ typedef struct
 # endif
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
@@ -69,6 +78,16 @@ static bool isVFPPresent()
     }
 #endif
 
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
 #if (COMPILER(RVCT) && defined(__TARGET_FPU_VFP)) || (COMPILER(GCC) && defined(__VFP_FP__))
     return true;
 #else
