$NetBSD$

--- src/util/u_process.c.orig	2019-03-15 01:02:19.000000000 +0000
+++ src/util/u_process.c
@@ -118,7 +118,7 @@ __getProgramName()
 #endif
 
 #if !defined(GET_PROGRAM_NAME)
-#    if defined(__OpenBSD__) || defined(NetBSD) || defined(__UCLIBC__) || defined(ANDROID)
+#    if defined(__OpenBSD__) || defined(NetBSD) || defined(__UCLIBC__) || defined(ANDROID) || defined(NO_GETPROGRAMNAME)
 /* This is a hack. It's said to work on OpenBSD, NetBSD and GNU.
  * Rogelio M.Serrano Jr. reported it's also working with UCLIBC. It's
  * used as a last resort, if there is no documented facility available. */
