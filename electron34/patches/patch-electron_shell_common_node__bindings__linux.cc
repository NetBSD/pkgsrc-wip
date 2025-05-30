$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/node_bindings_linux.cc.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/common/node_bindings_linux.cc
@@ -4,12 +4,25 @@
 
 #include "shell/common/node_bindings_linux.h"
 
+#if !defined(OS_BSD)
 #include <sys/epoll.h>
+#else
+#include <errno.h>
+#include <sys/select.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#endif
 
 namespace electron {
 
 NodeBindingsLinux::NodeBindingsLinux(BrowserEnvironment browser_env)
+#if !defined(OS_BSD)
     : NodeBindings(browser_env), epoll_(epoll_create(1)) {
+#else
+    : NodeBindings(browser_env) {
+#endif
+#if !defined(OS_BSD)
   auto* const event_loop = uv_loop();
 
   int backend_fd = uv_backend_fd(event_loop);
@@ -17,11 +30,13 @@ NodeBindingsLinux::NodeBindingsLinux(Bro
   ev.events = EPOLLIN;
   ev.data.fd = backend_fd;
   epoll_ctl(epoll_, EPOLL_CTL_ADD, backend_fd, &ev);
+#endif
 }
 
 void NodeBindingsLinux::PollEvents() {
   auto* const event_loop = uv_loop();
 
+#if !defined(OS_BSD)
   int timeout = uv_backend_timeout(event_loop);
 
   // Wait for new libuv events.
@@ -30,6 +45,26 @@ void NodeBindingsLinux::PollEvents() {
     struct epoll_event ev;
     r = epoll_wait(epoll_, &ev, 1, timeout);
   } while (r == -1 && errno == EINTR);
+#else
+  struct timeval tv;
+  int timeout = uv_backend_timeout(event_loop);
+  if (timeout != -1) {
+    tv.tv_sec = timeout / 1000;
+    tv.tv_usec = (timeout % 1000) * 1000;
+  }
+
+  fd_set readset;
+  int fd = uv_backend_fd(event_loop);
+  FD_ZERO(&readset);
+  FD_SET(fd, &readset);
+
+  // Wait for new libuv events.
+  int r;
+  do {
+    r = select(fd + 1, &readset, nullptr, nullptr,
+               timeout == -1 ? nullptr : &tv);
+   } while (r == -1 && errno == EINTR);
+#endif
 }
 
 // static
