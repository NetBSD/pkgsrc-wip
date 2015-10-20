$NetBSD: patch-ipc_chromium_src_base_message__pump__libevent.cc,v 1.1 2014/09/29 10:46:25 thomasklausner Exp $

--- ipc/chromium/src/base/message_pump_libevent.cc.orig	2015-10-20 08:24:26.000000000 +0000
+++ ipc/chromium/src/base/message_pump_libevent.cc
@@ -15,7 +15,7 @@
 #include "base/scoped_nsautorelease_pool.h"
 #include "base/time.h"
 #include "nsDependentSubstring.h"
-#include "third_party/libevent/event.h"
+#include "event.h"
 #include "mozilla/UniquePtr.h"
 
 // This macro checks that the _EVENT_SIZEOF_* constants defined in
