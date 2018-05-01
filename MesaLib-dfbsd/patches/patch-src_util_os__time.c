$NetBSD$

Use monotonic clock for timeouts

FreeBSD Bugzilla - Bug 225415  graphics/mesa-dri: update to 18.0.0
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415

--- src/util/os_time.c.orig	2018-02-09 02:18:00.000000000 +0000
+++ src/util/os_time.c
@@ -55,7 +55,7 @@
 int64_t
 os_time_get_nano(void)
 {
-#if defined(PIPE_OS_LINUX)
+#if defined(PIPE_OS_BSD) || defined(PIPE_OS_LINUX)
 
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);
@@ -95,7 +95,7 @@ os_time_get_nano(void)
 void
 os_time_sleep(int64_t usecs)
 {
-#if defined(PIPE_OS_LINUX)
+#if defined(HAVE_CLOCK_NANOSLEEP) || defined(PIPE_OS_LINUX)
    struct timespec time;
    time.tv_sec = usecs / 1000000;
    time.tv_nsec = (usecs % 1000000) * 1000;
