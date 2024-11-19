$NetBSD$

/scratch/nih/webkit-gtk/work/webkitgtk-2.46.3/Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp: In member function 'void WebKit::WebProcessPool::setSandboxEnabled(bool)':
/scratch/nih/webkit-gtk/work/webkitgtk-2.46.3/Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp:211:9: error: 'RUNNING_ON_VALGRIND' was not declared in this scope
  211 |     if (RUNNING_ON_VALGRIND)
      |         ^~~~~~~~~~~~~~~~~~~

--- Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp.orig	2024-11-05 22:58:35.924840877 +0000
+++ Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp
@@ -207,7 +207,7 @@ void WebProcessPool::setSandboxEnabled(b
         return;
     }
 
-#if !USE(SYSTEM_MALLOC)
+#if !USE(SYSTEM_MALLOC) && OS(LINUX)
     if (RUNNING_ON_VALGRIND)
         return;
 #endif
