$NetBSD$

--- src/rtc_base/task_queue_libevent.cc.orig	2021-03-01 12:27:11.826517971 +0000
+++ src/rtc_base/task_queue_libevent.cc
@@ -27,7 +27,7 @@
 #include "absl/strings/string_view.h"
 #include "api/task_queue/queued_task.h"
 #include "api/task_queue/task_queue_base.h"
-#include "base/third_party/libevent/event.h"
+#include <event.h>
 #include "rtc_base/checks.h"
 #include "rtc_base/logging.h"
 #include "rtc_base/numerics/safe_conversions.h"
