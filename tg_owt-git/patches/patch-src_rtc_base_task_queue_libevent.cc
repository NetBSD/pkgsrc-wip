$NetBSD$

--- src/rtc_base/task_queue_libevent.cc.orig	2021-02-25 17:44:32.125524582 +0000
+++ src/rtc_base/task_queue_libevent.cc
@@ -27,7 +27,7 @@
 #include "absl/strings/string_view.h"
 #include "api/task_queue/queued_task.h"
 #include "api/task_queue/task_queue_base.h"
-#include "base/third_party/libevent/event.h"
+#include <event.h>
 #include "rtc_base/checks.h"
 #include "rtc_base/critical_section.h"
 #include "rtc_base/logging.h"
