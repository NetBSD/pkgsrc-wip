$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/physical_socket_server.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ third_party/webrtc/rtc_base/physical_socket_server.cc
@@ -65,7 +65,7 @@
 #include "rtc_base/synchronization/mutex.h"
 #include "rtc_base/time_utils.h"
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <linux/sockios.h>
 #endif
 
@@ -85,7 +85,7 @@ typedef void* SockOptArg;
 
 #endif  // WEBRTC_POSIX
 
-#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__)
+#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__) && !defined(WEBRTC_BSD)
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
@@ -340,7 +340,7 @@ int PhysicalSocket::GetOption(Option opt
     return -1;
   }
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
   } else if (opt == OPT_DSCP) {
@@ -369,7 +369,7 @@ int PhysicalSocket::SetOption(Option opt
   if (TranslateOption(opt, &slevel, &sopt) == -1)
     return -1;
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
   } else if (opt == OPT_DSCP) {
@@ -400,7 +400,7 @@ int PhysicalSocket::SetOption(Option opt
 int PhysicalSocket::Send(const void* pv, size_t cb) {
   int sent = DoSend(
       s_, reinterpret_cast<const char*>(pv), static_cast<int>(cb),
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
       // Suppress SIGPIPE. Without this, attempting to send on a socket whose
       // other end is closed will result in a SIGPIPE signal being raised to
       // our process, which by default will terminate the process, which we
@@ -429,7 +429,7 @@ int PhysicalSocket::SendTo(const void* b
   size_t len = addr.ToSockAddrStorage(&saddr);
   int sent =
       DoSendTo(s_, static_cast<const char*>(buffer), static_cast<int>(length),
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
                // Suppress SIGPIPE. See above for explanation.
                MSG_NOSIGNAL,
 #else
@@ -707,7 +707,7 @@ int PhysicalSocket::TranslateOption(Opti
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
@@ -756,7 +756,7 @@ int PhysicalSocket::TranslateOption(Opti
       return -1;
 #endif
     case OPT_RECV_ECN:
-#if defined(WEBRTC_POSIX)
+#if defined(WEBRTC_POSIX) && defined(IP_RECVTOS) 
       if (family_ == AF_INET6) {
         *slevel = IPPROTO_IPV6;
         *sopt = IPV6_RECVTCLASS;
@@ -776,10 +776,19 @@ int PhysicalSocket::TranslateOption(Opti
       *sopt = SO_KEEPALIVE;
       break;
     case OPT_TCP_KEEPCNT:
+#if !defined(TCP_KEEPCNT)
+      RTC_LOG(LS_WARNING) << "Socket::OPT_TCP_KEEPCNT not supported.";
+      return -1;
+#else
       *slevel = IPPROTO_TCP;
       *sopt = TCP_KEEPCNT;
       break;
+#endif
     case OPT_TCP_KEEPIDLE:
+#if !defined(TCP_KEEPALIVE)
+      RTC_LOG(LS_WARNING) << "Socket::OPT_TCP_KEEPALIVE not supported.";
+      return -1;
+#else
       *slevel = IPPROTO_TCP;
 #if !defined(WEBRTC_MAC)
       *sopt = TCP_KEEPIDLE;
@@ -787,12 +796,18 @@ int PhysicalSocket::TranslateOption(Opti
       *sopt = TCP_KEEPALIVE;
 #endif
       break;
+#endif
     case OPT_TCP_KEEPINTVL:
+#if !defined(TCP_KEEPALIVE)
+      RTC_LOG(LS_WARNING) << "Socket::OPT_TCP_KEEPINTVL not supported.";
+      return -1;
+#else
       *slevel = IPPROTO_TCP;
       *sopt = TCP_KEEPINTVL;
       break;
+#endif
     case OPT_TCP_USER_TIMEOUT:
-#if defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#if (defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)) && defined(TCP_USER_TIMEOUT)
       *slevel = IPPROTO_TCP;
       *sopt = TCP_USER_TIMEOUT;
       break;
