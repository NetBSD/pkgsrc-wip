$NetBSD$

NetBSD is like FreeBSD here.

--- hifr.h.orig	2019-09-10 18:06:20.000000000 +0000
+++ hifr.h
@@ -110,7 +110,7 @@ struct hifr
 };
 typedef struct hifr hifr;
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
   #define  hifr_name       ifreq.ifr_name
 #else
   #define  hifr_name       ifreq.ifr_ifrn.ifrn_name
