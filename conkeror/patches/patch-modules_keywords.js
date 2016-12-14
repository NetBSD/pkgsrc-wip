$NetBSD$

From: John Foerch <jjfoerch@earthlink.net>
Date: Thu, 10 Nov 2016 01:07:18 +0000 (-0500)
Subject: keywords.js: restyle to eliminate strict mode warnings
X-Git-Url: http://repo.or.cz/conkeror.git/commitdiff_plain/88566433998f7ebeaf01010c20703ab9636b381b

keywords.js: restyle to eliminate strict mode warnings

There were several warnings like this:

    JavaScript strict warning: chrome://conkeror/content/keywords.js,
    line 20: SyntaxError: in strict mode code, functions may be declared
    only at top level or immediately within another function
---

diff --git a/modules/keywords.js b/modules/keywords.js
dissimilarity index 90%
index bf5fc8a..79f2b23 100644
--- modules/keywords.js
+++ modules/keywords.js
@@ -1,77 +1,77 @@
-/**
- * (C) Copyright 2007-2008 Jeremy Maitin-Shepard
- *
- * Use, modification, and distribution are subject to the terms specified in the
- * COPYING file.
- **/
-
-{
-    let _keyword_argument_list = [];
-    let _get_keyword_argument_setter = function _get_keyword_argument_setter (name) {
-        return function (value) { _keyword_argument_list.push(name); return value; };
-    };
-
-    let _get_keyword_argument_getter = function _get_keyword_argument_getter (name) {
-        return function () { _keyword_argument_list.push(name); return true; };
-    };
-
-    // This function must be called with all string arguments, all of
-    // which must begin with "$".
-    function define_keywords () {
-        for (var i = 0, alen = arguments.length; i < alen; ++i) {
-            var name = arguments[i];
-            this.__defineSetter__(name, _get_keyword_argument_setter(name));
-            this.__defineGetter__(name, _get_keyword_argument_getter(name));
-        }
-    }
-
-    var define_keyword = define_keywords;
-
-    function write_keywords (output, input, first_index) {
-        if (first_index == null)
-            first_index = input.callee.length;
-        let max_index = input.length;
-        let count = max_index - first_index;
-        if (count > 0) {
-            let offset = _keyword_argument_list.length - 1;
-            for (let i = max_index - 1; i >= first_index; --i) {
-                let value = input[i];
-                if (value instanceof keyword_argument_forwarder) {
-                    for (let x in value)
-                        output[x] = value[x];
-                    --count;
-                } else {
-                    let name = _keyword_argument_list[offset--];
-                    output[name] = value;
-                }
-            }
-            _keyword_argument_list.length -= count;
-        }
-    }
-
-    let keyword_argument_forwarder = function keyword_argument_forwarder (args) {
-        if ("_processed_keywords" in args) {
-            for (let x in args) {
-                if (x[0] == "$")
-                    this[x] = args[x];
-            }
-        } else
-            write_keywords(this, args);
-    };
-
-    function keywords (args) {
-        write_keywords(args, arguments);
-        write_keywords(args, args);
-        args._processed_keywords = true;
-    }
-
-    function forward_keywords (args) {
-        return new keyword_argument_forwarder(args);
-    }
-
-    function protect_keywords () {
-        return new keyword_argument_forwarder(arguments);
-    }
-}
-
-provide("keywords");
+/**
+ * (C) Copyright 2007-2008 Jeremy Maitin-Shepard
+ *
+ * Use, modification, and distribution are subject to the terms specified in the
+ * COPYING file.
+ **/
+
+var _keyword_argument_list = [];
+function _get_keyword_argument_setter (name) {
+    return function (value) { _keyword_argument_list.push(name); return value; };
+}
+
+function _get_keyword_argument_getter (name) {
+    return function () { _keyword_argument_list.push(name); return true; };
+}
+
+// This function must be called with all string arguments, all of
+// which must begin with "$".
+function define_keywords () {
+    for (var i = 0, alen = arguments.length; i < alen; ++i) {
+        var name = arguments[i];
+        this.__defineSetter__(name, _get_keyword_argument_setter(name));
+        this.__defineGetter__(name, _get_keyword_argument_getter(name));
+    }
+}
+
+var define_keyword = define_keywords;
+
+function write_keywords (output, input, first_index) {
+    if (first_index == null) {
+        first_index = input.callee.length;
+    }
+    let max_index = input.length;
+    let count = max_index - first_index;
+    if (count > 0) {
+        let offset = _keyword_argument_list.length - 1;
+        for (let i = max_index - 1; i >= first_index; --i) {
+            let value = input[i];
+            if (value instanceof keyword_argument_forwarder) {
+                for (let x in value)
+                    output[x] = value[x];
+                --count;
+            } else {
+                let name = _keyword_argument_list[offset--];
+                output[name] = value;
+            }
+        }
+        _keyword_argument_list.length -= count;
+    }
+}
+
+function keyword_argument_forwarder (args) {
+    if ("_processed_keywords" in args) {
+        for (let x in args) {
+            if (x[0] == "$")
+                this[x] = args[x];
+        }
+    } else {
+        write_keywords(this, args);
+    }
+}
+
+function keywords (args) {
+    write_keywords(args, arguments);
+    write_keywords(args, args);
+    args._processed_keywords = true;
+}
+
+function forward_keywords (args) {
+    return new keyword_argument_forwarder(args);
+}
+
+function protect_keywords () {
+    return new keyword_argument_forwarder(arguments);
+}
+
+provide("keywords");
