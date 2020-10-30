$NetBSD$

try fix

--- scripts/meson_post_install.py.orig	2020-09-25 18:46:41.000000000 +0000
+++ scripts/meson_post_install.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python3
+#!/usr/pkg/bin/env python3.7
 
 import os
 import subprocess
