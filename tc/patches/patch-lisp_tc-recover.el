$NetBSD: patch-lisp_tc-recover.el,v 1.1 2013/12/15 14:21:09 makoto Exp $

Fix following problem
  Emacs-20 (20.7) -> Symbol's function definition is void: coding-system-from-name
  Emacs-21 (21.4) -> Symbol's function definition is void: coding-system-from-name
  Emacs-22 (22.3) -> Symbol's function definition is void: coding-system-from-name
This file is used only when byte compile of BATCH-SORT, and not to be installed.

--- /dev/null	2013-12-15 21:37:29.000000000 +0900
+++ lisp/tc-recover.el	2013-12-15 21:42:13.000000000 +0900
@@ -0,0 +1,43 @@
+;; tc-recover.el
+;; For Emacs-23.0-Versions before 2009-01-27.
+;; CVSWeb URLs:
+;; http://cvs.savannah.gnu.org/viewcvs/emacs/lisp/international/mule-cmds.el?cvsroot=emacs&r1=1.355&r2=1.356
+(when (not (and (fboundp 'canonicalize-coding-system-name)
+                (fboundp 'coding-system-from-name)))
+  ;; Canonicalize the coding system name NAME by removing some prefixes
+  ;; and delimiter characters. Support function of
+  ;; coding-system-from-name.
+  (defun canonicalize-coding-system-name (name)
+    (if (string-match "^iso[-_ ]?[0-9]" name)
+        ;; "iso-8859-1" -> "8859-1", "iso-2022-jp" ->"2022-jp"
+        (setq name (substring name (1- (match-end 0)))))
+    (let ((idx (string-match "[-_ /]" name)))
+      ;; Delete "-", "_", " ", "/" but do distinguish "16-be" and "16be".
+      (while idx
+        (if (and (>= idx 2)
+                 (eq (string-match "16-[lb]e$" name (- idx 2))
+                     (- idx 2)))
+            (setq idx (string-match "[-_ /]" name (match-end 0)))
+          (setq name (concat (substring name 0 idx) (substring name (1+ idx)))
+                idx (string-match "[-_ /]" name idx))))
+      name))
+
+  (defun coding-system-from-name (name)
+    "Return a coding system whose name matches with NAME (string or symbol)."
+    (let (sym)
+      (if (stringp name) (setq sym (intern name))
+        (setq sym name name (symbol-name name)))
+      (if (coding-system-p sym)
+          sym
+        (let ((eol-type
+               (if (string-match "-\\(unix\\|dos\\|mac\\)$" name)
+                   (prog1 (intern (match-string 1 name))
+                     (setq name (substring name 0 (match-beginning 0)))))))
+          (setq name (canonicalize-coding-system-name (downcase name)))
+          (catch 'tag
+            (dolist (elt (coding-system-list))
+              (if (string= (canonicalize-coding-system-name (symbol-name elt))
+                           name)
+                  (throw 'tag (if eol-type (coding-system-change-eol-conversion
+                                            elt eol-type)
+                                elt))))))))))
