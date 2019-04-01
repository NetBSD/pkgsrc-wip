$NetBSD$

--- coregrind/pub_core_machine.h.orig	2018-07-13 08:52:05.000000000 +0000
+++ coregrind/pub_core_machine.h
@@ -46,7 +46,7 @@
 #  define VG_ELF_MACHINE      EM_386
 #  define VG_ELF_CLASS        ELFCLASS32
 #  undef  VG_PLAT_USES_PPCTOC
-#elif defined(VGP_amd64_linux) || defined(VGP_amd64_solaris)
+#elif defined(VGP_amd64_linux) || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 #  define VG_ELF_DATA2XXX     ELFDATA2LSB
 #  define VG_ELF_MACHINE      EM_X86_64
 #  define VG_ELF_CLASS        ELFCLASS64
