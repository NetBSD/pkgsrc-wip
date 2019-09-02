$NetBSD$

--- gdb/p-exp.y.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/p-exp.y
@@ -1516,7 +1516,7 @@ yylex (void)
   {
     std::string tmp = copy_name (yylval.sval);
     struct symbol *sym;
-    struct field_of_this_result is_a_field_of_this;
+    struct field_of_this_result is_a_field_of_this = { .type = NULL };
     int is_a_field = 0;
     int hextype;
 
