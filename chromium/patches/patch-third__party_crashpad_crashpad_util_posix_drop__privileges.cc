$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/posix/drop_privileges.cc.orig	2024-07-24 02:45:04.427473300 +0000
+++ third_party/crashpad/crashpad/util/posix/drop_privileges.cc
@@ -25,7 +25,7 @@ void DropPrivileges() {
   gid_t gid = getgid();
   uid_t uid = getuid();
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // Based on the POSIX.1-2008 2013 edition documentation for setreuid() and
   // setregid(), setreuid() and setregid() alone should be sufficient to drop
   // privileges. The standard specifies that the saved ID should be set to the
