$NetBSD$

- Use monotonic clock for timeouts

FreeBSD Bugzilla - Bug 225415  graphics/mesa-dri: update to 18.0.0
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415

--- src/util/os_time.c.orig	2018-05-11 23:27:04.000000000 +0000
+++ src/util/os_time.c
@@ -95,7 +95,7 @@ os_time_get_nano(void)
 void
 os_time_sleep(int64_t usecs)
 {
-#if defined(PIPE_OS_LINUX)
+#if (defined(HAVE_CLOCK_NANOSLEEP) && defined(USE_CLOCK_NANOSLEEP_OS_TIME)) || defined(PIPE_OS_LINUX)
    struct timespec time;
    time.tv_sec = usecs / 1000000;
    time.tv_nsec = (usecs % 1000000) * 1000;
