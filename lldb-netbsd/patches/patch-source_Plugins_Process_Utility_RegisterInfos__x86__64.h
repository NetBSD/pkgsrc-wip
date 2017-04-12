$NetBSD$

--- source/Plugins/Process/Utility/RegisterInfos_x86_64.h.orig	2016-12-17 10:29:58.000000000 +0000
+++ source/Plugins/Process/Utility/RegisterInfos_x86_64.h
@@ -148,7 +148,7 @@
         DR_OFFSET(i), eEncodingUint, eFormatHex,                               \
                   {LLDB_INVALID_REGNUM, LLDB_INVALID_REGNUM,                   \
                    LLDB_INVALID_REGNUM, LLDB_INVALID_REGNUM,                   \
-                   LLDB_INVALID_REGNUM },                                      \
+                   lldb_##reg##i##_x86_64 },                                   \
                    nullptr, nullptr, nullptr, 0                                \
   }
 
