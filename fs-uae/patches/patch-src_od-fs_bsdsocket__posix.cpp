$NetBSD: patch-src_od-fs_bsdsocket__posix.cpp,v 1.1 2013/10/25 22:02:17 rhialto Exp $

u_int8_t * won't automagically become const char *.

--- src/od-fs/bsdsocket_posix.cpp.orig	2013-06-25 19:21:16.000000000 +0000
+++ src/od-fs/bsdsocket_posix.cpp
@@ -929,7 +929,7 @@ static void *bsdlib_threadfunc (void *ar
         break;
 
         case 7: {
-        struct hostent *tmphostent = gethostbyaddr (get_real_address (sb->name), sb->a_addrlen, sb->flags);
+        struct hostent *tmphostent = gethostbyaddr ((const char *)get_real_address (sb->name), sb->a_addrlen, sb->flags);
 
         if (tmphostent) {
             copyHostent (tmphostent, sb);
