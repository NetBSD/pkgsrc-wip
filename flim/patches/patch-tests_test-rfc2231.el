$NetBSD$

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./tests/test-rfc2231.el	2001-05-31 11:38:29.000000000 +0900
+++ ././tests/test-rfc2231.el	2018-07-29 22:48:22.287997569 +0900
@@ -151,13 +151,13 @@
 (luna-define-method test-rfc2231-encoded-word-1 ((case test-rfc2231))
   (lunit-assert
    (string=
-    (eword-decode-encoded-word "=?US-ASCII?Q?Keith_Moore?=")
+    (eword-decode-string "=?US-ASCII?Q?Keith_Moore?=")
     "Keith Moore")))
 
 (luna-define-method test-rfc2231-encoded-word-2 ((case test-rfc2231))
   (lunit-assert
    (string=
-    (eword-decode-encoded-word "=?US-ASCII*EN?Q?Keith_Moore?=")
+    (eword-decode-string "=?US-ASCII*EN?Q?Keith_Moore?=")
     "Keith Moore")))
 
 (luna-define-method test-rfc2231-encoded-word-3 ((case test-rfc2231))
@@ -165,7 +165,7 @@
    (eq
     (get-text-property
      0 'mime-language
-     (eword-decode-encoded-word "=?US-ASCII*EN?Q?Keith_Moore?="))
+     (eword-decode-string "=?US-ASCII*EN?Q?Keith_Moore?="))
     'en)))
 
 ;;;
