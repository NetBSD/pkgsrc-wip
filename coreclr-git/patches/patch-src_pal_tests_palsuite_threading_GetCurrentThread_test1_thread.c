$NetBSD$

--- src/pal/tests/palsuite/threading/GetCurrentThread/test1/thread.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/threading/GetCurrentThread/test1/thread.c
@@ -30,7 +30,13 @@ int __cdecl main( int argc, char **argv 
     {
         return ( FAIL );
     }
-   
+
+#if !HAVE_SCHED_OTHER_ASSIGNABLE
+    /* Defining thread priority for SCHED_OTHER is implementation defined.
+       Some platforms like NetBSD cannot reassign it as they are dynamic.
+    */
+    printf("paltest_getcurrentthread_test1 has been disabled on this platform\n");
+#else   
     hThread = GetCurrentThread();
     
     nPriority = GetThreadPriority(hThread);
@@ -79,6 +85,7 @@ int __cdecl main( int argc, char **argv 
 		    "function failed.  Failing test.\n");
 	}
     }
+#endif
 
     PAL_Terminate();
     return ( PASS );    
