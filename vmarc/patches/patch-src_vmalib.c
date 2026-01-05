$NetBSD$

- use <utime.h> instead of <sys/utime.h>
- ctype macros need unsigned char as argument.

--- src/vmalib.c.orig	2020-08-10 17:42:52.000000000 +0000
+++ src/vmalib.c
@@ -23,7 +23,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 
-#if defined( linux ) || defined( __APPLE__ ) || defined(__MVS__)
+#if defined( linux ) || defined( __APPLE__ ) || defined(__MVS__) || defined(__NetBSD__)
 #include <utime.h>
 #else
 #include <sys/utime.h>
@@ -4198,7 +4198,7 @@ vma_setname( void *vvma, const char *fn,
             case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
             case 'S': case 'T': case 'U': case 'V': case 'W': case 'Y':
             case 'Z':
-                if( isdigit( fm[ 1 ] ) )
+                if( isdigit( (unsigned char)fm[ 1 ] ) )
                 {
                     break;
                 }
