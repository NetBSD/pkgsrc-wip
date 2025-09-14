$NetBSD$

--- docutils/parsers/rst/states.py.orig	2025-07-29 14:37:37.894344600 +0000
+++ docutils/parsers/rst/states.py
@@ -107,6 +107,7 @@ __docformat__ = 'reStructuredText'
 import re
 from types import FunctionType, MethodType
 from types import SimpleNamespace as Struct
+import warnings
 
 from docutils import nodes, statemachine, utils
 from docutils import ApplicationError, DataError
@@ -121,6 +122,10 @@ from docutils.utils import split_escaped
 from docutils.utils._roman_numerals import (InvalidRomanNumeralError,
                                             RomanNumeral)
 
+TYPE_CHECKING = False
+if TYPE_CHECKING:
+    from docutils.statemachine import StringList
+
 
 class MarkupError(DataError): pass
 class UnknownInterpretedRoleError(DataError): pass
@@ -136,6 +141,15 @@ class RSTStateMachine(StateMachineWS):
 
     The entry point to reStructuredText parsing is the `run()` method.
     """
+    section_level_offset: int = 0
+    """Correction term for section level determination in nested parsing.
+
+    Updated by `RSTState.nested_parse()` and used in
+    `RSTState.check_subsection()` to compensate differences when
+    nested parsing uses a detached base node with a document-wide
+    section title style hierarchy or the current node with a new,
+    independent title style hierarchy.
+    """
 
     def run(self, input_lines, document, input_offset=0, match_titles=True,
             inliner=None) -> None:
@@ -151,16 +165,19 @@ class RSTStateMachine(StateMachineWS):
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
@@ -168,16 +185,23 @@ class RSTStateMachine(StateMachineWS):
         self.node = self.memo = None    # remove unneeded references
 
 
-class NestedStateMachine(StateMachineWS):
-
+class NestedStateMachine(RSTStateMachine):
     """
     StateMachine run from within other StateMachine runs, to parse nested
     document structures.
     """
 
+    def __init__(self, state_classes, initial_state,
+                 debug=False, parent_state_machine=None) -> None:
+
+        self.parent_state_machine = parent_state_machine
+        """The instance of the parent state machine."""
+
+        super().__init__(state_classes, initial_state, debug)
+
     def run(self, input_lines, input_offset, memo, node, match_titles=True):
         """
-        Parse `input_lines` and populate a `docutils.nodes.document` instance.
+        Parse `input_lines` and populate `node`.
 
         Extend `StateMachineWS.run()`: set up document-wide data.
         """
@@ -185,8 +209,8 @@ class NestedStateMachine(StateMachineWS)
         self.memo = memo
         self.document = memo.document
         self.attach_observer(self.document.note_source)
-        self.reporter = memo.reporter
         self.language = memo.language
+        self.reporter = self.document.reporter
         self.node = node
         results = StateMachineWS.run(self, input_lines, input_offset)
         assert results == [], ('NestedStateMachine.run() results should be '
@@ -205,7 +229,7 @@ class RSTState(StateWS):
     nested_sm = NestedStateMachine
     nested_sm_cache = []
 
-    def __init__(self, state_machine, debug=False) -> None:
+    def __init__(self, state_machine: RSTStateMachine, debug=False) -> None:
         self.nested_sm_kwargs = {'state_classes': state_classes,
                                  'initial_state': 'Body'}
         StateWS.__init__(self, state_machine, debug)
@@ -214,14 +238,21 @@ class RSTState(StateWS):
         StateWS.runtime_init(self)
         memo = self.state_machine.memo
         self.memo = memo
-        self.reporter = memo.reporter
-        self.inliner = memo.inliner
         self.document = memo.document
-        self.parent = self.state_machine.node
+        self.inliner = memo.inliner
+        self.reporter = self.document.reporter
         # enable the reporter to determine source and source-line
         if not hasattr(self.reporter, 'get_source_and_line'):
             self.reporter.get_source_and_line = self.state_machine.get_source_and_line  # noqa:E501
 
+    @property
+    def parent(self) -> nodes.Element | None:
+        return self.state_machine.node
+
+    @parent.setter
+    def parent(self, value: nodes.Element):
+        self.state_machine.node = value
+
     def goto_line(self, abs_line_offset) -> None:
         """
         Jump to input line `abs_line_offset`, ignoring jumps past the end.
@@ -248,12 +279,45 @@ class RSTState(StateWS):
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
+                     node: nodes.Element|None = None,
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
+            Base node. Generated nodes will be appended to this node.
+            Default: the "current node" (`self.state_machine.node`).
+        :match_titles:
+            Allow section titles?
+            Caution: With a custom base node, this may lead to an invalid
+            or mixed up document tree. [#]_
+        :state_machine_class:
+            Default: `NestedStateMachine`.
+        :state_machine_kwargs:
+            Keyword arguments for the state-machine instantiation.
+            Default: `self.nested_sm_kwargs`.
+
+        Create a new state-machine instance if required.
+        Return new offset.
+
+        .. [#] See also ``test_parsers/test_rst/test_nested_parsing.py``
+               and Sphinx's `nested_parse_to_nodes()`__.
+
+        __ https://www.sphinx-doc.org/en/master/extdev/utils.html
+           #sphinx.util.parsing.nested_parse_to_nodes
         """
+        if node is None:
+            node = self.state_machine.node
         use_default = 0
         if state_machine_class is None:
             state_machine_class = self.nested_sm
@@ -261,24 +325,54 @@ class RSTState(StateWS):
         if state_machine_kwargs is None:
             state_machine_kwargs = self.nested_sm_kwargs
             use_default += 1
-        block_length = len(block)
-
-        state_machine = None
+        my_state_machine = None
         if use_default == 2:
             try:
-                state_machine = self.nested_sm_cache.pop()
+                # get cached state machine, prevent others from using it
+                my_state_machine = self.nested_sm_cache.pop()
             except IndexError:
                 pass
-        if not state_machine:
-            state_machine = state_machine_class(debug=self.debug,
-                                                **state_machine_kwargs)
-        state_machine.run(block, input_offset, memo=self.memo,
-                          node=node, match_titles=match_titles)
+        if not my_state_machine:
+            my_state_machine = state_machine_class(
+                                  debug=self.debug,
+                                  parent_state_machine=self.state_machine,
+                                  **state_machine_kwargs)
+        # Check if we may use sections (with a caveat for custom nodes
+        # that may be dummies to collect children):
+        if (node == self.state_machine.node
+                and not isinstance(node, (nodes.document, nodes.section))):
+            match_titles = False  # avoid invalid sections
+        if match_titles:
+            # Compensate mismatch of known title styles and number of
+            # parent sections of the base node if the document wide
+            # title styles are used with a detached base node or
+            # a new list of title styles with the current parent node:
+            l_node = len(node.section_hierarchy())
+            l_start = min(len(self.parent.section_hierarchy()),
+                          len(self.memo.title_styles))
+            my_state_machine.section_level_offset = l_start - l_node
+
+        # run the state machine and populate `node`:
+        block_length = len(block)
+        my_state_machine.run(block, input_offset, self.memo,
+                             node, match_titles)
+
+        if match_titles:
+            if node == self.state_machine.node:
+                # Pass on the new "current node" to parent state machines:
+                sm = self.state_machine
+                try:
+                    while True:
+                        sm.node = my_state_machine.node
+                        sm = sm.parent_state_machine
+                except AttributeError:
+                    pass
+        # clean up
+        new_offset = my_state_machine.abs_line_offset()
         if use_default == 2:
-            self.nested_sm_cache.append(state_machine)
+            self.nested_sm_cache.append(my_state_machine)
         else:
-            state_machine.unlink()
-        new_offset = state_machine.abs_line_offset()
+            my_state_machine.unlink()
         # No `block.parent` implies disconnected -- lines aren't in sync:
         if block.parent and (len(block) - block_length) != 0:
             # Adjustment for block if modified in nested parse:
@@ -289,31 +383,45 @@ class RSTState(StateWS):
                           blank_finish,
                           blank_finish_state=None,
                           extra_settings={},
-                          match_titles=False,
+                          match_titles=False,  # deprecated, will be removed
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
+        if match_titles:
+            warnings.warn('The "match_titles" argument of '
+                          'parsers.rst.states.RSTState.nested_list_parse() '
+                          'will be ignored in Docutils 1.0 '
+                          'and removed in Docutils 2.0.',
+                          PendingDeprecationWarning, stacklevel=2)
         if state_machine_class is None:
             state_machine_class = self.nested_sm
         if state_machine_kwargs is None:
             state_machine_kwargs = self.nested_sm_kwargs.copy()
         state_machine_kwargs['initial_state'] = initial_state
-        state_machine = state_machine_class(debug=self.debug,
-                                            **state_machine_kwargs)
+        my_state_machine = state_machine_class(
+                               debug=self.debug,
+                               parent_state_machine=self.state_machine,
+                               **state_machine_kwargs)
         if blank_finish_state is None:
             blank_finish_state = initial_state
-        state_machine.states[blank_finish_state].blank_finish = blank_finish
+        my_state_machine.states[blank_finish_state].blank_finish = blank_finish
         for key, value in extra_settings.items():
-            setattr(state_machine.states[initial_state], key, value)
-        state_machine.run(block, input_offset, memo=self.memo,
-                          node=node, match_titles=match_titles)
-        blank_finish = state_machine.states[blank_finish_state].blank_finish
-        state_machine.unlink()
-        return state_machine.abs_line_offset(), blank_finish
+            setattr(my_state_machine.states[initial_state], key, value)
+        my_state_machine.run(block, input_offset, memo=self.memo,
+                             node=node, match_titles=match_titles)
+        blank_finish = my_state_machine.states[blank_finish_state].blank_finish
+        my_state_machine.unlink()
+        return my_state_machine.abs_line_offset(), blank_finish
 
     def section(self, title, source, style, lineno, messages) -> None:
         """Check for a valid subsection and create one if it checks out."""
@@ -326,40 +434,60 @@ class RSTState(StateWS):
 
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
+        oldlevel = (len(parent_sections)
+                    + self.state_machine.section_level_offset)
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
-        # Update parent state:
-        self.memo.section_level = level
-        if level <= mylevel:
+        if newlevel <= oldlevel:
             # new section is sibling or higher up in the section hierarchy
-            self.parent = parent_sections[level-1].parent
+            try:
+                new_parent = parent_sections[newlevel-oldlevel-1].parent
+            except IndexError:
+                styles = ' '.join('/'.join(style) for style in title_styles)
+                details = (f'The parent of level {newlevel} sections cannot'
+                           ' be reached. The parser is at section level'
+                           f' {oldlevel} but the current node has only'
+                           f' {len(parent_sections)} parent section(s).'
+                           '\nOne reason may be a high level'
+                           ' section used in a directive that parses its'
+                           ' content into a base node not attached to'
+                           ' the document\n(up to Docutils 0.21,'
+                           ' these sections were silently dropped).')
+                self.parent += self.reporter.error(
+                    f'A level {newlevel} section cannot be used here.',
+                    nodes.literal_block('', source),
+                    nodes.paragraph('', f'Established title styles: {styles}'),
+                    nodes.paragraph('', details),
+                    line=lineno)
+                return False
+            self.parent = new_parent
+            self.memo.section_level = newlevel - 1
+        if newlevel > len(title_styles):
+            title_styles.append(style)
         return True
 
     def title_inconsistent(self, sourcetext, lineno):
         # Ignored. Will be removed in Docutils 2.0.
-        error = self.reporter.severe(
+        error = self.reporter.error(
             'Title level inconsistent:', nodes.literal_block('', sourcetext),
             line=lineno)
         return error
@@ -377,15 +505,8 @@ class RSTState(StateWS):
         section_node += title_messages
         self.document.note_implicit_target(section_node, section_node)
         # Update state:
-        self.state_machine.node = section_node
-        # Also update the ".parent" attribute in all states.
-        # This is a bit violent, but the state classes copy their .parent from
-        # state_machine.node on creation, so we need to update them. We could
-        # also remove RSTState.parent entirely and replace references to it
-        # with statemachine.node, but that might break code downstream of
-        # docutils.
-        for s in self.state_machine.states.values():
-            s.parent = section_node
+        self.parent = section_node
+        self.memo.section_level += 1
 
     def paragraph(self, lines, lineno):
         """
@@ -620,9 +741,9 @@ class Inliner:
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
@@ -1600,7 +1721,7 @@ class Body(RSTState):
                   self.state_machine.input_lines[offset:],
                   input_offset=self.state_machine.abs_line_offset() + 1,
                   node=block, initial_state='LineBlock',
-                  blank_finish=0)
+                  blank_finish=False)
             self.goto_line(new_line_offset)
         if not blank_finish:
             self.parent += self.reporter.warning(
@@ -1695,14 +1816,14 @@ class Body(RSTState):
 
     def isolate_grid_table(self):
         messages = []
-        blank_finish = 1
+        blank_finish = True
         try:
             block = self.state_machine.get_text_block(flush_left=True)
         except statemachine.UnexpectedIndentationError as err:
             block, src, srcline = err.args
             messages.append(self.reporter.error('Unexpected indentation.',
                                                 source=src, line=srcline))
-            blank_finish = 0
+            blank_finish = False
         block.disconnect()
         # for East Asian chars:
         block.pad_double_width(self.double_width_pad_char)
@@ -1710,24 +1831,26 @@ class Body(RSTState):
         for i in range(len(block)):
             block[i] = block[i].strip()
             if block[i][0] not in '+|':  # check left edge
-                blank_finish = 0
+                blank_finish = False
                 self.state_machine.previous_line(len(block) - i)
                 del block[i:]
                 break
         if not self.grid_table_top_pat.match(block[-1]):  # find bottom
-            blank_finish = 0
             # from second-last to third line of table:
             for i in range(len(block) - 2, 1, -1):
                 if self.grid_table_top_pat.match(block[i]):
                     self.state_machine.previous_line(len(block) - i + 1)
                     del block[i+1:]
+                    blank_finish = False
                     break
             else:
-                messages.extend(self.malformed_table(block))
+                detail = 'Bottom border missing or corrupt.'
+                messages.extend(self.malformed_table(block, detail, i))
                 return [], messages, blank_finish
         for i in range(len(block)):     # check right edge
             if len(block[i]) != width or block[i][-1] not in '+|':
-                messages.extend(self.malformed_table(block))
+                detail = 'Right border not aligned or missing.'
+                messages.extend(self.malformed_table(block, detail, i))
                 return [], messages, blank_finish
         return block, messages, blank_finish
 
@@ -1747,8 +1870,8 @@ class Body(RSTState):
                 if len(line.strip()) != toplen:
                     self.state_machine.next_line(i - start)
                     messages = self.malformed_table(
-                        lines[start:i+1], 'Bottom/header table border does '
-                        'not match top border.')
+                        lines[start:i+1], 'Bottom border or header rule does '
+                        'not match top border.', i-start)
                     return [], messages, i == limit or not lines[i+1].strip()
                 found += 1
                 found_at = i
@@ -1757,17 +1880,16 @@ class Body(RSTState):
                     break
             i += 1
         else:                           # reached end of input_lines
+            details = 'No bottom table border found'
             if found:
-                extra = ' or no blank line after table bottom'
+                details += ' or no blank line after table bottom'
                 self.state_machine.next_line(found_at - start)
                 block = lines[start:found_at+1]
             else:
-                extra = ''
                 self.state_machine.next_line(i - start - 1)
                 block = lines[start:]
-            messages = self.malformed_table(
-                block, 'No bottom table border found%s.' % extra)
-            return [], messages, not extra
+            messages = self.malformed_table(block, details + '.')
+            return [], messages, not found
         self.state_machine.next_line(end - start)
         block = lines[start:end+1]
         # for East Asian chars:
@@ -2382,8 +2504,7 @@ class Body(RSTState):
               self.state_machine.input_lines[offset:],
               input_offset=self.state_machine.abs_line_offset() + 1,
               node=self.parent, initial_state='Explicit',
-              blank_finish=blank_finish,
-              match_titles=self.state_machine.match_titles)
+              blank_finish=blank_finish)
         self.goto_line(newline_offset)
         if not blank_finish:
             self.parent += self.unindent_warning('Explicit markup')
@@ -2420,7 +2541,7 @@ class Body(RSTState):
             raise statemachine.TransitionCorrection('text')
         else:
             blocktext = self.state_machine.line
-            msg = self.reporter.severe(
+            msg = self.reporter.error(
                   'Unexpected section title or transition.',
                   nodes.literal_block(blocktext, blocktext),
                   line=self.state_machine.abs_line_number())
@@ -2775,7 +2896,7 @@ class Text(RSTState):
             # if the error is in a table (try with test_tables.py)?
             # print("get_source_and_line", srcline)
             # print("abs_line_number", self.state_machine.abs_line_number())
-            msg = self.reporter.severe(
+            msg = self.reporter.error(
                 'Unexpected section title.',
                 nodes.literal_block(blocktext, blocktext),
                 source=src, line=srcline)
@@ -2977,7 +3098,7 @@ class Line(SpecializedText):
             if len(overline.rstrip()) < 4:
                 self.short_overline(context, blocktext, lineno, 2)
             else:
-                msg = self.reporter.severe(
+                msg = self.reporter.error(
                     'Incomplete section title.',
                     nodes.literal_block(blocktext, blocktext),
                     line=lineno)
@@ -2991,7 +3112,7 @@ class Line(SpecializedText):
             if len(overline.rstrip()) < 4:
                 self.short_overline(context, blocktext, lineno, 2)
             else:
-                msg = self.reporter.severe(
+                msg = self.reporter.error(
                     'Missing matching underline for section title overline.',
                     nodes.literal_block(source, source),
                     line=lineno)
@@ -3002,7 +3123,7 @@ class Line(SpecializedText):
             if len(overline.rstrip()) < 4:
                 self.short_overline(context, blocktext, lineno, 2)
             else:
-                msg = self.reporter.severe(
+                msg = self.reporter.error(
                       'Title overline & underline mismatch.',
                       nodes.literal_block(source, source),
                       line=lineno)
