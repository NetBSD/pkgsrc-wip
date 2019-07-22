$NetBSD$

--- vm/src/any/runtime/config.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/runtime/config.hh
@@ -17,7 +17,7 @@
    HOST_ARCH is where the compiler is running, one of SPARC_ARCH, M68K_ARCH, PPC_ARCH, I386_ARCH
    TARGET_ARCH is the platform we are compiling for
    TARGET_OS_FAMILY: UNIX_FAMILY, MACOS_FAMILY
-   TARGET_OS_VERSION: SUNOS_VERSION, SOLARIS_VERSION, MACOS_SYSTEM_7_VERSION, LINUX_VERSION
+   TARGET_OS_VERSION: SUNOS_VERSION, SOLARIS_VERSION, MACOS_SYSTEM_7_VERSION, LINUX_VERSION, NETBSD_VERSION
    COMPILER is the compiler we are using:
      CC_COMPILER, GCC_COMPILER, MWERKS_COMPILER, SPARCWORKS_COMPILER
 
@@ -53,6 +53,7 @@
 # define   MACOS_CARBON_VERSION 4 // Carbon 9/10 version
 # define         MACOSX_VERSION 5 // MacOSX native version
 # define          LINUX_VERSION 6 // Ubuntu
+# define         NETBSD_VERSION 7 // 8.99.51 tested
 
 # define         CC_COMPILER 1
 # define        GCC_COMPILER 2
