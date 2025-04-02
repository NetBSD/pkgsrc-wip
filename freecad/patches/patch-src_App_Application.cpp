$NetBSD$

Fall through to using /proc on NetBSD for the executable path.

--- src/App/Application.cpp.orig	2025-03-30 05:33:31.967652861 +0000
+++ src/App/Application.cpp
@@ -3427,7 +3427,7 @@ std::string Application::FindHomePath(co
         // path. In the worst case we simply get q wrong path and FreeCAD is not
         // able to load its modules.
         char resolved[PATH_MAX];
-#if defined(FC_OS_BSD)
+#if defined(FC_OS_BSD) && !defined(__NetBSD__)
         int mib[4];
         mib[0] = CTL_KERN;
         mib[1] = KERN_PROC;
