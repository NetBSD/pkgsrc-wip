$NetBSD$

--- v8/src/base/cpu.cc.orig	2020-07-15 19:01:43.000000000 +0000
+++ v8/src/base/cpu.cc
@@ -475,6 +475,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -497,6 +498,7 @@ CPU::CPU()
     }
     delete[] variant;
   }
+#endif
 
   // Extract part number from the "CPU part" field.
   char* part = cpu_info.ExtractField("CPU part");
