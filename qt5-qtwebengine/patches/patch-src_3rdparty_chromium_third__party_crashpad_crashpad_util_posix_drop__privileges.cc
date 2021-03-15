$NetBSD$

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/drop_privileges.cc.orig	2020-07-15 18:56:30.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/drop_privileges.cc
@@ -25,7 +25,7 @@ void DropPrivileges() {
   gid_t gid = getgid();
   uid_t uid = getuid();
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Based on the POSIX.1-2008 2013 edition documentation for setreuid() and
   // setregid(), setreuid() and setregid() alone should be sufficient to drop
   // privileges. The standard specifies that the saved ID should be set to the
