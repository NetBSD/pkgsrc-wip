$NetBSD$

--- coregrind/m_machine.c.orig	2018-07-24 08:23:41.000000000 +0000
+++ coregrind/m_machine.c
@@ -2035,7 +2035,7 @@ void* VG_(fnptr_to_fnentry)( void* f )
       || defined(VGP_ppc32_linux) || defined(VGP_ppc64le_linux) \
       || defined(VGP_s390x_linux) || defined(VGP_mips32_linux) \
       || defined(VGP_mips64_linux) || defined(VGP_arm64_linux) \
-      || defined(VGP_x86_solaris) || defined(VGP_amd64_solaris)
+      || defined(VGP_x86_solaris) || defined(VGP_amd64_solaris) || defined(VGO_netbsd)
    return f;
 #  elif defined(VGP_ppc64be_linux)
    /* ppc64-linux uses the AIX scheme, in which f is a pointer to a
