$NetBSD: patch-lib_bup_helpers.py,v 1.1 2013/11/24 02:35:19 thomasklausner Exp $

Add --exclude-rx-from and fix a bug in --exclude-rx error handling.

--- lib/bup/helpers.py.orig	2013-11-15 09:46:48.000000000 +0000
+++ lib/bup/helpers.py
@@ -735,19 +735,34 @@ def parse_excludes(options, fatal):
                 raise fatal("couldn't read %s" % parameter)
             for exclude_path in f.readlines():
                 excluded_paths.append(realpath(exclude_path.strip()))
+            f.close()
     return excluded_paths
 
 
 def parse_rx_excludes(options, fatal):
     """Traverse the options and extract all rx excludes, or call
     Option.fatal()."""
-    rxs = [v for f, v in options if f == '--exclude-rx']
-    for i in range(len(rxs)):
-        try:
-            rxs[i] = re.compile(rxs[i])
-        except re.error, ex:
-            o.fatal('invalid --exclude-rx pattern (%s):' % (ex, rxs[i]))
-    return rxs
+    excluded_patterns = []
+
+    for flag in options:
+        (option, parameter) = flag
+        if option == '--exclude-rx':
+            try:
+                excluded_patterns.append(re.compile(parameter))
+            except re.error, ex:
+                fatal('invalid --exclude-rx pattern (%s): %s' % (parameter, ex))
+        elif option == '--exclude-rx-from':
+            try:
+                f = open(realpath(parameter))
+            except IOError, e:
+                raise fatal("couldn't read %s" % parameter)
+            for pattern in f.readlines():
+                try:
+                    excluded_patterns.append(re.compile(pattern.rstrip('\n')))
+                except re.error, ex:
+                    fatal('invalid --exclude-rx pattern (%s): %s' % (pattern.rstrip('\n'), ex))
+            f.close()
+    return excluded_patterns
 
 
 def should_rx_exclude_path(path, exclude_rxs):
