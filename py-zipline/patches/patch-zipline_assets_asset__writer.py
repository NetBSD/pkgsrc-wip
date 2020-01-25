$NetBSD$

- Use contextlib from the standard library.
- Fix syntax errors with Python 3.7 and 3.8.

--- zipline/assets/asset_writer.py.orig	2017-12-11 17:11:41.000000000 +0000
+++ zipline/assets/asset_writer.py
@@ -15,7 +15,7 @@
 from collections import namedtuple
 import re
 
-from contextlib2 import ExitStack
+from contextlib import ExitStack
 import numpy as np
 import pandas as pd
 import sqlalchemy as sa
@@ -253,7 +253,7 @@ def _split_symbol_mappings(df):
                 len(ambigious),
                 '' if len(ambigious) == 1 else 's',
                 '\n'.join(
-                    '%s:\n  intersections: %s\n  %s' % (
+                    ('%s:\n  intersections: %s\n  %s' % (
                         symbol,
                         tuple(map(_format_range, intersections)),
                         # indent the dataframe string
@@ -262,7 +262,7 @@ def _split_symbol_mappings(df):
                     for symbol, (intersections, df) in sorted(
                         ambigious.items(),
                         key=first,
-                    ),
+                    )),
                 ),
             )
         )
