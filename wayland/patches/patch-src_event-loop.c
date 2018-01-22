$NetBSD$

--- event-loop.c.orig	2017-08-08 18:20:52.000000000 +0000
+++ src/event-loop.c
@@ -34,9 +34,9 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/epoll.h>
+#include <unistd.h>
 #include <sys/signalfd.h>
 #include <sys/timerfd.h>
-#include <unistd.h>
 #include "wayland-util.h"
 #include "wayland-private.h"
 #include "wayland-server-core.h"
