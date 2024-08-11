$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/channel.cc.orig	2024-07-24 02:44:41.657267800 +0000
+++ mojo/core/channel.cc
@@ -71,7 +71,11 @@ const size_t kMaxUnusedReadBufferCapacit
 // Fuchsia: The zx_channel_write() API supports up to 64 handles.
 const size_t kMaxAttachedHandles = 64;
 
+#if defined(__i386__) && defined(OS_FREEBSD)
+const size_t kChannelMessageAlignment = 4;
+#else
 static_assert(alignof(std::max_align_t) >= kChannelMessageAlignment, "");
+#endif
 Channel::AlignedBuffer MakeAlignedBuffer(size_t size) {
   // Generic allocators (such as malloc) return a pointer that is suitably
   // aligned for storing any type of object with a fundamental alignment
