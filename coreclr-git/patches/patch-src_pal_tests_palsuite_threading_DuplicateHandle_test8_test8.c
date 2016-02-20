$NetBSD$

--- src/pal/tests/palsuite/threading/DuplicateHandle/test8/test8.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/threading/DuplicateHandle/test8/test8.c
@@ -36,6 +36,13 @@ int __cdecl main(int argc, char* argv[])
     {
         return (FAIL);
     }
+
+#if !HAVE_SCHED_OTHER_ASSIGNABLE
+    /* Defining thread priority for SCHED_OTHER is implementation defined.
+       Some platforms like NetBSD cannot reassign it as they are dynamic.
+    */
+    printf("paltest_duplicatehandle_test8 has been disabled on this platform\n");
+#else
     
     /* Create a thread.*/
     hThread = CreateThread(NULL,            /* SD*/
@@ -143,6 +150,9 @@ int __cdecl main(int argc, char* argv[])
     /* Clean-up thread and Terminate the PAL.*/
     CloseHandle(hThread);
     CloseHandle(hDupThread);
+
+#endif
+
     PAL_Terminate();
     return PASS;
 }
