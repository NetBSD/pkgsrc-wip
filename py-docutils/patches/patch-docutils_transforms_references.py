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
@@ -953,11 +955,29 @@ class DanglingReferencesVisitor(nodes.Sp
         if refname in self.document.nameids:
             msg = self.document.reporter.error(
                 'Duplicate target name, cannot be used as a unique '
-                'reference: "%s".' % (node['refname']), base_node=node)
+                f'reference: "{refname}".', base_node=node)
         else:
+            if '<' in refname or '>' in refname:
+                hint = 'Did you want to embed a URI or alias?'
+                if '<' not in refname:
+                    hint += '\nOpening bracket missing.'
+                elif ' <' not in refname:
+                    hint += ('\nThe embedded reference must be preceded'
+                             ' by whitespace.')
+                if '>' not in refname:
+                    hint += '\nClosing bracket missing.'
+                elif not refname.endswith('>'):
+                    hint += ('\nThe embedded reference must be the last text'
+                             ' before the end string.')
+                if '< ' in refname or ' >' in refname:
+                    hint += ('\nWhitespace around the embedded reference'
+                             ' is not allowed.')
+                details = [nodes.paragraph('', hint)]
+            else:
+                details = []
             msg = self.document.reporter.error(
-                f'Unknown target name: "{node["refname"]}".',
-                base_node=node)
+                      f'Unknown target name: "{refname}".',
+                      *details, base_node=node)
         msgid = self.document.set_id(msg)
         prb = nodes.problematic(node.rawsource, node.rawsource, refid=msgid)
         try:
