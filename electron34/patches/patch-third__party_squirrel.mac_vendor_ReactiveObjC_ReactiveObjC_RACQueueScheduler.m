$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/RACQueueScheduler.m.orig	2019-03-14 15:12:17.000000000 +0000
+++ third_party/squirrel.mac/vendor/ReactiveObjC/ReactiveObjC/RACQueueScheduler.m
@@ -48,8 +48,8 @@
 	double frac = modf(date.timeIntervalSince1970, &seconds);
 
 	struct timespec walltime = {
-		.tv_sec = (time_t)fmin(fmax(seconds, LONG_MIN), LONG_MAX),
-		.tv_nsec = (long)fmin(fmax(frac * NSEC_PER_SEC, LONG_MIN), LONG_MAX)
+		.tv_sec = (time_t)fmin(fmax(seconds, LONG_MIN), (double)LONG_MAX),
+		.tv_nsec = (long)fmin(fmax(frac * NSEC_PER_SEC, LONG_MIN), (double)LONG_MAX)
 	};
 
 	return dispatch_walltime(&walltime, 0);
