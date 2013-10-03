$NetBSD: patch-mcs-e20.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

Derived from 
apel (10.8+0.20120427-4), 0.20120427-4.debian.tar.gz 
to fix Following problem:
 ----
 Loading `static': old-style backquotes detected!
 Loading `pym': old-style backquotes detected!
 Loading `product': old-style backquotes detected!
 Eager macro-expansion failure: (wrong-type-argument sequencep 769)
 Loading `poe': old-style backquotes detected!
 Wrong type argument: sequencep, 769
 gmake: *** [elc] Error 255
 ----

--- mcs-e20.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ mcs-e20.el	2013-10-03 19:33:10.000000000 +0900
@@ -90,11 +90,15 @@
      ((ascii korean-ksc5601)				. euc-kr)
      ((ascii chinese-gb2312)				. gb2312)
      ((ascii chinese-big5-1 chinese-big5-2)		. big5)
-     ((ascii thai-tis620 composition)			. tis-620)
-     ((ascii latin-iso8859-1 greek-iso8859-7
-	     latin-jisx0201 japanese-jisx0208-1978
-	     chinese-gb2312 japanese-jisx0208
-	     korean-ksc5601 japanese-jisx0212)		. iso-2022-jp-2)
+     ,(static-cond
+       ((null (string< mule-version "6.0"))
+	'((ascii thai-tis620)				. tis-620))
+       (t
+	'((ascii thai-tis620 composition)      		. tis-620)))
+     ;; ((ascii latin-iso8859-1 greek-iso8859-7
+     ;; 	     latin-jisx0201 japanese-jisx0208-1978
+     ;; 	     chinese-gb2312 japanese-jisx0208
+     ;; 	     korean-ksc5601 japanese-jisx0212)		. iso-2022-jp-2)
      ;;((ascii latin-iso8859-1 greek-iso8859-7
      ;;        latin-jisx0201 japanese-jisx0208-1978
      ;;        chinese-gb2312 japanese-jisx0208
@@ -119,8 +123,16 @@
 (defun coding-system-to-mime-charset (coding-system)
   "Convert CODING-SYSTEM to a MIME-charset.
 Return nil if corresponding MIME-charset is not found."
-  (or (car (rassq coding-system mime-charset-coding-system-alist))
-      (coding-system-get coding-system 'mime-charset)
+  (or (coding-system-get coding-system 'mime-charset)
+      (let ((coding (coding-system-base coding-system))
+	    (alist mime-charset-coding-system-alist)
+	    result)
+	(while alist
+	  (if (eq (coding-system-base (cdar alist)) coding)
+	      (setq result (caar alist)
+		    alist nil)
+	    (setq alist (cdr alist))))
+	result)
       ))
 
 (defun-maybe-cond mime-charset-list ()
