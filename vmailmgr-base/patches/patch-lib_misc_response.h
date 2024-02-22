$NetBSD$

Avoid operator precedence warning.

--- lib/misc/response.h.orig	2024-02-22 18:26:09.457292318 +0000
+++ lib/misc/response.h
@@ -19,7 +19,7 @@ struct response
   mystring message() const;
   mystring codestr() const;
 
-  static const unsigned long maxsize = 1<<16-1;
+  static const unsigned long maxsize = (1<<16)-1;
 };
 
 #define RETURN(CODE,STR) return response(response::CODE, STR)
