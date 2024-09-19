$NetBSD$

--- coregrind/m_redir.c.orig	2018-09-18 06:43:50.000000000 +0000
+++ coregrind/m_redir.c
@@ -1213,6 +1213,9 @@ Bool VG_(is_soname_ld_so) (const HChar *
    if (VG_STREQ(soname, VG_U_LD_SO_1))               return True;
    if (VG_STREQ(soname, VG_U_LD_LINUX_AARCH64_SO_1)) return True;
    if (VG_STREQ(soname, VG_U_LD_LINUX_ARMHF_SO_3))   return True;
+#  elif defined(VGO_netbsd)
+   if (VG_STREQ(soname, VG_U_LD_ELF_SO_1)) return True;
+   if (VG_STREQ(soname, VG_U_LD_ELF32_SO_1)) return True;
 #  elif defined(VGO_darwin)
    if (VG_STREQ(soname, VG_U_DYLD)) return True;
 #  elif defined(VGO_solaris)
@@ -1528,6 +1531,8 @@ void VG_(redir_initialise) ( void )
 #     endif
    }
 
+#  elif defined(VGO_netbsd)
+/* XXX do something real if needed */
 #  elif defined(VGP_x86_darwin)
    /* If we're using memcheck, use these intercepts right from
       the start, otherwise dyld makes a lot of noise. */
