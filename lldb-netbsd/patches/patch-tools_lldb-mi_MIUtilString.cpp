$NetBSD$

--- tools/lldb-mi/MIUtilString.cpp.orig	2016-09-10 17:36:23.000000000 +0000
+++ tools/lldb-mi/MIUtilString.cpp
@@ -156,7 +156,7 @@ CMIUtilString CMIUtilString::FormatPriv(
 // Return:  CMIUtilString - Number of splits found in the string data.
 // Throws:  None.
 //--
-CMIUtilString CMIUtilString::Format(const CMIUtilString vFormating, ...) {
+CMIUtilString CMIUtilString::Format(const char *vFormating, ...) {
   va_list args;
   va_start(args, vFormating);
   CMIUtilString strResult = CMIUtilString::FormatPriv(vFormating, args);
