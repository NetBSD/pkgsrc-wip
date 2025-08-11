$NetBSD$

https://sourceforge.net/p/docutils/bugs/508/
https://sourceforge.net/p/docutils/bugs/509/

--- docutils/parsers/rst/states.py.orig	2025-07-29 14:37:37.894344600 +0000
+++ docutils/parsers/rst/states.py
@@ -169,7 +169,6 @@ class RSTStateMachine(StateMachineWS):
 
 
 class NestedStateMachine(StateMachineWS):
-
     """
     StateMachine run from within other StateMachine runs, to parse nested
     document structures.
@@ -177,7 +176,7 @@ class NestedStateMachine(StateMachineWS)
 
     def run(self, input_lines, input_offset, memo, node, match_titles=True):
         """
-        Parse `input_lines` and populate a `docutils.nodes.document` instance.
+        Parse `input_lines` and populate `node`.
 
         Extend `StateMachineWS.run()`: set up document-wide data.
         """
@@ -326,35 +325,53 @@ class RSTState(StateWS):
 
         When a new section is reached that isn't a subsection of the current
         section, set `self.parent` to the new section's parent section
-        (or the document if the new section is a top-level section).
+        (or the root node if the new section is a top-level section).
         """
         title_styles = self.memo.title_styles
         parent_sections = self.parent.section_hierarchy()
-        # current section level: (0 document, 1 section, 2 subsection, ...)
-        mylevel = len(parent_sections)
-        # Determine the level of the new section:
+        # Adding a new <section> at level "i" is done by appending to
+        # ``parent_sections[i-1].parent``.
+        # However, in nested parsing the root `node` may be a <section>.
+        # Then ``parent_sections[0]`` has no parent and must be discarded:
+        if parent_sections and parent_sections[0].parent is None:
+            parent_sections.pop(0)
+        # current section level: (0 root, 1 section, 2 subsection, ...)
+        oldlevel = len(parent_sections)
+        # new section level:
         try:  # check for existing title style
-            level = title_styles.index(style) + 1
+            newlevel = title_styles.index(style) + 1
         except ValueError:  # new title style
             title_styles.append(style)
-            level = len(title_styles)
+            newlevel = len(title_styles)
         # The new level must not be deeper than an immediate child
         # of the current level:
-        if level > mylevel + 1:
-            styles = " ".join("/".join(s for s in style)
-                              for style in title_styles)
+        if newlevel > oldlevel + 1:
+            styles = ' '.join('/'.join(style) for style in title_styles)
             self.parent += self.reporter.severe(
                 'Inconsistent title style:'
-                f' skip from level {mylevel} to {level}.',
+                f' skip from level {oldlevel} to {newlevel}.',
                 nodes.literal_block('', source),
                 nodes.paragraph('', f'Established title styles: {styles}'),
                 line=lineno)
             return False
         # Update parent state:
-        self.memo.section_level = level
-        if level <= mylevel:
+        self.memo.section_level = newlevel
+        if newlevel <= oldlevel:
             # new section is sibling or higher up in the section hierarchy
-            self.parent = parent_sections[level-1].parent
+            new_parent = parent_sections[newlevel-1].parent
+            if new_parent is None:
+                styles = ' '.join('/'.join(style) for style in title_styles)
+                self.parent += self.reporter.severe(
+                    f'Cannot skip from level {oldlevel} to {newlevel}.'
+                    ' Current element has only {len(self.parent_sections)'
+                    ' parent sections.'
+                    ' (Mismatch of `memo.section_styles`,'
+                    ' and the root node of a nested parser?)',
+                    nodes.literal_block('', source),
+                    nodes.paragraph('', f'Established title styles: {styles}'),
+                    line=lineno)
+                return False
+            self.parent = new_parent
         return True
 
     def title_inconsistent(self, sourcetext, lineno):
