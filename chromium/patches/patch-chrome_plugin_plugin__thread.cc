$NetBSD: patch-chrome_plugin_plugin__thread.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/plugin/plugin_thread.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/plugin/plugin_thread.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if defined(USE_X11)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
 #elif defined(OS_MACOSX)
 #include <CoreFoundation/CoreFoundation.h>
@@ -57,7 +57,7 @@ PluginThread::PluginThread()
           switches::kPluginPath);
 
   lazy_tls.Pointer()->Set(this);
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   {
     // XEmbed plugins assume they are hosted in a Gtk application, so we need
     // to initialize Gtk in the plugin process.
