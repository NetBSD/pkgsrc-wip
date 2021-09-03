$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- unmanaged.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ unmanaged.cpp
@@ -46,7 +46,7 @@ Unmanaged::~Unmanaged()
 {
 }
 
-bool Unmanaged::track(Window w)
+bool Unmanaged::track(xcb_window_t w)
 {
     GRAB_SERVER_DURING_CONTEXT
     Xcb::WindowAttributes attr(w);
