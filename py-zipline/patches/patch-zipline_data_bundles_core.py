$NetBSD$

Use contextlib from the standard library.

--- zipline/data/bundles/core.py.orig	2018-07-16 14:49:07.000000000 +0000
+++ zipline/data/bundles/core.py
@@ -4,7 +4,7 @@ import os
 import shutil
 import warnings
 
-from contextlib2 import ExitStack
+from contextlib import ExitStack
 import click
 import pandas as pd
 from trading_calendars import get_calendar
