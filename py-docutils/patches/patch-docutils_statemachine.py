$NetBSD$

--- docutils/statemachine.py.orig	2025-07-29 14:37:38.508729200 +0000
+++ docutils/statemachine.py
@@ -140,7 +140,6 @@ class StateMachine:
         - `initial_state`: a string, the class name of the initial state.
         - `debug`: a boolean; produce verbose output if true (nonzero).
         """
-
         self.input_lines = None
         """`StringList` of input lines (without newlines).
         Filled by `self.run()`."""
@@ -1406,7 +1405,7 @@ class StringList(ViewList):
             stripped = line.lstrip()
             if not stripped:            # blank line
                 if until_blank:
-                    blank_finish = 1
+                    blank_finish = True
                     break
             elif block_indent is None:
                 line_indent = len(line) - len(stripped)
@@ -1416,7 +1415,7 @@ class StringList(ViewList):
                     indent = min(indent, line_indent)
             end += 1
         else:
-            blank_finish = 1            # block ends at end of lines
+            blank_finish = True            # block ends at end of lines
         block = self[start:end]
         if first_indent is not None and block:
             block.data[0] = block.data[0][first_indent:]
