$NetBSD$

# Resolve conflict

--- tools/external/driver-tool/sratools.cpp.orig	2023-08-13 21:49:06.139091507 +0000
+++ tools/external/driver-tool/sratools.cpp
@@ -578,7 +578,7 @@ static int main(CommandLine const &argv)
 
 } // namespace sratools
 
-#if BSD
+#if BSD && ! MAC
 int main(int argc, char *argv[], char *envp[])
 {
     auto const invocation = CommandLine(argc, argv, envp, nullptr);
