$NetBSD$

--- docutils/nodes.py.orig	2025-07-29 14:37:37.467805600 +0000
+++ docutils/nodes.py
@@ -818,20 +818,23 @@ class Element(Node):
         return self.parent[i-1] if i > 0 else None
 
     def section_hierarchy(self) -> list[section]:
-        """Return the element's section hierarchy.
+        """Return the element's section anchestors.
 
-        Return a list of all <section> elements containing `self`
-        (including `self` if it is a <section>).
+        Return a list of all <section> elements that contain `self`
+        (including `self` if it is a <section>) and have a parent node.
 
         List item ``[i]`` is the parent <section> of level i+1
         (1: section, 2: subsection, 3: subsubsection, ...).
         The length of the list is the element's section level.
 
+        See `docutils.parsers.rst.states.RSTState.check_subsection()`
+        for a usage example.
+
         Provisional. May be changed or removed without warning.
         """
         sections = []
         node = self
-        while node is not None:
+        while node.parent is not None:
             if isinstance(node, section):
                 sections.append(node)
             node = node.parent
