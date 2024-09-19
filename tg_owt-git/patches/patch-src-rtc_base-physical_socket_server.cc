$NetBSD$

--- src/rtc_base/physical_socket_server.cc.orig	2021-02-03 11:42:41.000000000 +0000
+++ src/rtc_base/physical_socket_server.cc
@@ -73,7 +73,11 @@ typedef void* SockOptArg;
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
+#if defined(WEBRTC_LINUX)
   int ret = ioctl(socket, SIOCGSTAMP, &tv_ioctl);
+#elif defined(__NetBSD__)
+  int ret = ioctl(socket, SO_TIMESTAMP, &tv_ioctl);
+#endif
   if (ret != 0)
     return -1;
   int64_t timestamp =
@@ -571,7 +575,7 @@ int PhysicalSocket::TranslateOption(Opti
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(__NetBSD__) || defined(BSD) || defined(__native_client__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
