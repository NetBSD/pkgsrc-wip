$NetBSD$

Backport <https://github.com/insanum/gcalcli/pull/796> to fix `gcalcli init`.

It will be no longer needed in gcalcli-4.5.1.

--- gcalcli/cli.py.orig	2024-09-28 19:29:00.000000000 +0000
+++ gcalcli/cli.py
@@ -21,17 +21,25 @@
 # Everything you need to know (Google API Calendar v3): http://goo.gl/HfTGQ #
 #                                                                           #
 # ######################################################################### #
-from argparse import ArgumentTypeError
+
+
+# Import trusted certificate store to enable SSL, e.g., behind firewalls.
+# Must be called as early as possible to avoid bugs.
+# fmt: off
+import truststore; truststore.inject_into_ssl()  # noqa: I001,E702
+# fmt: on
+# ruff: noqa: E402
+
+
 import json
 import os
 import pathlib
 import re
 import signal
 import sys
+from argparse import ArgumentTypeError
 from collections import namedtuple
 
-import truststore
-
 from . import config, env, utils
 from .argparsers import get_argument_parser, handle_unparsed
 from .exceptions import GcalcliError
@@ -39,12 +47,12 @@ from .gcal import GoogleCalendarInterfac
 from .printer import Printer, valid_color_name
 from .validators import (
     get_date_input_description,
-    get_input,
     PARSABLE_DATE,
     PARSABLE_DURATION,
     REMINDER,
     STR_ALLOW_EMPTY,
     STR_NOT_EMPTY,
+    get_input,
 )
 
 CalName = namedtuple('CalName', ['name', 'color'])
@@ -146,9 +154,6 @@ def run_add_prompt(parsed_args, printer)
 
 
 def main():
-    # import trusted certificate store to enable SSL, e.g., behind firewalls
-    truststore.inject_into_ssl()
-
     parser = get_argument_parser()
     argv = sys.argv[1:]
 
