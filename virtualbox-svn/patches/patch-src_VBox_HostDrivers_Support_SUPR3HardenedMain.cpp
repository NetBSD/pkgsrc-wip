$NetBSD$

--- src/VBox/HostDrivers/Support/SUPR3HardenedMain.cpp.orig	2016-08-05 17:22:56.000000000 +0000
+++ src/VBox/HostDrivers/Support/SUPR3HardenedMain.cpp
@@ -425,9 +425,10 @@
 #  ifndef CAP_TO_MASK
 #   define CAP_TO_MASK(cap) RT_BIT(cap)
 #  endif
-# elif defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #  include <sys/param.h>
 #  include <sys/sysctl.h>
+#  undef PVM
 # elif defined(RT_OS_SOLARIS)
 #  include <priv.h>
 # endif
@@ -1221,7 +1222,7 @@ static void supR3HardenedGetFullExePath(
      *
      * Darwin, OS/2 and Windows all have proper APIs for getting the program file name.
      */
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_SOLARIS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD) || defined(RT_OS_SOLARIS)
 # ifdef RT_OS_LINUX
     int cchLink = readlink("/proc/self/exe", &g_szSupLibHardenedExePath[0], sizeof(g_szSupLibHardenedExePath) - 1);
 
@@ -1230,12 +1231,19 @@ static void supR3HardenedGetFullExePath(
     sprintf(szFileBuf, "/proc/%ld/path/a.out", (long)getpid());
     int cchLink = readlink(szFileBuf, &g_szSupLibHardenedExePath[0], sizeof(g_szSupLibHardenedExePath) - 1);
 
-# else /* RT_OS_FREEBSD */
+# else /* RT_OS_FREEBSD || RT_OS_NETBSD */
     int aiName[4];
+#  if defined(RT_OS_FREEBSD)
     aiName[0] = CTL_KERN;
     aiName[1] = KERN_PROC;
     aiName[2] = KERN_PROC_PATHNAME;
     aiName[3] = getpid();
+#  else /* RT_OS_NETBSD */
+    aiName[0] = CTL_KERN;
+    aiName[1] = KERN_PROC_ARGS;
+    aiName[2] = getpid();
+    aiName[3] = KERN_PROC_PATHNAME;
+#  endif
 
     size_t cbPath = sizeof(g_szSupLibHardenedExePath);
     if (sysctl(aiName, RT_ELEMENTS(aiName), g_szSupLibHardenedExePath, &cbPath, NULL, 0) < 0)
@@ -1922,7 +1930,7 @@ static void supR3HardenedMainDropPrivile
     egid = getegid();
     rgid = sgid = getgid();
 
-# elif defined(RT_OS_SOLARIS)
+# elif defined(RT_OS_SOLARIS) || defined(RT_OS_NETBSD)
     /* Solaris doesn't have setresuid, but the setreuid interface is BSD
        compatible and will set the saved uid to euid when we pass it a ruid
        that isn't -1 (which we do). */
@@ -2391,4 +2399,3 @@ DECLHIDDEN(int) SUPR3HardenedMain(const 
     g_enmSupR3HardenedMainState = SUPR3HARDENEDMAINSTATE_CALLED_TRUSTED_MAIN;
     return pfnTrustedMain(argc, argv, envp);
 }
-
