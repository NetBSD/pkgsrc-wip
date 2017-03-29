$NetBSD$

--- source/Plugins/Process/elf-core/ThreadElfCore.cpp.orig	2017-03-26 19:17:32.000000000 +0000
+++ source/Plugins/Process/elf-core/ThreadElfCore.cpp
@@ -21,6 +21,7 @@
 #include "Plugins/Process/Utility/RegisterContextLinux_i386.h"
 #include "Plugins/Process/Utility/RegisterContextLinux_s390x.h"
 #include "Plugins/Process/Utility/RegisterContextLinux_x86_64.h"
+#include "Plugins/Process/Utility/RegisterContextNetBSD_x86_64.h"
 #include "Plugins/Process/Utility/RegisterContextOpenBSD_i386.h"
 #include "Plugins/Process/Utility/RegisterContextOpenBSD_x86_64.h"
 #include "Plugins/Process/Utility/RegisterInfoPOSIX_arm.h"
@@ -112,6 +113,17 @@ ThreadElfCore::CreateRegisterContextForF
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
@@ -144,8 +156,8 @@ ThreadElfCore::CreateRegisterContextForF
         reg_interface = new RegisterInfoPOSIX_arm(arch);
         break;
       case llvm::Triple::x86:
-	reg_interface = new RegisterContextOpenBSD_i386(arch);
-	break;
+        reg_interface = new RegisterContextOpenBSD_i386(arch);
+        break;
       case llvm::Triple::x86_64:
         reg_interface = new RegisterContextOpenBSD_x86_64(arch);
         break;
@@ -260,7 +272,6 @@ Error ELFLinuxPrStatus::Parse(DataExtrac
   pr_cstime.tv_sec = data.GetPointer(&offset);
   pr_cstime.tv_usec = data.GetPointer(&offset);
 
-
   return error;
 }
 
@@ -317,9 +328,7 @@ Error ELFLinuxPrPsInfo::Parse(DataExtrac
 //----------------------------------------------------------------
 // Parse SIGINFO from NOTE entry
 //----------------------------------------------------------------
-ELFLinuxSigInfo::ELFLinuxSigInfo() {
-  memset(this, 0, sizeof(ELFLinuxSigInfo));
-}
+ELFLinuxSigInfo::ELFLinuxSigInfo() { memset(this, 0, sizeof(ELFLinuxSigInfo)); }
 
 Error ELFLinuxSigInfo::Parse(DataExtractor &data, const ArchSpec &arch) {
   Error error;
