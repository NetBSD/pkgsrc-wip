$NetBSD$

--- coregrind/pub_core_initimg.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/pub_core_initimg.h
@@ -68,7 +68,7 @@ void VG_(ii_finalise_image)( IIFinaliseI
 
 /* ------------------------- Linux ------------------------- */
 
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
 
 struct _IICreateImageInfo {
    /* ------ Mandatory fields ------ */
@@ -88,8 +88,10 @@ struct _IIFinaliseImageInfo {
    Addr  initial_client_IP;
    Addr  initial_client_TOC;
    UInt* client_auxv;
+#if !defined(VGO_netbsd)
    /* ------ Arch-specific ELF loading state ------ */
    struct vki_arch_elf_state arch_elf_state;
+#endif
 };
 
 /* ------------------------- Darwin ------------------------- */
