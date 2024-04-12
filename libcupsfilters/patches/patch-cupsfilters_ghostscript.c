$NetBSD$

--- cupsfilters/ghostscript.c.orig	2023-09-21 22:21:04.000000000 +0000
+++ cupsfilters/ghostscript.c
@@ -613,7 +613,7 @@ gs_spawn (const char *filename,
     }
 
     // Execute Ghostscript command line ...
-    execvpe(filename, gsargv, envp);
+    execve(filename, gsargv, envp);
     if (log) log(ld, CF_LOGLEVEL_ERROR,
 		 "cfFilterGhostscript: Unable to launch Ghostscript: %s: %s",
 		 filename, strerror(errno));
