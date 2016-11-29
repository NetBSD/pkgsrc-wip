$NetBSD$

--- net/dns/dns_session.cc.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/dns/dns_session.cc
@@ -228,7 +228,7 @@ void DnsSession::RecordRTT(unsigned serv
   base::TimeDelta current_error = rtt - estimate;
   estimate += current_error / 8;  // * alpha
   base::TimeDelta abs_error = base::TimeDelta::FromInternalValue(
-      std::abs(current_error.ToInternalValue()));
+      std::labs(current_error.ToInternalValue()));
   deviation += (abs_error - deviation) / 4;  // * delta
 
   // Histogram-based method.
