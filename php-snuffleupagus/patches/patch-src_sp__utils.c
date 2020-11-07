$NetBSD$

Work around build error with nested macro:

'macro "memcpy" requires 3 arguments, but only 2 given'

--- src/sp_utils.c.orig	2020-08-12 14:16:28.000000000 +0000
+++ src/sp_utils.c
@@ -422,7 +422,7 @@ int hook_function(const char* original_n
       return FAILURE;
     }
     memcpy(mb_name, "mb_", sizeof("mb_") - 1);
-    memcpy(mb_name + 3, VAR_AND_LEN(original_name));
+    memcpy(mb_name + 3, original_name, strlen(original_name));
     if (zend_hash_str_find(CG(function_table), VAR_AND_LEN(mb_name))) {
       return hook_function(mb_name, hook_table, new_function);
     }
