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
