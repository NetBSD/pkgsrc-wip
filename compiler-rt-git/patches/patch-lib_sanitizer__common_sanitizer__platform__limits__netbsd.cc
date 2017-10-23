$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2017-10-20 11:21:05.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -128,6 +128,8 @@ uptr __sanitizer_in_addr_sz(int af) {
     return 0;
 }
 
+unsigned struct_ElfW_Phdr_sz = sizeof(Elf_Phdr);
+
 int glob_nomatch = GLOB_NOMATCH;
 int glob_altdirfunc = GLOB_ALTDIRFUNC;
 
