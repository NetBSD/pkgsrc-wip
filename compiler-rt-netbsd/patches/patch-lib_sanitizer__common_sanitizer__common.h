$NetBSD$

--- lib/sanitizer_common/sanitizer_common.h.orig	2018-05-10 23:16:36.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common.h
@@ -221,6 +221,7 @@ bool SetEnv(const char *name, const char
 
 u32 GetUid();
 void ReExec();
+void CheckASLR();
 char **GetArgv();
 void PrintCmdline();
 bool StackSizeIsUnlimited();
