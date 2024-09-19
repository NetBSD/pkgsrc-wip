$NetBSD$

--- unpaper.c.orig	2014-10-26 21:43:51.000000000 +0000
+++ unpaper.c
@@ -367,7 +367,7 @@ int main(int argc, char* argv[]) {
             { NULL,                         no_argument,       NULL, 0    }
         };
 
-        c = getopt_long_only(argc, argv, "hVl:S:x::n::M:s:z:p:m:W:B:w:b:Tt:qv",
+        c = getopt_long(argc, argv, "hVl:S:x::n::M:s:z:p:m:W:B:w:b:Tt:qv",
                              long_options, &option_index);
         if (c == -1)
             break;
