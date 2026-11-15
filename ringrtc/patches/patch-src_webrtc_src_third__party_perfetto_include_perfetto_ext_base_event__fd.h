$NetBSD$

* Import from chromium

--- src/webrtc/src/third_party/perfetto/include/perfetto/ext/base/event_fd.h.orig	2026-05-28 14:04:21.000000000 +0000
+++ src/webrtc/src/third_party/perfetto/include/perfetto/ext/base/event_fd.h
@@ -58,6 +58,8 @@ class EventFd {
   // On Mac and other non-Linux UNIX platforms a pipe-based fallback is used.
   // The write end of the wakeup pipe.
   ScopedFile write_fd_;
+#else
+  ScopedFile write_fd_;
 #endif
 };
 
