$NetBSD$

--- third_party/cacheinvalidation/src/google/cacheinvalidation/include/types.h.orig	2020-07-15 18:56:49.000000000 +0000
+++ third_party/cacheinvalidation/src/google/cacheinvalidation/include/types.h
@@ -335,6 +335,8 @@ class Status {
     PERMANENT_FAILURE
   };
 
+  Status() : code_(SUCCESS), message_() {}
+
   /* Creates a new Status object given the code and message. */
   Status(Code code, const string& message) : code_(code), message_(message) {}
 
