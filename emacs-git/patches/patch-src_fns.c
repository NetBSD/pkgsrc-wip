$NetBSD$

Fix ctype(3) usage.
https://debbugs.gnu.org/cgi/bugreport.cgi?bug=73307

--- src/fns.c.orig	2024-09-16 21:11:40.908684144 +0000
+++ src/fns.c
@@ -3579,7 +3579,7 @@ by a mouse, or by some window-system ges
   {
     char *s = SSDATA (prompt);
     ptrdiff_t len = strlen (s);
-    if ((len > 0) && !isspace (s[len - 1]))
+    if ((len > 0) && !isspace ((unsigned char)s[len - 1]))
       prompt = CALLN (Fconcat, prompt, build_string (" "));
   }
   prompt = CALLN (Fconcat, prompt, Vyes_or_no_prompt);
