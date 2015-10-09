$NetBSD: patch-src_od-fs_bsdsocket__posix.cpp,v 1.5 2014/12/24 20:17:47 rhialto Exp $

u_int8_t * won't automagically become const char *.

--- src/od-fs/bsdsocket_posix.cpp.orig	2015-09-29 15:55:01.000000000 +0000
+++ src/od-fs/bsdsocket_posix.cpp
@@ -926,7 +926,7 @@ static void *bsdlib_threadfunc (void *ar
         break;
 
         case 7: {
-        struct hostent *tmphostent = gethostbyaddr (get_real_address (sb->name), sb->a_addrlen, sb->flags);
+        struct hostent *tmphostent = gethostbyaddr ((const char *)get_real_address (sb->name), sb->a_addrlen, sb->flags);
 
         if (tmphostent) {
             copyHostent (tmphostent, sb);
