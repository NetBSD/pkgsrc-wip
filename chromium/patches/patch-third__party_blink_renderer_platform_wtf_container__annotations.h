$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2024-08-06 19:52:34.834775700 +0000
+++ third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -12,7 +12,7 @@
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
 #if defined(ADDRESS_SANITIZER) &&                      \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     defined(ARCH_CPU_X86_64)
 
 // Annotations require buffers to begin on an 8-byte boundary. See
