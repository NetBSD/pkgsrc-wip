$NetBSD: patch-src_od-fs_bsdsocket__posix.cpp,v 1.1 2013/11/15 12:26:23 rhialto Exp $

u_int8_t * won't automagically become const char *.

--- src/od-fs/bsdsocket_posix.cpp.orig	2013-10-23 17:58:00.000000000 +0000
+++ src/od-fs/bsdsocket_posix.cpp
@@ -929,7 +929,7 @@ static void *bsdlib_threadfunc (void *ar
         break;
 
         case 7: {
-        struct hostent *tmphostent = gethostbyaddr (get_real_address (sb->name), sb->a_addrlen, sb->flags);
+        struct hostent *tmphostent = gethostbyaddr ((const char *)get_real_address (sb->name), sb->a_addrlen, sb->flags);
 
         if (tmphostent) {
             copyHostent (tmphostent, sb);
