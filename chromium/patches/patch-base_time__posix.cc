$NetBSD: patch-base_time__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/time_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/time_posix.cc
@@ -160,7 +160,7 @@ Time Time::FromExploded(bool is_local, c
 // FreeBSD 6 has CLOCK_MONOLITHIC but defines _POSIX_MONOTONIC_CLOCK to -1.
 #if (defined(OS_POSIX) &&                                               \
      defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK >= 0) || \
-     defined(OS_FREEBSD) || defined(OS_OPENBSD)
+     defined(OS_BSD)
 
 // static
 TimeTicks TimeTicks::Now() {
