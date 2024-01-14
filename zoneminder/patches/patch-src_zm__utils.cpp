$NetBSD$

Avoid assuming linux on arm.  For now, assume neon.

Fix time types (sizes).

--- src/zm_utils.cpp.orig	2023-02-23 21:44:01.000000000 +0000
+++ src/zm_utils.cpp
@@ -183,7 +183,7 @@ std::string TimevalToString(timeval tv) 
     return "";
   }
 
-  return stringtf("%s.%06ld", tm_buf.data(), tv.tv_usec);
+  return stringtf("%s.%06ld", tm_buf.data(), (long) tv.tv_usec);
 }
 
 /* Detect special hardware features, such as SIMD instruction sets */
@@ -238,6 +238,10 @@ void HwCapsDetect() {
   } else {
     Debug(1,"Detected ARM (AArch32) processor");
   }
+#  else
+    Debug(1,"!!ASSUMING!! ARM (AArch32) processor with Neon");
+    neonversion = 1;
+#  endif
 #elif defined(__aarch64__)
   // ARM processor in 64bit mode
   // Neon is mandatory, no need to check for it
