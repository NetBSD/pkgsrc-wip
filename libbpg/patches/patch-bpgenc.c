$NetBSD: patch-bpgenc.c,v 1.2 2015/02/02 13:13:26 thomasklausner Exp $

Use getopt_long instead of getopt_long_only since it's more portable
(e.g., exists on NetBSD).

--- bpgenc.c.orig	2015-01-11 16:17:07.000000000 +0000
+++ bpgenc.c
@@ -2721,7 +2721,7 @@ int main(int argc, char **argv)
     frame_delay_file = NULL;
     
     for(;;) {
-        c = getopt_long_only(argc, argv, "q:o:hf:c:vm:b:e:a", long_opts, &option_index);
+        c = getopt_long(argc, argv, "q:o:hf:c:vm:b:e:a", long_opts, &option_index);
         if (c == -1)
             break;
         switch(c) {
