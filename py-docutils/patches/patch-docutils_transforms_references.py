$NetBSD$

--- docutils/transforms/references.py.orig	2025-07-29 14:37:38.409054500 +0000
+++ docutils/transforms/references.py
@@ -542,10 +542,12 @@ class Footnotes(Transform):
             try:
                 label = self.autofootnote_labels[i]
             except IndexError:
+                n = len(self.autofootnote_labels)
+                s = 's' if n > 1 else ''
                 msg = self.document.reporter.error(
-                      'Too many autonumbered footnote references: only %s '
-                      'corresponding footnotes available.'
-                      % len(self.autofootnote_labels), base_node=ref)
+                          'Too many autonumbered footnote references: '
+                          f'only {n} corresponding footnote{s} available.',
+                          base_node=ref)
                 msgid = self.document.set_id(msg)
                 for ref in self.document.autofootnote_refs[i:]:
                     if ref.resolved or ref.hasattr('refname'):
