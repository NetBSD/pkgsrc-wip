$NetBSD$

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MICmnBase.h.orig	2016-02-21 02:08:07.000000000 +0000
+++ tools/lldb-mi/MICmnBase.h
@@ -28,7 +28,7 @@ class CMICmnBase
     bool HaveErrorDescription() const;
     const CMIUtilString &GetErrorDescription() const;
     void SetErrorDescription(const CMIUtilString &vrTxt) const;
-    void SetErrorDescriptionn(const CMIUtilString vFormat, ...) const;
+    void SetErrorDescriptionn(const char *vFormat, ...) const;
     void SetErrorDescriptionNoLog(const CMIUtilString &vrTxt) const;
     void ClrErrorDescription() const;
 
