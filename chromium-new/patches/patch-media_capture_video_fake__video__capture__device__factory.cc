$NetBSD$

--- media/capture/video/fake_video_capture_device_factory.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/capture/video/fake_video_capture_device_factory.cc
@@ -49,7 +49,7 @@ void FakeVideoCaptureDeviceFactory::GetD
   for (int n = 0; n < number_of_devices_; ++n) {
     VideoCaptureDevice::Name name(base::StringPrintf("fake_device_%d", n),
                                   base::StringPrintf("/dev/video%d", n)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                       ,
                                   VideoCaptureDevice::Name::V4L2_SINGLE_PLANE
 #elif defined(OS_MACOSX)
