$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media_galleries/fileapi/mtp_device_async_delegate.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/media_galleries/fileapi/mtp_device_async_delegate.h
@@ -209,7 +209,7 @@ class MTPDeviceAsyncDelegate {
   virtual ~MTPDeviceAsyncDelegate() = default;
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 typedef base::OnceCallback<void(MTPDeviceAsyncDelegate*)>
     CreateMTPDeviceAsyncDelegateCallback;
 
