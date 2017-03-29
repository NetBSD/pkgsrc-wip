$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp
@@ -154,6 +154,9 @@ int NativeRegisterContextNetBSD_x86_64::
   case GPRegSet:
     ReadGPR();
     return 0;
+  case FPRegSet:
+    ReadFPR();
+    return 0;
   default:
     break;
   }
@@ -164,6 +167,9 @@ int NativeRegisterContextNetBSD_x86_64::
   case GPRegSet:
     WriteGPR();
     return 0;
+  case FPRegSet:
+    WriteFPR();
+    return 0;
   default:
     break;
   }
