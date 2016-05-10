$NetBSD$

NetBSD provides a timespecadd macro in sys/time.h, which conflicts with this one.

--- js/src/threading/posix/ConditionVariable.cpp.orig	2016-05-10 09:55:11.875611541 +0000
+++ js/src/threading/posix/ConditionVariable.cpp
@@ -37,7 +37,7 @@ static const clockid_t WhichClock = CLOC
 // timespec structure is largely lacking such conveniences. Thankfully, the
 // utilities available in MFBT make implementing our own quite easy.
 static void
-timespecadd(struct timespec* lhs, struct timespec* rhs, struct timespec* result)
+moz_timespecadd(struct timespec* lhs, struct timespec* rhs, struct timespec* result)
 {
   // Add nanoseconds. This may wrap, but not above 2 billion.
   MOZ_RELEASE_ASSERT(lhs->tv_nsec < NanoSecPerSec);
@@ -149,7 +149,7 @@ js::ConditionVariable::wait_for(UniqueLo
   MOZ_RELEASE_ASSERT(!r);
 
   struct timespec abs_ts;
-  timespecadd(&now_ts, &rel_ts, &abs_ts);
+  moz_timespecadd(&now_ts, &rel_ts, &abs_ts);
 
   r = pthread_cond_timedwait(ptCond, ptMutex, &abs_ts);
 #else
