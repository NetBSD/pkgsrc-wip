$NetBSD$

--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/gpu/gpu_data_manager_impl_private.h
@@ -155,7 +155,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
                            UnblockOtherDomainFrom3DAPIs);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            UnblockThisDomainFrom3DAPIs);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            SetGLStrings);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
