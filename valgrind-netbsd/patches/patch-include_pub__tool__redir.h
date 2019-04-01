$NetBSD$

--- include/pub_tool_redir.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ include/pub_tool_redir.h
@@ -243,7 +243,7 @@
 
 /* --- Soname of the standard C library. --- */
 
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 # if defined(MUSL_LIBC)
 #  define  VG_Z_LIBC_SONAME  libcZdZa              // libc.*
 #else
@@ -284,6 +284,8 @@
 #else
 #  define  VG_Z_LIBPTHREAD_SONAME  libpthreadZdsoZd0     // libpthread.so.0
 #endif
+#elif defined(VGO_netbsd)
+#  define  VG_Z_LIBPTHREAD_SONAME  libpthreadZdsoZa      // libpthread.so*
 #elif defined(VGO_darwin)
 #  define  VG_Z_LIBPTHREAD_SONAME  libSystemZdZaZddylib  // libSystem.*.dylib
 #elif defined(VGO_solaris)
@@ -318,6 +320,18 @@
 
 #endif
 
+/* --- Sonames for NetBSD ELF linkers. --- */
+
+#if defined(VGO_netbsd)
+
+#define  VG_Z_LD_ELF_SO_1           ldZdelf_so           // ld.elf_so
+#define  VG_U_LD_ELF_SO_1           "ld.elf_so"
+
+#define  VG_Z_LD_ELF32_SO_1         ldZdelf_soZhi386         // ld.elf_so-i386
+#define  VG_U_LD_ELF32_SO_1         "ld.elf_so-i386"
+
+#endif
+
 /* --- Executable name for Darwin Mach-O linker. --- */
 
 #if defined(VGO_darwin)
