$NetBSD: patch-emacs-w3m_w3m.el,v 1.1 2012/03/02 23:52:39 makoto Exp $

The Makefile in www/emacs-w3m puts icon directory to 
   share/emacs/etc/${EMACS_MAJOR_VERSION} while elisp code may not find
   the location. This adjusts that problem.

--- w3m.el.orig	2012-03-01 20:45:08.000000000 +0900
+++ w3m.el	2012-03-01 22:24:17.000000000 +0900
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
