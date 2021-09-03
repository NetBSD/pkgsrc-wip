$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- unmanaged.h.orig	2018-05-01 12:52:19.000000000 +0000
+++ unmanaged.h
@@ -35,7 +35,7 @@ class Unmanaged
 public:
     explicit Unmanaged();
     bool windowEvent(xcb_generic_event_t *e);
-    bool track(Window w);
+    bool track(xcb_window_t w);
     static void deleteUnmanaged(Unmanaged* c);
     virtual int desktop() const;
     virtual QStringList activities() const;
