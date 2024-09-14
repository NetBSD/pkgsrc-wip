$NetBSD$

Add CLOCK_PROCESS_CPUTIME_ID and CLOCK_THREAD_CPUTIME_ID constants.

--- ../vendor/libc-0.2.158/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2024-09-14 03:51:01.201145252 +0000
+++ ../vendor/libc-0.2.158/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -1891,6 +1891,8 @@ pub const MNT_NOWAIT: ::c_int = 2;
 pub const MNT_LAZY: ::c_int = 3;

 //<sys/timex.h>
+pub const CLOCK_PROCESS_CPUTIME_ID: ::clockid_t = 2;
+pub const CLOCK_THREAD_CPUTIME_ID: ::clockid_t = 4;
 pub const NTP_API: ::c_int = 4;
 pub const MAXPHASE: ::c_long = 500000000;
 pub const MAXFREQ: ::c_long = 500000;
