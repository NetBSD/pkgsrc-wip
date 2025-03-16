$NetBSD$

# Try to fix: WebProcess CRASHED
# https://github.com/freebsd/freebsd-ports/commit/1eeaaa8e063450d0eb8f08df33a6ba338c348825

--- Source/WebCore/platform/MediaSample.h.orig	2025-03-13 16:46:02.595638107 +0000
+++ Source/WebCore/platform/MediaSample.h
@@ -63,7 +63,6 @@ struct PlatformSample {
         const MockSampleBox* mockSampleBox;
         CMSampleBufferRef cmSampleBuffer;
         GstSample* gstSample;
-        std::pair<MTPluginByteSourceRef, std::reference_wrapper<const TrackInfo>> byteRangeSample;
     } sample;
 };
 
