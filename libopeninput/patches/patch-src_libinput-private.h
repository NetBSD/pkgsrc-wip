$NetBSD$

* Add NetBSD support

--- src/libinput-private.h.orig	2025-08-17 15:49:37.000000000 +0000
+++ src/libinput-private.h
@@ -1015,7 +1015,7 @@ static inline void libinput_libwacom_unr
 #endif
 
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 void
 axis_notify_event(struct libinput_device *device,
     uint64_t time,
