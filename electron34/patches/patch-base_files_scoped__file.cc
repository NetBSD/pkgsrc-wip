$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/files/scoped_file.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/files/scoped_file.cc
@@ -32,7 +32,7 @@ void ScopedFDCloseTraits::Free(int fd) {
   int ret = IGNORE_EINTR(close(fd));
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // NB: Some file descriptors can return errors from close() e.g. network
   // filesystems such as NFS and Linux input devices. On Linux, macOS, and
   // Fuchsia's POSIX layer, errors from close other than EBADF do not indicate
