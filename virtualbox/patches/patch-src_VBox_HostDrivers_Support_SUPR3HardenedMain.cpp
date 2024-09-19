$NetBSD$

--- src/VBox/HostDrivers/Support/SUPR3HardenedMain.cpp.orig	2016-03-04 19:29:24.000000000 +0000
+++ src/VBox/HostDrivers/Support/SUPR3HardenedMain.cpp
@@ -63,7 +63,7 @@
 #  ifndef CAP_TO_MASK
 #   define CAP_TO_MASK(cap) RT_BIT(cap)
 #  endif
-# elif defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #  include <sys/param.h>
 #  include <sys/sysctl.h>
 # elif defined(RT_OS_SOLARIS)
@@ -859,7 +859,7 @@ static void supR3HardenedGetFullExePath(
      *
      * Darwin, OS/2 and Windows all have proper APIs for getting the program file name.
      */
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_SOLARIS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_SOLARIS) || defined(RT_OS_NETBSD)
 # ifdef RT_OS_LINUX
     int cchLink = readlink("/proc/self/exe", &g_szSupLibHardenedExePath[0], sizeof(g_szSupLibHardenedExePath) - 1);
 
@@ -868,7 +868,7 @@ static void supR3HardenedGetFullExePath(
     sprintf(szFileBuf, "/proc/%ld/path/a.out", (long)getpid());
     int cchLink = readlink(szFileBuf, &g_szSupLibHardenedExePath[0], sizeof(g_szSupLibHardenedExePath) - 1);
 
-# else /* RT_OS_FREEBSD */
+# elif defined(RT_OS_FREEBSD)
     int aiName[4];
     aiName[0] = CTL_KERN;
     aiName[1] = KERN_PROC;
@@ -881,6 +881,19 @@ static void supR3HardenedGetFullExePath(
     g_szSupLibHardenedExePath[sizeof(g_szSupLibHardenedExePath) - 1] = '\0';
     int cchLink = suplibHardenedStrLen(g_szSupLibHardenedExePath); /* paranoid? can't we use cbPath? */
 
+# else /* RT_OS_NETBSD */
+    int aiName[4];
+    aiName[0] = CTL_KERN;
+    aiName[1] = KERN_PROC_ARGS;
+    aiName[2] = getpid();
+    aiName[3] = KERN_PROC_PATHNAME;
+
+    size_t cbPath = sizeof(g_szSupLibHardenedExePath);
+    if (sysctl(aiName, RT_ELEMENTS(aiName), g_szSupLibHardenedExePath, &cbPath, NULL, 0) < 0)
+        supR3HardenedFatal("supR3HardenedExecDir: sysctl failed\n");
+    g_szSupLibHardenedExePath[sizeof(g_szSupLibHardenedExePath) - 1] = '\0';
+    int cchLink = suplibHardenedStrLen(g_szSupLibHardenedExePath); /* paranoid? can't we use cbPath? */
+
 # endif
     if (cchLink < 0 || cchLink == sizeof(g_szSupLibHardenedExePath) - 1)
         supR3HardenedFatal("supR3HardenedExecDir: couldn't read \"%s\", errno=%d cchLink=%d\n",
@@ -1558,7 +1571,7 @@ static void supR3HardenedMainDropPrivile
     egid = getegid();
     rgid = sgid = getgid();
 
-# elif defined(RT_OS_SOLARIS)
+# elif defined(RT_OS_SOLARIS) || defined(RT_OS_NETBSD)
     /* Solaris doesn't have setresuid, but the setreuid interface is BSD
        compatible and will set the saved uid to euid when we pass it a ruid
        that isn't -1 (which we do). */
@@ -2025,4 +2038,3 @@ DECLHIDDEN(int) SUPR3HardenedMain(const 
     g_enmSupR3HardenedMainState = SUPR3HARDENEDMAINSTATE_CALLED_TRUSTED_MAIN;
     return pfnTrustedMain(argc, argv, envp);
 }
-
