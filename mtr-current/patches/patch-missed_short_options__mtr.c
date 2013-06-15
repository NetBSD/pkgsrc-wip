$NetBSD: patch-missed_short_options__mtr.c,v 1.1 2013/06/15 16:00:13 yvs4sf Exp $

missed short options
https://bugs.launchpad.net/mtr/+bug/1189221

--- mtr.c.orig	2013-06-09 21:35:40.000000000 +0300
+++ mtr.c	2013-06-09 21:41:37.000000000 +0300
@@ -253,7 +253,6 @@
 void parse_arg (int argc, char **argv)
 {
   int opt;
-  int i;
   static struct option long_options[] = {
     { "version", 0, 0, 'v' },
     { "help", 0, 0, 'h' },
@@ -299,8 +298,16 @@
   opt = 0;
   while(1) {
     /* added f:m:o: byMin */
-    opt = getopt_long(argc, argv,
-		      "vhrwxtglCpo:B:i:c:s:Q:ena:f:m:uTP:Zby:z46", long_options, NULL);
+    char short_options[128] = {0};
+    char* p_short_options = short_options;
+    int i;
+    for (i = 0; i < ((sizeof(long_options) / sizeof(long_options[0])) - 1); i++) {
+	*p_short_options++ = (char)long_options[i].val;
+	if (long_options[i].has_arg)
+		*p_short_options++ = ':';
+	*p_short_options = '\0';
+    }
+    opt = getopt_long(argc, argv, short_options, long_options, NULL);
     if(opt == -1)
       break;
 
