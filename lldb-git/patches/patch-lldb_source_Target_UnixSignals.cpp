$NetBSD$

--- lldb/source/Target/UnixSignals.cpp.orig	2015-12-06 02:57:30.000000000 +0000
+++ lldb/source/Target/UnixSignals.cpp
@@ -19,6 +19,7 @@
 #include "Plugins/Process/Utility/FreeBSDSignals.h"
 #include "Plugins/Process/Utility/LinuxSignals.h"
 #include "Plugins/Process/Utility/MipsLinuxSignals.h"
+#include "Plugins/Process/Utility/NetBSDSignals.h"
 
 using namespace lldb_private;
 
@@ -63,8 +64,9 @@ UnixSignals::Create(const ArchSpec &arch
         }
         case llvm::Triple::FreeBSD:
         case llvm::Triple::OpenBSD:
-        case llvm::Triple::NetBSD:
             return std::make_shared<FreeBSDSignals>();
+        case llvm::Triple::NetBSD:
+            return std::make_shared<NetBSDSignals>();
         default:
             return std::make_shared<UnixSignals>();
     }
