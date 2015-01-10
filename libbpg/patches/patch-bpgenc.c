$NetBSD: patch-bpgenc.c,v 1.1 2015/01/10 09:41:23 thomasklausner Exp $

Use getopt_long instead of getopt_long_only since it's more portable
(e.g., exists on NetBSD).

--- bpgenc.c.orig	2014-12-18 21:10:00.000000000 +0000
+++ bpgenc.c
@@ -2155,7 +2155,7 @@ int main(int argc, char **argv)
     premultiplied_alpha = 0;
     
     for(;;) {
-        c = getopt_long_only(argc, argv, "q:o:hf:c:vm:b:e:", long_opts, &option_index);
+        c = getopt_long(argc, argv, "q:o:hf:c:vm:b:e:", long_opts, &option_index);
         if (c == -1)
             break;
         switch(c) {
