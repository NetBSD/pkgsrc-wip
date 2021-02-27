$NetBSD$

--- src/rtc_base/physical_socket_server.cc.orig	2020-11-13 06:17:31.000000000 +0000
+++ src/rtc_base/physical_socket_server.cc
@@ -74,7 +74,11 @@ typedef void* SockOptArg;
 
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
@@ -551,7 +555,7 @@ int PhysicalSocket::TranslateOption(Opti
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(__NetBSD__) || defined(BSD) || defined(__native_client__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
