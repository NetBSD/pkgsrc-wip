$NetBSD$

--- tools/lldb-mi/MIUtilString.h.orig	2016-09-10 17:36:23.000000000 +0000
+++ tools/lldb-mi/MIUtilString.h
@@ -30,7 +30,7 @@ public:
 
   // Static method:
 public:
-  static CMIUtilString Format(const CMIUtilString vFormating, ...);
+  static CMIUtilString Format(const char *vFormating, ...);
   static CMIUtilString FormatBinary(const MIuint64 vnDecimal);
   static CMIUtilString FormatValist(const CMIUtilString &vrFormating,
                                     va_list vArgs);
