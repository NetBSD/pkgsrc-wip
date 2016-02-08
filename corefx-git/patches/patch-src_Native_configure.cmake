$NetBSD$

--- src/Native/configure.cmake.orig	2016-02-08 16:12:54.000000000 +0000
+++ src/Native/configure.cmake
@@ -10,6 +10,7 @@ include(CheckTypeSize)
 #CMake does not include /usr/local/include into the include search path
 #thus add it manually. This is required on FreeBSD.
 include_directories(SYSTEM /usr/local/include)
+include_directories(SYSTEM /usr/pkg/include)
 
 # in_pktinfo: Find whether this struct exists
 check_include_files(
@@ -27,6 +28,14 @@ check_type_size(
     "struct in_pktinfo"
     HAVE_IN_PKTINFO
     BUILTIN_TYPES_ONLY)
+
+check_type_size(
+    "struct ip_mreqn"
+    HAVE_IP_MREQN)
+
+check_type_size(
+    "struct ip_mreq" 
+    HAVE_IP_MREQ)
 set(CMAKE_EXTRA_INCLUDE_FILES) # reset CMAKE_EXTRA_INCLUDE_FILES
 # /in_pktinfo
 
@@ -34,6 +43,10 @@ check_include_files(
     alloca.h
     HAVE_ALLOCA_H)
 
+check_include_files(
+    sys/statvfs.h
+    HAVE_SYS_STATVFS)
+
 check_function_exists(
     stat64
     HAVE_STAT64)
@@ -117,6 +130,21 @@ check_struct_has_member(
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
+    HAVE_VFS_NAMELEN)
+
+check_struct_has_member(
     "struct in6_addr"
     __in6_u
     "netdb.h"
@@ -157,6 +185,18 @@ check_function_exists(
     gethostbyaddr_r
     HAVE_GETHOSTBYADDR_R)
 
+check_function_exists(
+    getaddrinfo
+    HAVE_GETADDRINFO)
+
+check_function_exists(
+    gethostbyname_r
+    HAVE_GETHOSTBYNAME_R)
+
+check_function_exists(
+    getnameinfo
+    HAVE_GETNAMEINFO)
+
 set(HAVE_SUPPORT_FOR_DUAL_MODE_IPV4_PACKET_INFO 0)
 set(HAVE_THREAD_SAFE_GETHOSTBYNAME_AND_GETHOSTBYADDR 0)
 
