$NetBSD$

--- src/pal/tests/palsuite/threading/GetProcessTimes/test2/test2.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/threading/GetProcessTimes/test2/test2.c
@@ -25,7 +25,7 @@ int __cdecl main( int argc, char **argv 
 
 {
     int i, j, k;
-    int total = 0;
+    int *total;
     
     HANDLE hProcess;    
     FILETIME createTime;
@@ -76,11 +76,16 @@ int __cdecl main( int argc, char **argv 
     {
         for( j=0; j<1000; j++ )
         {
-            total = j * i;
+            /* do kernel work to increase system usage counters */
+            total = malloc(1024 * 1024);
+
+            *total = j * i;
             for( k=0; k<1000; k++ )
             {
-                total += k + i;
+                *total += k + i;
             }
+
+            free(total);
         }
     }
 
