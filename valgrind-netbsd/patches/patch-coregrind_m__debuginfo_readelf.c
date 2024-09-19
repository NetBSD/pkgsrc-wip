$NetBSD$

--- coregrind/m_debuginfo/readelf.c.orig	2018-07-20 10:43:38.000000000 +0000
+++ coregrind/m_debuginfo/readelf.c
@@ -29,7 +29,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 #include "pub_core_basics.h"
 #include "pub_core_vki.h"
@@ -1554,7 +1554,7 @@ static HChar* readlink_path (const HChar
 #if defined(VGP_arm64_linux)
       res = VG_(do_syscall4)(__NR_readlinkat, VKI_AT_FDCWD,
                                               (UWord)path, (UWord)buf, bufsiz);
-#elif defined(VGO_linux) || defined(VGO_darwin)
+#elif defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
       res = VG_(do_syscall3)(__NR_readlink, (UWord)path, (UWord)buf, bufsiz);
 #elif defined(VGO_solaris)
       res = VG_(do_syscall4)(__NR_readlinkat, VKI_AT_FDCWD, (UWord)path,
@@ -2393,7 +2393,8 @@ Bool ML_(read_elf_debug_info) ( struct _
          || defined(VGP_arm_linux) || defined (VGP_s390x_linux) \
          || defined(VGP_mips32_linux) || defined(VGP_mips64_linux) \
          || defined(VGP_arm64_linux) \
-         || defined(VGP_x86_solaris) || defined(VGP_amd64_solaris)
+         || defined(VGP_x86_solaris) || defined(VGP_amd64_solaris) \
+         || defined(VGP_amd64_netbsd)
       /* Accept .plt where mapped as rx (code) */
       if (0 == VG_(strcmp)(name, ".plt")) {
          if (inrx && !di->plt_present) {
@@ -3333,7 +3334,7 @@ Bool ML_(read_elf_debug_info) ( struct _
    /* NOTREACHED */
 }
 
-#endif // defined(VGO_linux) || defined(VGO_solaris)
+#endif // defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/
