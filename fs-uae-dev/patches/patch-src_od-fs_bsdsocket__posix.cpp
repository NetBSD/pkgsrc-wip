$NetBSD: patch-src_od-fs_bsdsocket__posix.cpp,v 1.2 2014/04/06 13:33:55 rhialto Exp $

u_int8_t * won't automagically become const char *.

--- src/od-fs/bsdsocket_posix.cpp.orig	2014-03-25 19:40:59.000000000 +0000
+++ src/od-fs/bsdsocket_posix.cpp
@@ -928,7 +928,7 @@ static void *bsdlib_threadfunc (void *ar
         break;
 
         case 7: {
-        struct hostent *tmphostent = gethostbyaddr (get_real_address (sb->name), sb->a_addrlen, sb->flags);
+        struct hostent *tmphostent = gethostbyaddr ((const char *)get_real_address (sb->name), sb->a_addrlen, sb->flags);
 
         if (tmphostent) {
             copyHostent (tmphostent, sb);
