$NetBSD$

Use contextlib from the standard library.

--- zipline/testing/fixtures.py.orig	2018-07-16 14:49:07.000000000 +0000
+++ zipline/testing/fixtures.py
@@ -3,7 +3,7 @@ import sqlite3
 from unittest import TestCase
 import warnings
 
-from contextlib2 import ExitStack
+from contextlib import ExitStack
 from logbook import NullHandler, Logger
 import pandas as pd
 from six import with_metaclass, iteritems
