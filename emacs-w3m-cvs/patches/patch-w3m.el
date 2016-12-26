$NetBSD: patch-w3m.el,v 1.3 2012/03/11 02:18:22 makoto Exp $

(1) Use an absolute path in invoking w3m.
(2) The Makefile in www/emacs-w3m puts icon directory to 
   share/emacs/etc/${EMACS_MAJOR_VERSION} while elisp code may not find
   the location. This adjusts that problem.

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
@@ -828,6 +828,10 @@
 		     (throw 'found-dir dir))
 		 (if (file-directory-p
 		      (setq dir
+			    (concat (expand-file-name "../../etc/w3m/" path) (number-to-string emacs-major-version ) "/")))
+		     (throw 'found-dir dir))
+		 (if (file-directory-p
+		      (setq dir
 			    (expand-file-name "../etc/w3m/icons/" path)))
 		     (throw 'found-dir dir)))))))
      (and (fboundp 'locate-data-directory)
