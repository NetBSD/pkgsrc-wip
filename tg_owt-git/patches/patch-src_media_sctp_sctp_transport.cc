$NetBSD$

--- src/media/sctp/sctp_transport.cc.orig	2020-11-13 06:17:31.000000000 +0000
+++ src/media/sctp/sctp_transport.cc
@@ -43,7 +43,7 @@ enum PreservedErrno {
 #include "rtc_base/thread_annotations.h"
 #include "rtc_base/thread_checker.h"
 #include "rtc_base/trace_event.h"
-#include "usrsctplib/usrsctp.h"
+#include <usrsctp.h>
 
 namespace {
 
@@ -470,7 +470,7 @@ class SctpTransport::UsrSctpWrapper {
     return transport;
   }
 
-  static int SendThresholdCallback(struct socket* sock, uint32_t sb_free) {
+  static int SendThresholdCallback(struct socket* sock, uint32_t sb_free, void *ulp_info) {
     // Fired on our I/O thread. SctpTransport::OnPacketReceived() gets
     // a packet containing acknowledgments, which goes into usrsctp_conninput,
     // and then back here.
