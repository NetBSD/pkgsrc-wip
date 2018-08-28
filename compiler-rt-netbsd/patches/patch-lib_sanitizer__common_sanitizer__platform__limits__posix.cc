$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_posix.cc.orig	2018-08-21 21:25:39.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_posix.cc
@@ -945,6 +945,7 @@ unsigned struct_ElfW_Phdr_sz = sizeof(El
 
   const int si_SEGV_MAPERR = SEGV_MAPERR;
   const int si_SEGV_ACCERR = SEGV_ACCERR;
+  const unsigned fpos_t_sz = sizeof(fpos_t);
 } // namespace __sanitizer
 
 using namespace __sanitizer;
