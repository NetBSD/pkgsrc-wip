$NetBSD$

--- docutils/parsers/rst/directives/parts.py.orig	2025-07-29 14:37:38.160271400 +0000
+++ docutils/parsers/rst/directives/parts.py
@@ -43,8 +43,8 @@ class Contents(Directive):
                    'class': directives.class_option}
 
     def run(self):
-        if not (self.state_machine.match_titles
-                or isinstance(self.state_machine.node, nodes.sidebar)):
+        if not isinstance(self.state_machine.node,
+                          (nodes.document, nodes.section, nodes.sidebar)):
             raise self.error('The "%s" directive may not be used within '
                              'topics or body elements.' % self.name)
         document = self.state_machine.document
