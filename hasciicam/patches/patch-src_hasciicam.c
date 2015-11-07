$NetBSD$

o Avoid Linux-isms in order to support more operating systems that has
<sys/videoio.h>.
o Silent the warning:

 hasciicam.c:183:1: warning: initialization from incompatible pointer type [enabled by default]
  };
  ^
 hasciicam.c:183:1: warning: (near initialization for 'hascii_format.conversions') [enabled by default]

--- src/hasciicam.c.orig	2014-09-16 13:34:57.000000000 +0000
+++ src/hasciicam.c
@@ -42,8 +42,7 @@
 #include <pwd.h>
 #include <signal.h>
 
-#include <linux/types.h>
-#include <linux/videodev2.h>
+#include <sys/videoio.h>
 
 #include <aalib.h>
 
@@ -162,7 +161,7 @@ struct aa_savedata ascii_save;
 
 char hascii_header[1024];
 
-char *html_escapes[] =
+const char *html_escapes[] =
   { "<", "&lt;", ">", "&gt;", "&", "&amp;", NULL };
 
 struct aa_format hascii_format = {
