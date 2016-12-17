$NetBSD$

--- tools/lldb-mi/MICmnBase.h.orig	2016-09-10 17:36:23.000000000 +0000
+++ tools/lldb-mi/MICmnBase.h
@@ -28,7 +28,7 @@ public:
   bool HaveErrorDescription() const;
   const CMIUtilString &GetErrorDescription() const;
   void SetErrorDescription(const CMIUtilString &vrTxt) const;
-  void SetErrorDescriptionn(const CMIUtilString vFormat, ...) const;
+  void SetErrorDescriptionn(const char *vFormat, ...) const;
   void SetErrorDescriptionNoLog(const CMIUtilString &vrTxt) const;
   void ClrErrorDescription() const;
 
