$NetBSD$

--- src/Native/configure.cmake.orig	2016-02-07 13:49:29.000000000 +0000
+++ src/Native/configure.cmake
@@ -10,6 +10,7 @@ include(CheckTypeSize)
 #CMake does not include /usr/local/include into the include search path
 #thus add it manually. This is required on FreeBSD.
 include_directories(SYSTEM /usr/local/include)
+include_directories(SYSTEM /usr/pkg/include)
 
 # in_pktinfo: Find whether this struct exists
 check_include_files(
@@ -34,6 +35,10 @@ check_include_files(
     alloca.h
     HAVE_ALLOCA_H)
 
+check_include_files(
+    sys/statvfs.h
+    HAVE_SYS_STATVFS)
+
 check_function_exists(
     stat64
     HAVE_STAT64)
@@ -75,6 +80,16 @@ check_symbol_exists(
     "sys/ioctl.h"
     HAVE_TIOCGWINSZ)
 
+check_symbol_exists(
+    ENOTRECOVERABLE
+    "sys/errno.h"
+    HAVE_ENOTRECOVERABLE)
+
+check_symbol_exists(
+    EOWNERDEAD
+    "sys/errno.h"
+    HAVE_EOWNERDEAD)
+
 check_function_exists(
     tcgetattr
     HAVE_TCGETATTR)
@@ -117,6 +132,22 @@ check_struct_has_member(
     HAVE_STATFS_FSTYPENAME)
 
 check_struct_has_member(
+    "struct statvfs"
+    f_fstypename
+    "sys/mount.h"
+    HAVE_STATVFS_FSTYPENAME)
+
+if (HAVE_STATVFS_FSTYPENAME)
+    set(HAVE_STATFS_FSTYPENAME 1)
+endif ()
+
+check_symbol_exists(
+    VFS_NAMELEN
+    "sys/mount.h"
+    HAVE_VFS_NAMELEN
+)
+
+check_struct_has_member(
     "struct in6_addr"
     __in6_u
     "netdb.h"
