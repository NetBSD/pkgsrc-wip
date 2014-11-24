$NetBSD: patch-src_daemon_main.c,v 1.3 2014/11/24 22:40:15 makoto Exp $

Only display Linux-specific warning on Linux.

--- src/daemon/main.c~	2014-11-25 01:06:34.000000000 +0900
+++ src/daemon/main.c	2014-11-25 01:07:27.000000000 +0900
@@ -999,10 +999,12 @@ int main(int argc, char *argv[]) {
 
     pa_disable_sigpipe();
 
+#if defined(__linux__)
     if (pa_rtclock_hrtimer())
         pa_log_info("Fresh high-resolution timers available! Bon appetit!");
     else
         pa_log_info("Dude, your kernel stinks! The chef's recommendation today is Linux with high-resolution timers enabled!");
+#endif
 
     if (conf->lock_memory) {
 #if defined(HAVE_SYS_MMAN_H) && !defined(__ANDROID__)
