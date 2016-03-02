$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/rt/dmain2.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/rt/dmain2.d
@@ -36,6 +36,10 @@ version (FreeBSD)
 {
     import core.stdc.fenv;
 }
+version (NetBSD)
+{
+    import core.stdc.fenv;
+}
 
 extern (C) void _d_monitor_staticctor();
 extern (C) void _d_monitor_staticdtor();
@@ -324,6 +328,21 @@ extern (C) int _d_run_main(int argc, cha
             fldcw   fpucw;
         }
     }
+    version (NetBSD) version (D_InlineAsm_X86)
+    {
+        /*
+         * NetBSD/i386 sets the FPU precision mode to 53 bit double.
+         * Make it 64 bit extended.
+         */
+        ushort fpucw;
+        asm
+        {
+            fstsw   fpucw;
+            or      fpucw, 0b11_00_111111; // 11: use 64 bit extended-precision
+                                           // 111111: mask all FP exceptions
+            fldcw   fpucw;
+        }
+    }
     version (CRuntime_Microsoft)
     {
         init_msvc();
@@ -468,8 +487,9 @@ extern (C) int _d_run_main(int argc, cha
     //       thrown during cleanup, however, will abort the cleanup process.
     void runAll()
     {
-        if (rt_init() && runModuleUnitTests())
+        if (rt_init() && runModuleUnitTests()){
             tryExec({ result = mainFunc(args); });
+        }
         else
             result = EXIT_FAILURE;
 
