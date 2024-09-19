$NetBSD$

--- coregrind/m_vki.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_vki.c
@@ -68,16 +68,21 @@ void VG_(vki_do_initial_consistency_chec
    /* --- Platform-independent checks on signal sets --- */
 
    vki_sigset_t set;
+
+#if !defined(VGO_netbsd)
+   // NetBSD uses 128 bits for sigset, but defines only 64
+
    // Set's size must agree with _VKI_NSIG
    vg_assert( 8 * sizeof(set) == _VKI_NSIG );
    // Set's word size must agree with _VKI_NSIG_BPW
    vg_assert( 8 * sizeof(set.sig[0]) == _VKI_NSIG_BPW );
    // The set elements are 32- or 64-bit
    vg_assert( _VKI_NSIG_BPW == 32 || _VKI_NSIG_BPW == 64 );
+#endif
 
    /* --- Platform-specific checks on signal sets --- */
 
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    /* nothing to check */
 #  elif defined(VGP_x86_darwin) || defined(VGP_amd64_darwin)
    vg_assert(_VKI_NSIG == NSIG);
@@ -91,7 +96,7 @@ void VG_(vki_do_initial_consistency_chec
 
    /* --- Platform-specific checks on sigactions --- */
 
-#  if defined(VGO_linux)
+#  if defined(VGO_linux) || defined(VGO_netbsd)
    /* the toK- and fromK- forms are identical */
    vg_assert( sizeof(vki_sigaction_toK_t) 
               == sizeof(vki_sigaction_fromK_t) );
