$NetBSD$

--- source/Plugins/Process/elf-core/ThreadElfCore.cpp.orig	2017-02-27 20:47:52.000000000 +0000
+++ source/Plugins/Process/elf-core/ThreadElfCore.cpp
@@ -18,6 +18,7 @@
 #include "Plugins/Process/Utility/RegisterContextFreeBSD_mips64.h"
 #include "Plugins/Process/Utility/RegisterContextFreeBSD_powerpc.h"
 #include "Plugins/Process/Utility/RegisterContextFreeBSD_x86_64.h"
+#include "Plugins/Process/Utility/RegisterContextNetBSD_x86_64.h"
 #include "Plugins/Process/Utility/RegisterContextLinux_i386.h"
 #include "Plugins/Process/Utility/RegisterContextLinux_s390x.h"
 #include "Plugins/Process/Utility/RegisterContextLinux_x86_64.h"
@@ -110,6 +111,17 @@ ThreadElfCore::CreateRegisterContextForF
       break;
     }
 
+    case llvm::Triple::NetBSD: {
+      switch (arch.GetMachine()) {
+      case llvm::Triple::x86_64:
+        reg_interface = new RegisterContextNetBSD_x86_64(arch);
+        break;
+      default:
+        break;
+      }
+      break;
+    }
+
     case llvm::Triple::Linux: {
       switch (arch.GetMachine()) {
       case llvm::Triple::arm:
