$NetBSD: patch-w3m.el,v 1.2 2012/03/02 23:52:39 makoto Exp $

Use an absolute path in invoking w3m.

--- w3m.el.orig	2011-09-07 23:15:48.000000000 +0000
+++ w3m.el
@@ -257,13 +257,13 @@ The valid values include `w3m', `w3mmee'
 ;; Set w3m-command, w3m-type, w3m-version and w3m-compile-options
 (if noninteractive ;; Don't call the external command when compiling.
     (unless w3m-command
-      (setq w3m-command "w3m"))
+      (setq w3m-command "@W3MPREFIX@/bin/w3m"))
   (when (or (null w3m-command)
 	    (null w3m-type)
 	    (null w3m-version)
 	    (null w3m-compile-options))
     (let ((command (or w3m-command
-		       (w3m-which-command "w3m")
+		       (w3m-which-command "@W3MPREFIX@/bin/w3m")
 		       (w3m-which-command "w3mmee")
 		       (w3m-which-command "w3m-m17n"))))
       (when command
