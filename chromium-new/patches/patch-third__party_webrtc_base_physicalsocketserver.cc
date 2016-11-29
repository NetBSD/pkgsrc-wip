$NetBSD$

--- third_party/webrtc/base/physicalsocketserver.cc.orig	2016-11-10 20:03:05.000000000 +0000
+++ third_party/webrtc/base/physicalsocketserver.cc
@@ -59,7 +59,7 @@ typedef void* SockOptArg;
 
 #endif  // WEBRTC_POSIX
 
-#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__)
+#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__) && !defined(WEBRTC_BSD)
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
@@ -276,7 +276,7 @@ int PhysicalSocket::GetOption(Option opt
   socklen_t optlen = sizeof(*value);
   int ret = ::getsockopt(s_, slevel, sopt, (SockOptArg)value, &optlen);
   if (ret != -1 && opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
   }
@@ -289,7 +289,7 @@ int PhysicalSocket::SetOption(Option opt
   if (TranslateOption(opt, &slevel, &sopt) == -1)
     return -1;
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
   }
@@ -571,10 +571,10 @@ int PhysicalSocket::TranslateOption(Opti
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__)
       LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
-#elif defined(WEBRTC_POSIX)
+#elif defined(WEBRTC_POSIX) && !defined(WEBRTC_BSD)
       *slevel = IPPROTO_IP;
       *sopt = IP_MTU_DISCOVER;
       break;
