$NetBSD$

/scratch/nih/webkit-gtk/work/webkitgtk-2.46.3/Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp: In member function 'void WebKit::ProcessLauncher::launchProcess()':
/scratch/nih/webkit-gtk/work/webkitgtk-2.46.3/Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp:190:17: error: 'pidSocketString' was not declared in this scope
  190 |     argv[i++] = pidSocketString.get();
      |                 ^~~~~~~~~~~~~~~

--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2024-11-05 22:55:48.115789920 +0000
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -160,7 +160,11 @@ void ProcessLauncher::launchProcess()
     }
 
     realExecutablePath = FileSystem::fileSystemRepresentation(executablePath);
+#if OS(LINUX)
     unsigned nargs = 5; // size of the argv array for g_spawn_async()
+#else
+    unsigned nargs = 4; // size of the argv array for g_spawn_async()
+#endif
 
 #if ENABLE(DEVELOPER_MODE)
     Vector<CString> prefixArgs;
@@ -187,7 +191,9 @@ void ProcessLauncher::launchProcess()
     argv[i++] = const_cast<char*>(realExecutablePath.data());
     argv[i++] = processIdentifier.get();
     argv[i++] = webkitSocket.get();
+#if OS(LINUX)
     argv[i++] = pidSocketString.get();
+#endif
 #if ENABLE(DEVELOPER_MODE)
     if (configureJSCForTesting)
         argv[i++] = const_cast<char*>("--configure-jsc-for-testing");
