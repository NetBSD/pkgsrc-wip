$NetBSD$

--- src/pal/tests/palsuite/threading/GetCurrentThread/test2/test2.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/threading/GetCurrentThread/test2/test2.c
@@ -90,7 +90,12 @@ INT __cdecl main( INT argc, CHAR **argv 
         return( FAIL );
     }
 
-
+#if !HAVE_SCHED_OTHER_ASSIGNABLE
+    /* Defining thread priority for SCHED_OTHER is implementation defined.
+       Some platforms like NetBSD cannot reassign it as they are dynamic.
+    */
+    printf("paltest_duplicatehandle_test8 has been disabled on this platform\n");
+#else
     /* Create multiple threads. */
     hThread = CreateThread(    NULL,         /* no security attributes    */
                                0,            /* use default stack size    */
@@ -132,10 +137,8 @@ INT __cdecl main( INT argc, CHAR **argv 
         Fail( "FAIL:Unexpected thread priority %d returned, expected %d\n",
                 g_priority, THREAD_PRIORITY_TIME_CRITICAL );
     }
-    
-    
+#endif    
 
     PAL_Terminate();
     return PASS;
 }
-
