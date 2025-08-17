$NetBSD$

--- docutils/parsers/rst/states.py.orig	2025-07-29 14:37:37.894344600 +0000
+++ docutils/parsers/rst/states.py
@@ -104,6 +104,7 @@ from __future__ import annotations
 
 __docformat__ = 'reStructuredText'
 
+import copy
 import re
 from types import FunctionType, MethodType
 from types import SimpleNamespace as Struct
@@ -121,6 +122,10 @@ from docutils.utils import split_escaped
 from docutils.utils._roman_numerals import (InvalidRomanNumeralError,
                                             RomanNumeral)
 
+TYPE_CHECKING = False
+if TYPE_CHECKING:
+    from docutils.statemachine import StringList
+
 
 class MarkupError(DataError): pass
 class UnknownInterpretedRoleError(DataError): pass
@@ -151,16 +156,19 @@ class RSTStateMachine(StateMachineWS):
         if inliner is None:
             inliner = Inliner()
         inliner.init_customizations(document.settings)
+        # A collection of objects to share with nested parsers.
+        # The attributes `reporter`, `section_level`, and
+        # `section_bubble_up_kludge` will be removed in Docutils 2.0
         self.memo = Struct(document=document,
-                           reporter=document.reporter,
+                           reporter=document.reporter,  # ignored
                            language=self.language,
                            title_styles=[],
-                           section_level=0,  # ignored, to be removed in 2.0
-                           section_bubble_up_kludge=False,  # ignored, ""
+                           section_level=0,  # ignored
+                           section_bubble_up_kludge=False,  # ignored
                            inliner=inliner)
         self.document = document
         self.attach_observer(document.note_source)
-        self.reporter = self.memo.reporter
+        self.reporter = self.document.reporter
         self.node = document
         results = StateMachineWS.run(self, input_lines, input_offset,
                                      input_source=document['source'])
@@ -169,7 +177,6 @@ class RSTStateMachine(StateMachineWS):
 
 
 class NestedStateMachine(StateMachineWS):
-
     """
     StateMachine run from within other StateMachine runs, to parse nested
     document structures.
@@ -177,17 +184,28 @@ class NestedStateMachine(StateMachineWS)
 
     def run(self, input_lines, input_offset, memo, node, match_titles=True):
         """
-        Parse `input_lines` and populate a `docutils.nodes.document` instance.
+        Parse `input_lines` and populate `node`.
+
+        Use a separate "title style hierarchy" if `node` is not
+        attached to the document (changed in Docutils 0.23).
 
         Extend `StateMachineWS.run()`: set up document-wide data.
         """
         self.match_titles = match_titles
-        self.memo = memo
+        self.memo = copy.copy(memo)
         self.document = memo.document
         self.attach_observer(self.document.note_source)
-        self.reporter = memo.reporter
         self.language = memo.language
+        self.reporter = self.document.reporter
         self.node = node
+        if match_titles:
+            # Start a new title style hierarchy if `node` is not
+            # a descendant of the `document`:
+            _root = node
+            while _root.parent is not None:
+                _root = _root.parent
+            if _root != self.document:
+                self.memo.title_styles = []
         results = StateMachineWS.run(self, input_lines, input_offset)
         assert results == [], ('NestedStateMachine.run() results should be '
                                'empty!')
@@ -214,9 +232,9 @@ class RSTState(StateWS):
         StateWS.runtime_init(self)
         memo = self.state_machine.memo
         self.memo = memo
-        self.reporter = memo.reporter
-        self.inliner = memo.inliner
         self.document = memo.document
+        self.inliner = memo.inliner
+        self.reporter = self.document.reporter
         self.parent = self.state_machine.node
         # enable the reporter to determine source and source-line
         if not hasattr(self.reporter, 'get_source_and_line'):
@@ -248,11 +266,40 @@ class RSTState(StateWS):
         """Called at beginning of file."""
         return [], []
 
-    def nested_parse(self, block, input_offset, node, match_titles=False,
-                     state_machine_class=None, state_machine_kwargs=None):
-        """
-        Create a new StateMachine rooted at `node` and run it over the input
-        `block`.
+    def nested_parse(self,
+                     block: StringList,
+                     input_offset: int,
+                     node: nodes.Element,
+                     match_titles: bool = False,
+                     state_machine_class: StateMachineWS|None = None,
+                     state_machine_kwargs: dict|None = None
+                     ) -> int:
+        """
+        Parse the input `block` with a nested state-machine rooted at `node`.
+
+        :block:
+            reStructuredText source extract.
+        :input_offset:
+            Line number at start of the block.
+        :node:
+            Base node. Generated nodes will be appended to this node
+            (unless a new section with lower level is encountered, see below).
+        :match_titles:
+            Allow section titles?
+            If the base `node` is attached to the document, new sections will
+            be appended according their level in the section hierarchy
+            (moving up the tree).
+            If the base `node` is *not* attached to the document,
+            a separate section title style hierarchy is used for the nested
+            parsing (all sections are subsections of the current section).
+        :state_machine_class:
+            Default: `NestedStateMachine`.
+        :state_machine_kwargs:
+            Keyword arguments for the state-machine instantiation.
+            Default: `self.nested_sm_kwargs`.
+
+        Create a new state-machine instance if required.
+        Return new offset.
         """
         use_default = 0
         if state_machine_class is None:
@@ -261,8 +308,6 @@ class RSTState(StateWS):
         if state_machine_kwargs is None:
             state_machine_kwargs = self.nested_sm_kwargs
             use_default += 1
-        block_length = len(block)
-
         state_machine = None
         if use_default == 2:
             try:
@@ -272,8 +317,11 @@ class RSTState(StateWS):
         if not state_machine:
             state_machine = state_machine_class(debug=self.debug,
                                                 **state_machine_kwargs)
+        # run the statemachine and populate `node`:
+        block_length = len(block)
         state_machine.run(block, input_offset, memo=self.memo,
                           node=node, match_titles=match_titles)
+        # clean up
         if use_default == 2:
             self.nested_sm_cache.append(state_machine)
         else:
@@ -293,9 +341,15 @@ class RSTState(StateWS):
                           state_machine_class=None,
                           state_machine_kwargs=None):
         """
-        Create a new StateMachine rooted at `node` and run it over the input
-        `block`. Also keep track of optional intermediate blank lines and the
+        Parse the input `block` with a nested state-machine rooted at `node`.
+
+        Create a new StateMachine rooted at `node` and run it over the
+        input `block` (see also `nested_parse()`).
+        Also keep track of optional intermediate blank lines and the
         required final one.
+
+        Return new offset and a boolean indicating whether there was a
+        blank final line.
         """
         if state_machine_class is None:
             state_machine_class = self.nested_sm
@@ -326,40 +380,45 @@ class RSTState(StateWS):
 
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
+        # current section level: (0 root, 1 section, 2 subsection, ...)
+        oldlevel = len(parent_sections)
+        # new section level:
         try:  # check for existing title style
-            level = title_styles.index(style) + 1
+            newlevel = title_styles.index(style) + 1
         except ValueError:  # new title style
-            title_styles.append(style)
-            level = len(title_styles)
+            newlevel = len(title_styles) + 1
         # The new level must not be deeper than an immediate child
         # of the current level:
-        if level > mylevel + 1:
-            styles = " ".join("/".join(s for s in style)
-                              for style in title_styles)
-            self.parent += self.reporter.severe(
+        if newlevel > oldlevel + 1:
+            styles = ' '.join('/'.join(style) for style in title_styles)
+            self.parent += self.reporter.error(
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
+        if newlevel > len(title_styles):
+            title_styles.append(style)
+        self.memo.section_level = newlevel
+        if newlevel > oldlevel:
+            # new section is a subsection: get the current section or base node
+            while self.parent.parent and not isinstance(
+                      self.parent, (nodes.section, nodes.document)):
+                self.parent = self.parent.parent
+        else:
             # new section is sibling or higher up in the section hierarchy
-            self.parent = parent_sections[level-1].parent
+            self.parent = parent_sections[newlevel-1].parent
         return True
 
     def title_inconsistent(self, sourcetext, lineno):
         # Ignored. Will be removed in Docutils 2.0.
-        error = self.reporter.severe(
+        error = self.reporter.error(
             'Title level inconsistent:', nodes.literal_block('', sourcetext),
             line=lineno)
         return error
@@ -620,9 +679,9 @@ class Inliner:
         :text: source string
         :lineno: absolute line number, cf. `statemachine.get_source_and_line()`
         """
-        self.reporter = memo.reporter
         self.document = memo.document
         self.language = memo.language
+        self.reporter = self.document.reporter
         self.parent = parent
         pattern_search = self.patterns.initial.search
         dispatch = self.dispatch
@@ -2420,7 +2479,7 @@ class Body(RSTState):
             raise statemachine.TransitionCorrection('text')
         else:
             blocktext = self.state_machine.line
-            msg = self.reporter.severe(
+            msg = self.reporter.error(
                   'Unexpected section title or transition.',
                   nodes.literal_block(blocktext, blocktext),
                   line=self.state_machine.abs_line_number())
@@ -2775,7 +2834,7 @@ class Text(RSTState):
             # if the error is in a table (try with test_tables.py)?
             # print("get_source_and_line", srcline)
             # print("abs_line_number", self.state_machine.abs_line_number())
-            msg = self.reporter.severe(
+            msg = self.reporter.error(
                 'Unexpected section title.',
                 nodes.literal_block(blocktext, blocktext),
                 source=src, line=srcline)
@@ -2977,7 +3036,7 @@ class Line(SpecializedText):
             if len(overline.rstrip()) < 4:
                 self.short_overline(context, blocktext, lineno, 2)
             else:
-                msg = self.reporter.severe(
+                msg = self.reporter.error(
                     'Incomplete section title.',
                     nodes.literal_block(blocktext, blocktext),
                     line=lineno)
@@ -2991,7 +3050,7 @@ class Line(SpecializedText):
             if len(overline.rstrip()) < 4:
                 self.short_overline(context, blocktext, lineno, 2)
             else:
-                msg = self.reporter.severe(
+                msg = self.reporter.error(
                     'Missing matching underline for section title overline.',
                     nodes.literal_block(source, source),
                     line=lineno)
@@ -3002,7 +3061,7 @@ class Line(SpecializedText):
             if len(overline.rstrip()) < 4:
                 self.short_overline(context, blocktext, lineno, 2)
             else:
-                msg = self.reporter.severe(
+                msg = self.reporter.error(
                       'Title overline & underline mismatch.',
                       nodes.literal_block(source, source),
                       line=lineno)
