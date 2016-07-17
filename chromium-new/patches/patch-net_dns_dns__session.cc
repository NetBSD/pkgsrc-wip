$NetBSD$

--- net/dns/dns_session.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/dns/dns_session.cc
@@ -224,7 +224,7 @@ void DnsSession::RecordRTT(unsigned serv
   base::TimeDelta current_error = rtt - estimate;
   estimate += current_error / 8;  // * alpha
   base::TimeDelta abs_error = base::TimeDelta::FromInternalValue(
-      std::abs(current_error.ToInternalValue()));
+      std::labs(current_error.ToInternalValue()));
   deviation += (abs_error - deviation) / 4;  // * delta
 
   // Histogram-based method.
