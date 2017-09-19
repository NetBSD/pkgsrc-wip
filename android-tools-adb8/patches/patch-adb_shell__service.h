$NetBSD$

--- adb/shell_service.h.orig	2017-06-27 22:39:52.000000000 +0000
+++ adb/shell_service.h
@@ -125,7 +125,7 @@ class ShellProtocol {
     DISALLOW_COPY_AND_ASSIGN(ShellProtocol);
 };
 
-#if !ADB_HOST
+#if 1 //!ADB_HOST
 
 enum class SubprocessType {
     kPty,
