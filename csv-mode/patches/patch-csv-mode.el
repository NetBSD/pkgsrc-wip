$NetBSD: patch-csv-mode.el,v 1.1.1.1 2012/03/05 06:59:32 phonohawk Exp $

This patch enables to align multibyte characters. – Sugawara

--- csv-mode.el.orig	2012-03-05 06:34:22.000000000 +0000
+++ csv-mode.el
@@ -1006,7 +1006,7 @@ BEG and END specify the region to align.
 		(setq beg (point))	; beginning of current field
 		(while (not (eolp))
 		  (csv-end-of-field)
-		  (setq x (- (point) beg)) ; field width
+		  (setq x (string-width (buffer-substring beg (point)))) ; field width
 		  (if w
 		      (if (> x (car w)) (setcar w x))
 		    (setq w (list x)
@@ -1026,7 +1026,7 @@ BEG and END specify the region to align.
 		  (let ((left-padding 0) (right-padding 0) overlay)
 		    (csv-end-of-field)
 		    (set-marker end (point)) ; end of current field
-		    (setq x (- (point) beg) ; field width
+		    (setq x (string-width (buffer-substring beg (point))) ; field width
 			  x (- (car w) x)) ; required padding
 
 		    ;; beg = beginning of current field
