$NetBSD: patch-src_zm__rtp__source.cpp,v 1.6 2026/01/06 17:51:37 gdt Exp $

Fix type issue with tv_usec.

\todo Send upstream.

--- src/zm_rtp_source.cpp.orig	2026-05-28 12:42:49.000000000 +0000
+++ src/zm_rtp_source.cpp
@@ -203,7 +203,7 @@ void RtpSource::updateRtcpData(
   timeval ntpTime = zm::chrono::duration_cast<timeval>(
                       Seconds(ntpTimeSecs) + Microseconds((Microseconds::period::den * (ntpTimeFrac >> 16)) / (1 << 16)));
 
-  Debug(5, "ntpTime: %jd.%06ld, rtpTime: %x", static_cast<intmax_t>(ntpTime.tv_sec), ntpTime.tv_usec, rtpTime);
+  Debug(5, "ntpTime: %jd.%06ld, rtpTime: %x", static_cast<intmax_t>(ntpTime.tv_sec), static_cast<long>(ntpTime.tv_usec), rtpTime);
 
   if ( mBaseTimeNtp.tv_sec == 0 ) {
     mBaseTimeReal = std::chrono::system_clock::now();
@@ -213,7 +213,7 @@ void RtpSource::updateRtcpData(
     Debug(5, "lastSrNtpTime: %jd.%06ld, rtpTime: %x"
           "ntpTime: %jd.%06ld, rtpTime: %x",
           static_cast<intmax_t>(mLastSrTimeNtp.tv_sec), mLastSrTimeNtp.tv_usec, rtpTime,
-          static_cast<intmax_t>(ntpTime.tv_sec), ntpTime.tv_usec, rtpTime);
+          static_cast<intmax_t>(ntpTime.tv_sec), static_cast<long>(ntpTime.tv_usec), rtpTime);
 
     FPSeconds diffNtpTime =
       zm::chrono::duration_cast<Microseconds>(ntpTime) - zm::chrono::duration_cast<Microseconds>(mBaseTimeNtp);
