$NetBSD$

--- docutils/frontend.py.orig	2025-07-29 14:37:38.634775200 +0000
+++ docutils/frontend.py
@@ -808,34 +808,26 @@ class OptionParser(optparse.OptionParser
           ['--input-encoding'],
           {'metavar': '<name[:handler]>', 'default': 'utf-8',
            'validator': validate_encoding_and_error_handler}),
-         ('Specify the error handler for undecodable characters.  '
-          'Choices: "strict" (default), "ignore", and "replace".',
-          ['--input-encoding-error-handler'],
+         (SUPPRESS_HELP, ['--input-encoding-error-handler'],
           {'default': 'strict', 'validator': validate_encoding_error_handler}),
          ('Specify the text encoding and optionally the error handler for '
           'output.  Default: utf-8.',
           ['--output-encoding'],
           {'metavar': '<name[:handler]>', 'default': 'utf-8',
            'validator': validate_encoding_and_error_handler}),
-         ('Specify error handler for unencodable output characters; '
-          '"strict" (default), "ignore", "replace", '
-          '"xmlcharrefreplace", "backslashreplace".',
-          ['--output-encoding-error-handler'],
+         (SUPPRESS_HELP, ['--output-encoding-error-handler'],
           {'default': 'strict', 'validator': validate_encoding_error_handler}),
-         ('Specify text encoding and optionally error handler '
-          'for error output.  Default: %s.' % default_error_encoding,
+         ('Specify text encoding and optionally the error handler'
+          f' for error output.  Default: {default_error_encoding}.',
           ['--error-encoding', '-e'],
           {'metavar': '<name[:handler]>', 'default': default_error_encoding,
            'validator': validate_encoding_and_error_handler}),
-         ('Specify the error handler for unencodable characters in '
-          'error output.  Default: %s.'
-          % default_error_encoding_error_handler,
-          ['--error-encoding-error-handler'],
+         (SUPPRESS_HELP, ['--error-encoding-error-handler'],
           {'default': default_error_encoding_error_handler,
            'validator': validate_encoding_error_handler}),
          ('Specify the language (as BCP 47 language tag).  Default: en.',
           ['--language', '-l'], {'dest': 'language_code', 'default': 'en',
-                                 'metavar': '<name>'}),
+                                 'metavar': '<tag>'}),
          ('Write output file dependencies to <file>.',
           ['--record-dependencies'],
           {'metavar': '<file>', 'validator': validate_dependency_file,
