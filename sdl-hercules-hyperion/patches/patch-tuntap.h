$NetBSD$

NetBSD also uses "/dev/tun".

--- tuntap.h.orig	2019-09-10 18:06:20.000000000 +0000
+++ tuntap.h
@@ -25,7 +25,7 @@
 //  TunTap ioctl codes and Standard and TUNSETIFF ifr interface flags
 // ====================================================================
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
   #define  HERCTUN_DEV  "/dev/tun"     // Default TUN/TAP char dev
 #else
   #define  HERCTUN_DEV  "/dev/net/tun"  // Default TUN/TAP char dev
