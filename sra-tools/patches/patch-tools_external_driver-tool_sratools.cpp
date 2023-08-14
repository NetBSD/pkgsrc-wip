$NetBSD$

# pthread_main_np() for NetBSD

--- tools/external/driver-tool/sratools.cpp.orig	2023-08-12 23:35:22.000000000 +0000
+++ tools/external/driver-tool/sratools.cpp
@@ -578,9 +578,18 @@ static int main(CommandLine const &argv)
 
 } // namespace sratools
 
-#if BSD
+#ifdef __NetBSD__
+// Defined in sysmgr.c
+extern pthread_t	_thr_main;
+#endif
+
+#if BSD && ! MAC
 int main(int argc, char *argv[], char *envp[])
 {
+#ifdef __NetBSD__
+    _thr_main = pthread_self();
+#endif
+    
     auto const invocation = CommandLine(argc, argv, envp, nullptr);
     return sratools::main(invocation);
 }
