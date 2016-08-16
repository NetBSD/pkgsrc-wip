$NetBSD$

--- src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp.orig	2016-08-15 22:22:09.000000000 +0000
+++ src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp
@@ -52,7 +52,7 @@
 # include <iprt/win/windows.h>
 # include <winioctl.h>
 #elif defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) \
-    || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+    || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <errno.h>
 # include <sys/ioctl.h>
 # include <sys/types.h>
@@ -74,9 +74,9 @@
 # include <sys/dkio.h>
 # include <sys/vtoc.h>
 #endif /* RT_OS_SOLARIS */
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/disk.h>
-#endif /* RT_OS_FREEBSD */
+#endif /* RT_OS_FREEBSD || RT_OS_NETBSD */
 
 using namespace com;
 
@@ -1203,12 +1203,12 @@ static RTEXITCODE CmdCreateRawVMDK(int a
             i++;
             pszPartitions = argv[i];
         }
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_WINDOWS) || defined(RT_OS_NETBSD)
         else if (strcmp(argv[i], "-relative") == 0)
         {
             fRelative = true;
         }
-#endif /* RT_OS_LINUX || RT_OS_FREEBSD */
+#endif /* RT_OS_LINUX || RT_OS_FREEBSD || RT_OS_NETBSD */
         else
             return errorSyntax(USAGE_CREATERAWVMDK, "Invalid parameter '%s'", argv[i]);
     }
@@ -1448,7 +1448,7 @@ static RTEXITCODE CmdCreateRawVMDK(int a
         RTMsgError("Failed to get file informtation for raw disk '%s': %Rrc",
                    rawdisk.c_str(), vrc);
     }
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     struct stat DevStat;
     if (!fstat(RTFileToNative(hRawFile), &DevStat))
     {
@@ -1668,7 +1668,7 @@ static RTEXITCODE CmdCreateRawVMDK(int a
 
                 if (fRelative)
                 {
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                     /* Refer to the correct partition and use offset 0. */
                     char *psz;
 #if defined(RT_OS_LINUX)
@@ -1690,7 +1690,7 @@ static RTEXITCODE CmdCreateRawVMDK(int a
                                      "%s%u",
                                      rawdisk.c_str(),
                                      partitions.aPartitions[i].uIndex);
-#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                     RTStrAPrintf(&psz,
                                  "%ss%u",
                                  rawdisk.c_str(),
@@ -2595,4 +2595,3 @@ RTEXITCODE handleInternalCommands(Handle
     /* default: */
     return errorSyntax(USAGE_ALL, "Invalid command '%s'", a->argv[0]);
 }
-
