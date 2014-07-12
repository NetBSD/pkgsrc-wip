$NetBSD: patch-src_od-fs_bsdsocket__posix.cpp,v 1.3 2014/07/12 15:45:22 rhialto Exp $

u_int8_t * won't automagically become const char *.

--- src/od-fs/bsdsocket_posix.cpp.orig	2014-05-13 17:57:42.000000000 +0000
+++ src/od-fs/bsdsocket_posix.cpp
@@ -928,7 +928,7 @@ static void *bsdlib_threadfunc (void *ar
         break;
 
         case 7: {
-        struct hostent *tmphostent = gethostbyaddr (get_real_address (sb->name), sb->a_addrlen, sb->flags);
+        struct hostent *tmphostent = gethostbyaddr ((const char *)get_real_address (sb->name), sb->a_addrlen, sb->flags);
 
         if (tmphostent) {
             copyHostent (tmphostent, sb);
