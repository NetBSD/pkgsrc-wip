$NetBSD$

NetBSD does not provide getopt_long_only.

--- unpaper.c.orig	2026-10-29 16:55:42.846529708 +0000
+++ unpaper.c
@@ -357,7 +357,7 @@ int main(int argc, char *argv[]) {
         {"interpolate", required_argument, NULL, 0xcd},
         {NULL, no_argument, NULL, 0}};
 
-    c = getopt_long_only(argc, argv, "hVl:S:x::n::M:s:z:p:m:W:B:w:b:Tt:qv",
+    c = getopt_long(argc, argv, "hVl:S:x::n::M:s:z:p:m:W:B:w:b:Tt:qv",
                          long_options, &option_index);
     if (c == -1)
       break;
