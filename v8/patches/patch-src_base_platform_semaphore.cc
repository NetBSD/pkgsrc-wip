$NetBSD: patch-src_base_platform_semaphore.cc,v 1.1 2014/08/26 10:37:49 heidnes Exp $

Copy over workaround for missing sem_timedwait() in NetBSD < 6.99.4
from the openjdk7 package.

--- src/base/platform/semaphore.cc.orig	2014-08-08 13:04:31.000000000 +0000
+++ src/base/platform/semaphore.cc
@@ -104,6 +104,33 @@ void Semaphore::Wait() {
   }
 }
 
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 699000400)
+static inline int
+sem_timedwait(sem_t *sem, struct timespec *ts) {
+  struct timespec onems = { 0, 1000000 };
+  struct timespec total = { 0, 0 };
+  struct timespec unslept;
+  struct timespec elapsed;
+  struct timespec tmp;
+
+  while (timespeccmp(ts, &total, >)) {
+    if (sem_trywait(sem) == 0)
+      return 0;
+
+    if (errno != EAGAIN)
+      return -1;
+
+    (void)nanosleep(&onems, &unslept);
+
+    timespecsub(&onems, &unslept, &elapsed);
+    timespecadd(&total, &elapsed, &tmp);
+    total.tv_sec = tmp.tv_sec;
+    total.tv_nsec = tmp.tv_nsec;
+  }
+  errno = ETIMEDOUT;
+  return -1;
+}
+#endif /* __NetBSD__ */
 
 bool Semaphore::WaitFor(const TimeDelta& rel_time) {
   // Compute the time for end of timeout.
