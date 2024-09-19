$NetBSD$

--- include/iprt/time.h.orig	2016-03-04 19:23:02.000000000 +0000
+++ include/iprt/time.h
@@ -353,7 +353,7 @@ DECLINLINE(void) RTTimeSpecGetSecondsAnd
 
 
 /* PORTME: Add struct timeval guard macro here. */
-#if defined(RTTIME_INCL_TIMEVAL) || defined(_STRUCT_TIMEVAL) || defined(_SYS__TIMEVAL_H_) || defined(_SYS_TIME_H) || defined(_TIMEVAL) || defined(_LINUX_TIME_H)
+#if defined(RTTIME_INCL_TIMEVAL) || defined(_STRUCT_TIMEVAL) || defined(_SYS__TIMEVAL_H_) || defined(_SYS_TIME_H) || defined(_TIMEVAL) || defined(_LINUX_TIME_H) || defined(_SYS_TIME_H_)
 /**
  * Gets the time as POSIX timeval.
  *
@@ -1031,4 +1031,3 @@ RTDECL(uint64_t) RTTimeProgramStartNanoT
 RT_C_DECLS_END
 
 #endif
-
