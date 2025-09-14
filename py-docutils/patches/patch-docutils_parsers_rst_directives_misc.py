$NetBSD$

--- docutils/parsers/rst/directives/misc.py.orig	2025-07-29 14:37:38.096681000 +0000
+++ docutils/parsers/rst/directives/misc.py
@@ -236,8 +236,6 @@ class Include(Directive):
     def insert_into_input_lines(self, text: str) -> None:
         """Insert file content into the rST input of the calling parser.
 
-        Returns an empty list to comply with the API of `Directive.run()`.
-
         Provisional.
         """
         source = self.options['source']
