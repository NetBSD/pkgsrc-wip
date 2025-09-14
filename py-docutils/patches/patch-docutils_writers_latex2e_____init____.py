$NetBSD$

--- docutils/writers/latex2e/__init__.py.orig	2025-07-29 14:37:37.736252500 +0000
+++ docutils/writers/latex2e/__init__.py
@@ -47,11 +47,11 @@ class Writer(writers.Writer):
         None,
         (('Specify LaTeX documentclass.  Default: "article".',
           ['--documentclass'],
-          {'default': 'article', }),
+          {'metavar': '<documentclass>', 'default': 'article'}),
          ('Specify document options.  Multiple options can be given, '
           'separated by commas.  Default: "a4paper".',
           ['--documentoptions'],
-          {'default': 'a4paper', }),
+          {'metavar': '<options>', 'default': 'a4paper'}),
          ('Format for footnote references: one of "superscript" or '
           '"brackets".  Default: "superscript".',
           ['--footnote-references'],
@@ -105,7 +105,7 @@ class Writer(writers.Writer):
          ('Customization by LaTeX code in the preamble. '
           'Default: select PDF standard fonts (Times, Helvetica, Courier).',
           ['--latex-preamble'],
-          {'default': default_preamble}),
+          {'metavar': '<preamble>', 'default': default_preamble}),
          ('Specify the template file. Default: "%s".' % default_template,
           ['--template'],
           {'default': default_template, 'metavar': '<file>'}),
@@ -139,9 +139,11 @@ class Writer(writers.Writer):
            'validator': frontend.validate_boolean}),
          ('Color of any hyperlinks embedded in text. '
           'Default: "blue" (use "false" to disable).',
-          ['--hyperlink-color'], {'default': 'blue'}),
+          ['--hyperlink-color'],
+          {'metavar': '<color>', 'default': 'blue'}),
          ('Additional options to the "hyperref" package.',
-          ['--hyperref-options'], {'default': ''}),
+          ['--hyperref-options'],
+          {'metavar': '<options>', 'default': ''}),
          ('Enable compound enumerators for nested enumerated lists '
           '(e.g. "1.2.a.ii").',
           ['--compound-enumerators'],
@@ -166,8 +168,8 @@ class Writer(writers.Writer):
          ('When possible, use the specified environment for literal-blocks. '
           'Default: "" (fall back to "alltt").',
           ['--literal-block-env'],
-          {'default': ''}),
-         ('Deprecated alias for "--literal-block-env=verbatim".',
+          {'metavar': '<environment>', 'default': ''}),
+         (frontend.SUPPRESS_HELP,  # deprecated legacy option
           ['--use-verbatim-when-possible'],
           {'action': 'store_true',
            'validator': frontend.validate_boolean}),
@@ -181,22 +183,19 @@ class Writer(writers.Writer):
            'action': 'append',
            'validator': frontend.validate_comma_separated_list,
            'choices': table_style_values}),
-         ('LaTeX graphicx package option. '
-          'Possible values are "dvipdfmx", "dvips", "dvisvgm", '
-          '"luatex", "pdftex", and "xetex".'
-          'Default: "".',
+         ('LaTeX graphicx package option. Default: "".',
           ['--graphicx-option'],
-          {'default': ''}),
+          {'metavar': '<option>', 'default': ''}),
          ('LaTeX font encoding. '
           'Possible values are "", "T1" (default), "OT1", "LGR,T1" or '
           'any other combination of options to the `fontenc` package. ',
           ['--font-encoding'],
-          {'default': 'T1'}),
+          {'metavar': '<encoding>', 'default': 'T1'}),
          ('Per default the latex-writer puts the reference title into '
-          'hyperreferences. Specify "ref*" or "pageref*" to get the section '
+          'hyperreferences. Specify "ref" or "pageref" to get the section '
           'number or the page number.',
           ['--reference-label'],
-          {'default': ''}),
+          {'metavar': '<command name>', 'default': ''}),
          ('Specify style and database(s) for bibtex, for example '
           '"--use-bibtex=unsrt,mydb1,mydb2". Provisional!',
           ['--use-bibtex'],
@@ -938,24 +937,25 @@ class Table:
         return ''
 
     def get_opening(self, width=r'\linewidth'):
+        opening = []
+        nr_of_cols = len(self._col_specs)
         align_map = {'left': '[l]',
                      'center': '[c]',
                      'right': '[r]',
                      None: ''}
         align = align_map.get(self.get('align'))
         latex_type = self.get_latex_type()
-        if align and latex_type not in ("longtable", "longtable*"):
-            opening = [r'\noindent\makebox[\linewidth]%s{%%' % (align,),
-                       r'\begin{%s}' % (latex_type,)]
-        else:
-            opening = [r'\begin{%s}%s' % (latex_type, align)]
+        if align and not latex_type.startswith("longtable"):
+            opening.append(r'\noindent\makebox[\linewidth]%s{%%' % align)
+            align = ''
         if not self.colwidths_auto:
             if self.borders == 'standard' and not self.legacy_column_widths:
-                opening.insert(-1, r'\setlength{\DUtablewidth}'
+                opening.append(r'\setlength{\DUtablewidth}'
                                r'{\dimexpr%s-%i\arrayrulewidth\relax}%%'
-                               % (width, len(self._col_specs)+1))
+                               % (width, nr_of_cols+1))
             else:
-                opening.insert(-1, r'\setlength{\DUtablewidth}{%s}%%' % width)
+                opening.append(r'\setlength{\DUtablewidth}{%s}%%' % width)
+        opening.append(r'\begin{%s}%s' % (latex_type, align))
         return '\n'.join(opening)
 
     def get_closing(self):
@@ -966,7 +966,7 @@ class Table:
         #     closing.append(r'\hline')
         closing.append(r'\end{%s}' % self.get_latex_type())
         if (self.get('align')
-            and self.get_latex_type() not in ("longtable", "longtable*")):
+            and not self.get_latex_type().startswith("longtable")):
             closing.append('}')
         return '\n'.join(closing)
 
@@ -1359,7 +1359,7 @@ class LaTeXTranslator(writers.DoctreeTra
             else:
                 # require a minimal version:
                 self.fallbacks['_docutils.sty'] = (
-                    r'\usepackage{docutils}[2024-09-24]')
+                    r'\usepackage{docutils}[2025-08-06]')
 
         self.stylesheet = [self.stylesheet_call(path)
                            for path in stylesheet_list]
@@ -1381,7 +1381,8 @@ class LaTeXTranslator(writers.DoctreeTra
     # -----------------
 
     def stylesheet_call(self, path):
-        """Return code to reference or embed stylesheet file `path`"""
+        """Return code to reference or embed stylesheet file `path`."""
+
         path = Path(path)
         # is it a package (no extension or *.sty) or "normal" tex code:
         is_package = path.suffix in ('.sty', '')
@@ -1560,19 +1561,25 @@ class LaTeXTranslator(writers.DoctreeTra
                                    id for id in node['ids']))
 
     def ids_to_labels(self, node, set_anchor=True, protect=False,
-                      newline=False) -> list[str]:
+                      newline=False, pre_nl=False) -> list[str]:
         """Return label definitions for all ids of `node`.
 
         If `set_anchor` is True, an anchor is set with \\phantomsection.
         If `protect` is True, the \\label cmd is made robust.
         If `newline` is True, a newline is added if there are labels.
+        If `pre_nl` is True, a newline is prepended if there are labels.
+
+        Provisional.
         """
         prefix = '\\protect' if protect else ''
-        labels = [prefix + '\\label{%s}' % id for id in node['ids']]
-        if set_anchor and labels:
-            labels.insert(0, '\\phantomsection')
-        if newline and labels:
-            labels.append('\n')
+        labels = [f'{prefix}\\label{{{id}}}' for id in node['ids']]
+        if labels:
+            if set_anchor:
+                labels.insert(0, '\\phantomsection')
+            if newline:
+                labels.append('\n')
+            if pre_nl:
+                labels.insert(0, '\n')
         return labels
 
     def set_align_from_classes(self, node) -> None:
@@ -1707,6 +1714,8 @@ class LaTeXTranslator(writers.DoctreeTra
         self.provide_fallback('admonition')
         if 'error' in node['classes']:
             self.provide_fallback('error')
+        if not isinstance(node, nodes.system_message):
+            self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         self.out.append('\\begin{DUadmonition}')
 
@@ -1739,6 +1748,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.depart_docinfo_item(node)
 
     def visit_block_quote(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         self.out.append('\\begin{quote}')
 
@@ -1747,6 +1757,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.duclass_close(node)
 
     def visit_bullet_list(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         self.out.append('\\begin{itemize}')
 
@@ -1771,7 +1782,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.out.append('}')
 
     def visit_caption(self, node) -> None:
-        self.out.append('\n\\caption{')
+        self.out.append('\\caption{')
         self.visit_inline(node)
 
     def depart_caption(self, node) -> None:
@@ -1869,6 +1880,7 @@ class LaTeXTranslator(writers.DoctreeTra
     def visit_compound(self, node) -> None:
         if isinstance(node.parent, nodes.compound):
             self.out.append('\n')
+        self.out += self.ids_to_labels(node, pre_nl=True)
         node['classes'].insert(0, 'compound')
         self.duclass_open(node)
 
@@ -1882,6 +1894,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.depart_docinfo_item(node)
 
     def visit_container(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
 
     def depart_container(self, node) -> None:
@@ -1913,6 +1926,7 @@ class LaTeXTranslator(writers.DoctreeTra
         pass
 
     def visit_definition_list(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         self.out.append('\\begin{description}\n')
 
@@ -1921,7 +1935,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.duclass_close(node)
 
     def visit_definition_list_item(self, node) -> None:
-        pass
+        self.out += self.ids_to_labels(node, newline=True)
 
     def depart_definition_list_item(self, node) -> None:
         if node.next_node(descend=False, siblings=True) is not None:
@@ -2232,6 +2246,7 @@ class LaTeXTranslator(writers.DoctreeTra
         label = r'%s\%s{%s}%s' % (prefix, enumtype, counter_name, suffix)
         self._enumeration_counters.append(label)
 
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         if enum_level <= 4:
             self.out.append('\\begin{enumerate}')
@@ -2256,8 +2271,8 @@ class LaTeXTranslator(writers.DoctreeTra
         self._enumeration_counters.pop()
 
     def visit_field(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         # output is done in field_body, field_name
-        pass
 
     def depart_field(self, node) -> None:
         pass
@@ -2271,6 +2286,7 @@ class LaTeXTranslator(writers.DoctreeTra
             self.out.append(r'\\'+'\n')
 
     def visit_field_list(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         if self.out is not self.docinfo:
             self.provide_fallback('fieldlist')
@@ -2297,6 +2313,7 @@ class LaTeXTranslator(writers.DoctreeTra
 
     def visit_figure(self, node) -> None:
         self.requirements['float'] = PreambleCmds.float
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         # The 'align' attribute sets the "outer alignment",
         # for "inner alignment" use LaTeX default alignment (similar to HTML)
@@ -2305,10 +2322,9 @@ class LaTeXTranslator(writers.DoctreeTra
             # The LaTeX "figure" environment always uses the full linewidth,
             # so "outer alignment" is ignored. Just write a comment.
             # TODO: use the wrapfigure environment?
-            self.out.append('\\begin{figure} %% align = "%s"\n' % alignment)
+            self.out.append('\\begin{figure} %% align = "%s"' % alignment)
         else:
-            self.out.append('\\begin{figure}\n')
-        self.out += self.ids_to_labels(node, newline=True)
+            self.out.append('\\begin{figure}')
 
     def depart_figure(self, node) -> None:
         self.out.append('\\end{figure}\n')
@@ -2335,9 +2351,6 @@ class LaTeXTranslator(writers.DoctreeTra
                 num = '[%s]' % num
             self.out.append('%%\n\\DUfootnotetext{%s}{%s}{%s}{' %
                             (node['ids'][0], backref, self.encode(num)))
-            if node['ids'] == [nodes.make_id(n) for n in node['names']]:
-                # autonumber-label: create anchor
-                self.out += self.ids_to_labels(node)
             # prevent spurious whitespace if footnote starts with paragraph:
             if len(node) > 1 and isinstance(node[1], nodes.paragraph):
                 self.out.append('%')
@@ -2441,6 +2454,9 @@ class LaTeXTranslator(writers.DoctreeTra
         return f'{value}\\DU{unit}dimen'
 
     def visit_image(self, node) -> None:
+        # <image> can be inline element, body element, or nested in a <figure>
+        # in all three cases the <image> may also be nested in a <reference>
+        # TODO: "classes" attribute currently ignored!
         self.requirements['graphicx'] = self.graphicx_package
         attrs = node.attributes
         # convert image URI to filesystem path, do not adjust relative path:
@@ -2485,13 +2501,14 @@ class LaTeXTranslator(writers.DoctreeTra
         if 'width' in attrs:
             include_graphics_options.append(
                 f"width={self.to_latex_length(attrs['width'], node)}")
+        pre.append(''.join(self.ids_to_labels(node, newline=True)))
         if not (self.is_inline(node)
-                or isinstance(node.parent, (nodes.figure, nodes.compound))):
+                or isinstance(node.parent, nodes.compound)):
             pre.append('\n')
-        if not (self.is_inline(node)
-                or isinstance(node.parent, nodes.figure)):
+        if not self.is_inline(node):
             post.append('\n')
         pre.reverse()
+        # now insert image code
         self.out.extend(pre)
         if imagepath.suffix == '.svg' and 'svg' in self.settings.stylesheet:
             cmd = 'includesvg'
@@ -2504,7 +2521,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.out.extend(post)
 
     def depart_image(self, node) -> None:
-        self.out += self.ids_to_labels(node, newline=True)
+        pass
 
     def visit_inline(self, node) -> None:
         # This function is also called by the visiting functions for
@@ -2512,8 +2529,9 @@ class LaTeXTranslator(writers.DoctreeTra
 
         # Handle "ids" attribute:
         # do we need a \phantomsection?
-        set_anchor = not (isinstance(node.parent, (nodes.caption, nodes.title))
-                          or isinstance(node, nodes.caption))
+        anchor_nodes = (nodes.caption, nodes.subtitle, nodes.title)
+        set_anchor = not (isinstance(node.parent, anchor_nodes)
+                          or isinstance(node, anchor_nodes))
         add_newline = isinstance(node, nodes.paragraph)
         self.out += self.ids_to_labels(node, set_anchor, newline=add_newline)
         # Handle "classes" attribute:
@@ -2552,6 +2570,7 @@ class LaTeXTranslator(writers.DoctreeTra
                             '\\begin{DUlineblock}{\\DUlineblockindent}\n')
             # In rST, nested line-blocks cannot be given class arguments
         else:
+            self.out += self.ids_to_labels(node, pre_nl=True)
             self.duclass_open(node)
             self.out.append('\\begin{DUlineblock}{0em}\n')
             self.insert_align_declaration(node)
@@ -2561,6 +2580,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.duclass_close(node)
 
     def visit_list_item(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.out.append('\n\\item ')
 
     def depart_list_item(self, node) -> None:
@@ -2626,8 +2646,8 @@ class LaTeXTranslator(writers.DoctreeTra
         _use_listings = (literal_env == 'lstlisting') and _use_env
 
         # Labels and classes:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
-        self.out += self.ids_to_labels(node, newline=True)
         # Highlight code?
         if (not _plaintext
             and 'code' in node['classes']
@@ -2728,16 +2748,20 @@ class LaTeXTranslator(writers.DoctreeTra
 
     def visit_math_block(self, node) -> None:
         self.requirements['amsmath'] = r'\usepackage{amsmath}'
+        math_env = pick_math_environment(node.astext())
+        self.out.append('%\n')
+        if node['ids'] and math_env.endswith('*'):  # non-numbered equation
+            self.out.append('\\phantomsection\n')
         for cls in node['classes']:
             self.provide_fallback('inline')
-            self.out.append(r'\DUrole{%s}{' % cls)
-        math_env = pick_math_environment(node.astext())
-        self.out += [f'%\n\\begin{{{math_env}}}\n',
+            self.out.append(f'\\DUrole{{{cls}}}{{%\n')
+        self.out += [f'\\begin{{{math_env}}}\n',
                      node.astext().translate(unichar2tex.uni2tex_table),
                      '\n',
                      *self.ids_to_labels(node, set_anchor=False, newline=True),
                      f'\\end{{{math_env}}}']
-        self.out.append('}' * len(node['classes']))
+        if node['classes']:
+            self.out.append('\n' + '}' * len(node['classes']))
         raise nodes.SkipNode  # content already processed
 
     def depart_math_block(self, node) -> None:
@@ -2771,6 +2795,7 @@ class LaTeXTranslator(writers.DoctreeTra
     def visit_option_list(self, node) -> None:
         self.provide_fallback('providelength', '_providelength')
         self.provide_fallback('optionlist')
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         self.out.append('\\begin{DUoptionlist}\n')
 
@@ -2779,7 +2804,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.duclass_close(node)
 
     def visit_option_list_item(self, node) -> None:
-        pass
+        self.out += self.ids_to_labels(node, newline=True)
 
     def depart_option_list_item(self, node) -> None:
         pass
@@ -2871,7 +2896,7 @@ class LaTeXTranslator(writers.DoctreeTra
                          ord('%'): '\\%',
                          ord('\\'): '\\\\',
                          }
-        if not (self.is_inline(node) or isinstance(node.parent, nodes.figure)):
+        if not self.is_inline(node):
             self.out.append('\n')
         # external reference (URL)
         if 'refuri' in node:
@@ -2901,7 +2926,7 @@ class LaTeXTranslator(writers.DoctreeTra
 
     def depart_reference(self, node) -> None:
         self.out.append('}')
-        if not (self.is_inline(node) or isinstance(node.parent, nodes.figure)):
+        if not self.is_inline(node):
             self.out.append('\n')
 
     def visit_revision(self, node) -> None:
@@ -2914,10 +2939,13 @@ class LaTeXTranslator(writers.DoctreeTra
         self.provide_fallback('rubric')
         # class wrapper would interfere with ``\section*"`` type commands
         # (spacing/indent of first paragraph)
-        self.out.append('\n\\DUrubric{')
+        self.out += self.ids_to_labels(node, pre_nl=True)
+        self.duclass_open(node)
+        self.out.append('\\DUrubric{')
 
     def depart_rubric(self, node) -> None:
         self.out.append('}\n')
+        self.duclass_close(node)
 
     def visit_section(self, node) -> None:
         # Update counter-prefix for compound enumerators
@@ -2959,6 +2987,7 @@ class LaTeXTranslator(writers.DoctreeTra
         self.section_level -= 1
 
     def visit_sidebar(self, node) -> None:
+        self.out += self.ids_to_labels(node, pre_nl=True)
         self.duclass_open(node)
         self.requirements['color'] = PreambleCmds.color
         self.provide_fallback('sidebar')
@@ -2975,12 +3004,15 @@ class LaTeXTranslator(writers.DoctreeTra
 
     def visit_attribution(self, node) -> None:
         prefix, suffix = self.attribution_formats[self.settings.attribution]
-        self.out.append('\\nopagebreak\n\n\\raggedleft ')
-        self.out.append(prefix)
+        self.out.append('\\nopagebreak\n')
+        self.out += self.ids_to_labels(node, pre_nl=True)
+        self.duclass_open(node)
+        self.out.append(f'\\raggedleft {prefix}')
         self.context.append(suffix)
 
     def depart_attribution(self, node) -> None:
         self.out.append(self.context.pop() + '\n')
+        self.duclass_close(node)
 
     def visit_status(self, node) -> None:
         self.visit_docinfo_item(node)
@@ -3056,7 +3088,6 @@ class LaTeXTranslator(writers.DoctreeTra
         self.depart_admonition(node)
 
     def visit_table(self, node) -> None:
-        self.duclass_open(node)
         self.requirements['table'] = PreambleCmds.table
         if not self.settings.legacy_column_widths:
             self.requirements['table1'] = PreambleCmds.table_columnwidth
@@ -3088,9 +3119,9 @@ class LaTeXTranslator(writers.DoctreeTra
         # if it has no caption/title.
         # See visit_thead() for tables with caption.
         if not self.active_table.caption:
-            self.out.extend(self.ids_to_labels(
-                node, set_anchor=len(self.table_stack) != 1,
-                newline=True))
+            set_anchor = (len(self.table_stack) != 1)
+            self.out += self.ids_to_labels(node, set_anchor, pre_nl=True)
+        self.duclass_open(node)
         # TODO: Don't use a longtable or add \noindent before
         #       the next paragraph, when in a "compound paragraph".
         #       Start a new line or a new paragraph?
@@ -3269,7 +3300,7 @@ class LaTeXTranslator(writers.DoctreeTra
 
         # labels and PDF bookmark (sidebar entry)
         self.out.append('\n')  # start new paragraph
-        if node['names']:  # don't add labels just for auto-ids
+        if len(node['names']) > 1:  # don't add labels just for the auto-id
             self.out += self.ids_to_labels(node, newline=True)
         if (isinstance(node.next_node(), nodes.title)
             and 'local' not in node['classes']
