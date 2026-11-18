$NetBSD$

--- tests/conftest.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ tests/conftest.py
@@ -159,7 +159,10 @@ def disable_subp_usage(request, fixture_utils):
         real_subp = subp.subp
 
         def side_effect(args, *other_args, **kwargs):
-            cmd = args[0]
+            if isinstance(args, list):
+                cmd = args[0]
+            else:
+                cmd = args
             if cmd not in allow_subp_for:
                 raise UnexpectedSubpError(
                     "Unexpectedly used subp.subp to call {} (allowed:"
