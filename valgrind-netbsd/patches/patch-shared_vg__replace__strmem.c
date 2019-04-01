$NetBSD$

--- shared/vg_replace_strmem.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ shared/vg_replace_strmem.c
@@ -209,6 +209,12 @@ static inline void my_exit ( int x )
   STRRCHR(NONE, __dl_strrchr); /* in /system/bin/linker */
 #endif
 
+#elif defined(VGO_netbsd)
+// STRCHR(VG_Z_LIBC_SONAME,          strchr)
+// STRCHR(VG_Z_LIBC_SONAME,          index)
+// STRCHR(VG_Z_LD_ELF_SO_1, strchr)
+// STRCHR(VG_Z_LD_ELF32_SO_1, strchr)
+
 #elif defined(VGO_darwin)
  //STRRCHR(VG_Z_LIBC_SONAME,   strrchr)
  //STRRCHR(VG_Z_LIBC_SONAME,   rindex)
