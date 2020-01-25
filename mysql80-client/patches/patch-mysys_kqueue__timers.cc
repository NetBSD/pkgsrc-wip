$NetBSD$

* support pre NetBSD 10 __intptr_t udata type
* Fix for systems whcich do not define EVFILT_USER

--- mysys/kqueue_timers.cc.orig	2019-12-09 19:53:17.000000000 +0000
+++ mysys/kqueue_timers.cc
@@ -40,6 +40,18 @@
 #include "mysys_err.h"
 #include "mysys_priv.h" /* key_thread_timer_notifier */
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ < 999001400
+#define KEVENT_UDATA_TYPE_CAST (__intptr_t)
+#else
+#define KEVENT_UDATA_TYPE_CAST
+#endif
+#else
+#define KEVENT_UDATA_TYPE_CAST
+#endif
+
+
 /* Kernel event queue file descriptor. */
 static int kq_fd = -1;
 
@@ -69,11 +81,14 @@ static void *timer_notify_thread_func(vo
     }
 
     if (kev.filter == EVFILT_TIMER) {
-      timer = static_cast<my_timer_t *>(kev.udata);
+      timer = static_cast<my_timer_t *>((void *)kev.udata);
       DBUG_ASSERT(timer->id == kev.ident);
       timer->notify_function(timer);
-    } else if (kev.filter == EVFILT_USER)
+    }
+#ifdef EVFILT_USER
+      else if (kev.filter == EVFILT_USER)
       break;
+#endif
   }
 
   close(kq_fd);
@@ -91,7 +106,9 @@ static void *timer_notify_thread_func(vo
 static int start_helper_thread(void) {
   struct kevent kev;
 
+#ifdef EVFILT_USER
   EV_SET(&kev, 0, EVFILT_USER, EV_ADD, 0, 0, 0);
+#endif
 
   if (kevent(kq_fd, &kev, 1, NULL, 0, NULL) < 0) {
     my_message_local(ERROR_LEVEL, EE_FAILED_TO_CREATE_TIMER, errno);
@@ -134,7 +151,9 @@ int my_timer_initialize(void) {
 void my_timer_deinitialize(void) {
   struct kevent kev;
 
+#ifdef EVFILT_USER
   EV_SET(&kev, 0, EVFILT_USER, 0, NOTE_TRIGGER, 0, 0);
+#endif
 
   if (kevent(kq_fd, &kev, 1, NULL, 0, NULL) < 0)
     my_message_local(ERROR_LEVEL,
@@ -174,7 +193,7 @@ int my_timer_create(my_timer_t *timer) {
 int my_timer_set(my_timer_t *timer, unsigned long time) {
   struct kevent kev;
 
-  EV_SET(&kev, timer->id, EVFILT_TIMER, EV_ADD | EV_ONESHOT, 0, time, timer);
+  EV_SET(&kev, timer->id, EVFILT_TIMER, EV_ADD | EV_ONESHOT, 0, time,KEVENT_UDATA_TYPE_CAST timer);
 
   return kevent(kq_fd, &kev, 1, NULL, 0, NULL);
 }
