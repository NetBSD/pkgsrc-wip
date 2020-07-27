$NetBSD$

--- third_party/webrtc/rtc_base/physical_socket_server.cc.orig	2020-07-15 19:01:42.000000000 +0000
+++ third_party/webrtc/rtc_base/physical_socket_server.cc
@@ -69,7 +69,7 @@ typedef void* SockOptArg;
 
 #endif  // WEBRTC_POSIX
 
-#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__)
+#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__) && !defined(WEBRTC_BSD)
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
@@ -291,7 +291,7 @@ int PhysicalSocket::GetOption(Option opt
     return -1;
   }
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
   } else if (opt == OPT_DSCP) {
@@ -309,7 +309,7 @@ int PhysicalSocket::SetOption(Option opt
   if (TranslateOption(opt, &slevel, &sopt) == -1)
     return -1;
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
   } else if (opt == OPT_DSCP) {
@@ -550,10 +550,10 @@ int PhysicalSocket::TranslateOption(Opti
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__) && !defined(WEBRTC_BSD)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
-#elif defined(WEBRTC_POSIX)
+#elif defined(WEBRTC_POSIX) || 
       *slevel = IPPROTO_IP;
       *sopt = IP_MTU_DISCOVER;
       break;
