$NetBSD$

--- tools/lldb-mi/MICmnBase.cpp.orig	2016-09-10 17:36:23.000000000 +0000
+++ tools/lldb-mi/MICmnBase.cpp
@@ -122,7 +122,7 @@ void CMICmnBase::ClrErrorDescription() c
 // Return:  None.
 // Throws:  None.
 //--
-void CMICmnBase::SetErrorDescriptionn(const CMIUtilString vFormat, ...) const {
+void CMICmnBase::SetErrorDescriptionn(const char *vFormat, ...) const {
   va_list args;
   va_start(args, vFormat);
   CMIUtilString strResult = CMIUtilString::FormatValist(vFormat, args);
