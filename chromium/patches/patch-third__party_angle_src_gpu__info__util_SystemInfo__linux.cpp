$NetBSD$

--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2020-07-15 19:01:32.000000000 +0000
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,10 +73,17 @@ bool GetPCIDevicesWithLibPCI(std::vector
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+        return false;
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
         return false;
     }
+#endif
 
     if (info->gpus.size() == 0)
     {
