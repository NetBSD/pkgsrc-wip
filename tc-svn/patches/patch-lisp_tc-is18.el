$NetBSD: patch-lisp_tc-is18.el,v 1.1 2012/08/17 05:20:14 makoto Exp $

tc-is18.el:290:33:Warning: `unread-command-char' is an obsolete variable (as of before 19.15); 
use `unread-command-events' instead.  That variable is a list of events

--- lisp/tc-is18.el.orig	2012-08-17 13:57:57.000000000 +0900
+++ lisp/tc-is18.el	2012-08-17 14:15:05.000000000 +0900
@@ -136,7 +136,7 @@
     (save-window-excursion
       (catch 'search-done
 	(while t
-	  (or (>= unread-command-char 0)
+	  (or (>= unread-command-events 0)
 	      (progn
 		(or (input-pending-p)
 		    (isearch-message))
@@ -167,7 +167,7 @@
 	    ;; Meta character means exit search.
 	    (cond ((and (>= char 128)
 			search-exit-option)
-		   (setq unread-command-char char)
+		   (setq unread-command-events char)
 		   (throw 'search-done t))
 		  ((eq char search-exit-char)
 		   ;; Esc means exit search normally.
@@ -287,7 +287,7 @@
 			       (/= char search-quote-char)
 			       (or (= char ?\177)
 				   (and (< char ? ) (/= char ?\t) (/= char ?\r))))
-			  (setq unread-command-char char)
+			  (setq unread-command-events char)
 			  (throw 'search-done t))
 			 (t
 			  ;; Any other character => add it to the
@@ -584,7 +584,7 @@
 	(if success
 	    (setq other-end
 		  (if forward (match-beginning 0) (match-end 0)))))
-    (quit (setq unread-command-char ?\C-g)
+    (quit (setq unread-command-events ?\C-g)
 	  (setq success nil))
     (invalid-regexp (setq invalid-regexp (car (cdr lossage)))
 		    (if (string-match "\\`Premature \\|\\`Unmatched \\|\\`Invalid "
