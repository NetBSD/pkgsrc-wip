$NetBSD$

src/common/jstream.h:1564:39: error: 'nullptr_t' was not declared in this scope; did you mean 'std::nullptr_t'?

--- src/common/jstream.h.orig	2025-07-21 19:46:10.990061174 +0000
+++ src/common/jstream.h
@@ -1560,7 +1560,7 @@ struct Object {
 
 static inline bool is_null(Variant const &v)
 {
-	return std::holds_alternative<nullptr_t>(v);
+	return std::holds_alternative<std::nullptr_t>(v);
 }
 static inline bool is_boolean(Variant const &v)
 {
