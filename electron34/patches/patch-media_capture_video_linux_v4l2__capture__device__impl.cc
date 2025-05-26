$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/capture/video/linux/v4l2_capture_device_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/capture/video/linux/v4l2_capture_device_impl.cc
@@ -22,7 +22,7 @@ int V4L2CaptureDeviceImpl::close(int fd)
   return ::close(fd);
 }
 
-int V4L2CaptureDeviceImpl::ioctl(int fd, int request, void* argp) {
+int V4L2CaptureDeviceImpl::ioctl(int fd, unsigned long request, void* argp) {
   return ::ioctl(fd, request, argp);
 }
 
