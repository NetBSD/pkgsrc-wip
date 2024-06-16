$NetBSD$

Add empty file so that the test run, and pytest doesn't get confused about
import paths

--- tests/__init__.py.orig	2024-06-15 16:29:17.091983349 +0000
+++ tests/__init__.py
@@ -0,0 +1 @@
+# Empty on purpose
