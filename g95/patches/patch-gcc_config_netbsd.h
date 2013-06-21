$NetBSD: patch-gcc_config_netbsd.h,v 1.1 2013/06/21 07:38:52 makoto Exp $

Configuring in powerpc--netbsd/libssp
/usr/pkgsrc/lang/g95/work/gcc-4.1.2/g95/./gcc/libgcc_s.so.1: 
  Unsupported relocation type 10 in non-PLT relocations
/usr/pkgsrc/lang/g95/work/gcc-4.1.2/g95/./gcc/libgcc_s.so.1: 
  Unsupported relocation type 10 in non-PLT relocations
/usr/pkgsrc/lang/g95/work/gcc-4.1.2/g95/./gcc/libgcc_s.so.1: 
  Unsupported relocation type 10 in non-PLT relocations

--- work/gcc-4.1.2/gcc/config/netbsd.h	2005-07-14 01:28:25.000000000 +0900
+++ ../gcc-4.1.2/gcc/config/netbsd.h	2008-04-28 08:49:27.000000000 +0900
@@ -28,6 +28,11 @@
       builtin_assert ("system=bsd");		\
       builtin_assert ("system=unix");		\
       builtin_assert ("system=NetBSD");		\
+      if (flag_pic)				\
+        {					\
+          builtin_define ("__PIC__");		\
+          builtin_define ("__pic__");		\
+        }					\
     }						\
   while (0)
 
@@ -122,24 +142,22 @@
 #undef LIB_SPEC
 #define LIB_SPEC NETBSD_LIB_SPEC
 
-/* Provide a LIBGCC_SPEC appropriate for NetBSD.  We also want to exclude
-   libgcc with -symbolic.  */
+/* Don't provide a LIBGCC_SPEC for NetBSD as the default
+   is correct. In the --disabled-shared case -lgcc is perfect.  */
 
-#ifdef NETBSD_NATIVE
-#define NETBSD_LIBGCC_SPEC	\
-  "%{!symbolic:			\
-     %{!shared:			\
-       %{!p:			\
-	 %{!pg: -lgcc}}}	\
-     %{shared: -lgcc_pic}	\
-     %{p: -lgcc_p}		\
-     %{pg: -lgcc_p}}"
-#else
-#define NETBSD_LIBGCC_SPEC "%{!shared:%{!symbolic: -lgcc}}"
+#if defined(NETBSD_TOOLS) || defined(NETBSD_NATIVE)
+#define	LIBGCC_PICSUFFIX	"_pic"
 #endif
 
-#undef LIBGCC_SPEC
-#define LIBGCC_SPEC NETBSD_LIBGCC_SPEC
+/* Pass -cxx-isystem to cc1/cc1plus.  */
+#define NETBSD_CC1_AND_CC1PLUS_SPEC		\
+  "%{cxx-isystem}"
+
+#undef CC1_SPEC
+#define CC1_SPEC NETBSD_CC1_AND_CC1PLUS_SPEC
+
+#undef CC1PLUS_SPEC
+#define CC1PLUS_SPEC NETBSD_CC1_AND_CC1PLUS_SPEC
 
 /* When building shared libraries, the initialization and finalization 
    functions for the library are .init and .fini respectively.  */
