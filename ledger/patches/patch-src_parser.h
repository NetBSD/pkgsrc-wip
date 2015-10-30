$NetBSD$

Patch pulled from upstream (Commit: bcaca24de4264f89a94069701361988007e22e58) to allow compilation with recent Boost versions
--- src/parser.h.orig	2014-10-05 23:02:43.000000000 +0000
+++ src/parser.h
@@ -118,7 +118,7 @@ public:
 
   ptr_op_t parse(std::istream&           in,
                  const parse_flags_t&    flags           = PARSE_DEFAULT,
-                 const optional<string>& original_string = NULL);
+                 const optional<string>& original_string = boost::none);
 };
 
 } // namespace ledger
