# $NetBSD$

disable multicasting support for now.

--- src/java.base/unix/native/libnio/ch/Net.c.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/java.base/unix/native/libnio/ch/Net.c	2021-06-10 22:03:29.665580058 -0400
@@ -93,6 +93,7 @@
 #define COPY_INET6_ADDRESS(env, source, target) \
     (*env)->GetByteArrayRegion(env, source, 0, 16, target)
 
+#if !defined(_ALLBSD_SOURCE) || defined(__OpenBSD__)
 /*
  * Copy IPv6 group, interface index, and IPv6 source address
  * into group_source_req structure.
@@ -112,6 +113,7 @@
     sin6->sin6_family = AF_INET6;
     COPY_INET6_ADDRESS(env, source, (jbyte *)&(sin6->sin6_addr));
 }
+#endif
 
 #ifdef _AIX
 
@@ -600,6 +602,10 @@
 Java_sun_nio_ch_Net_joinOrDrop4(JNIEnv *env, jobject this, jboolean join, jobject fdo,
                                 jint group, jint interf, jint source)
 {
+#if defined(_ALLBSD_SOURCE)
+    /* no IPv4 exclude-mode filtering for now */
+    return IOS_UNAVAILABLE;
+#else
     struct ip_mreq mreq;
     struct ip_mreq_source mreq_source;
     int opt, n, optlen;
@@ -642,6 +648,7 @@
         handleSocketError(env, errno);
     }
     return 0;
+#endif
 }
 
 JNIEXPORT jint JNICALL
@@ -683,7 +690,9 @@
                                 jbyteArray group, jint index, jbyteArray source)
 {
     struct ipv6_mreq mreq6;
+#if !defined(_ALLBSD_SOURCE) || defined(__OpenBSD__)
     struct group_source_req req;
+#endif
     int opt, n, optlen;
     void* optval;
 
@@ -694,7 +703,7 @@
         optval = (void*)&mreq6;
         optlen = sizeof(mreq6);
     } else {
-#ifdef __APPLE__
+#if defined(_ALLBSD_SOURCE) && !defined(__OpenBSD__)
         /* no IPv6 include-mode filtering for now */
         return IOS_UNAVAILABLE;
 #else
@@ -725,7 +734,7 @@
 Java_sun_nio_ch_Net_blockOrUnblock6(JNIEnv *env, jobject this, jboolean block, jobject fdo,
                                     jbyteArray group, jint index, jbyteArray source)
 {
-#if defined(_ALLBSD_SOURCE)
+#if defined(_ALLBSD_SOURCE) && !defined(__OpenBSD__)
     /* no IPv6 exclude-mode filtering for now */
     return IOS_UNAVAILABLE;
 #else
