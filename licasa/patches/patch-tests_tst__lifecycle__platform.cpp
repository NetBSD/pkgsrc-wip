$NetBSD$

Hack around Linux-only interface.

--- tests/tst_lifecycle_platform.cpp.orig	2026-11-08 15:55:46.445360725 +0000
+++ tests/tst_lifecycle_platform.cpp
@@ -19,7 +19,9 @@
 #include <cerrno>
 #include <fcntl.h>
 #include <sys/file.h>
+#if __linux__
 #include <sys/prctl.h>
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 
@@ -683,12 +685,14 @@ int main(int argc, char** argv)
         return 0;
     }
     if (fixture == QStringLiteral("1") || fixture == QStringLiteral("inaccessible-viewer")) {
+#if __linux__
         // Real same-executable peers, kept alive until the parent closes stdin.
         // This branch is confined to the test executable.
         if (fixture == QStringLiteral("inaccessible-viewer") &&
             (::prctl(PR_SET_DUMPABLE, 0) != 0 || ::prctl(PR_SET_NAME, "unrelated") != 0)) {
             return 2;
         }
+#endif
         const char ready[] = "ready\n";
         const auto written = ::write(STDOUT_FILENO, ready, sizeof(ready) - 1);
         if (written != sizeof(ready) - 1) {
