$NetBSD$

--- coregrind/pub_core_syscall.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/pub_core_syscall.h
@@ -75,6 +75,7 @@ extern SysRes VG_(mk_SysRes_x86_linux)  
 extern SysRes VG_(mk_SysRes_amd64_linux) ( Long val );
 extern SysRes VG_(mk_SysRes_ppc32_linux) ( UInt  val, UInt  cr0so );
 extern SysRes VG_(mk_SysRes_ppc64_linux) ( ULong val, ULong cr0so );
+extern SysRes VG_(mk_SysRes_amd64_netbsd)( ULong val, ULong val2, Bool err );
 extern SysRes VG_(mk_SysRes_arm_linux)   ( Int val );
 extern SysRes VG_(mk_SysRes_arm64_linux) ( Long val );
 extern SysRes VG_(mk_SysRes_x86_darwin)  ( UChar scclass, Bool isErr,
