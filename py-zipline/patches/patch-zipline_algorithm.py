$NetBSD$

Use contextlib from the standard library.

--- zipline/algorithm.py.orig	2018-07-16 20:12:55.000000000 +0000
+++ zipline/algorithm.py
@@ -20,7 +20,7 @@ from datetime import tzinfo, time
 import logbook
 import pytz
 import pandas as pd
-from contextlib2 import ExitStack
+from contextlib import ExitStack
 import numpy as np
 
 from itertools import chain, repeat
