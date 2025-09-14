$NetBSD$

--- docutils/parsers/rst/directives/body.py.orig	2025-07-29 14:37:38.097654300 +0000
+++ docutils/parsers/rst/directives/body.py
@@ -19,9 +19,8 @@ from docutils.utils.code_analyzer import
 
 
 class BasePseudoSection(Directive):
+    """Base class for Topic and Sidebar."""
 
-    required_arguments = 1
-    optional_arguments = 0
     final_argument_whitespace = True
     option_spec = {'class': directives.class_option,
                    'name': directives.unchanged}
@@ -31,8 +30,8 @@ class BasePseudoSection(Directive):
     """Node class to be used (must be set in subclasses)."""
 
     def run(self):
-        if not (self.state_machine.match_titles
-                or isinstance(self.state_machine.node, nodes.sidebar)):
+        if not isinstance(self.state_machine.node,
+                          (nodes.document, nodes.section, nodes.sidebar)):
             raise self.error('The "%s" directive may not be used within '
                              'topics or body elements.' % self.name)
         self.assert_has_content()
@@ -64,15 +63,14 @@ class BasePseudoSection(Directive):
 
 class Topic(BasePseudoSection):
 
+    required_arguments = 1
     node_class = nodes.topic
 
 
 class Sidebar(BasePseudoSection):
 
-    node_class = nodes.sidebar
-
-    required_arguments = 0
     optional_arguments = 1
+    node_class = nodes.sidebar
     option_spec = BasePseudoSection.option_spec | {
                       'subtitle': directives.unchanged_required}
 
