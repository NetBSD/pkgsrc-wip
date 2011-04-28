$NetBSD: patch-chrome_browser_shell__integration__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/shell_integration_linux.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/shell_integration_linux.cc
@@ -117,11 +117,23 @@ void CreateShortcutOnDesktop(const FileP
   if (!PathService::Get(chrome::DIR_USER_DESKTOP, &desktop_path))
     return;
 
+#if defined(OS_NETBSD)
+  int desktop_fd = open(desktop_path.value().c_str(), O_RDONLY);
+#else
   int desktop_fd = open(desktop_path.value().c_str(), O_RDONLY | O_DIRECTORY);
+#endif
   if (desktop_fd < 0)
     return;
 
+#if defined(OS_BSD)
+  const char* path = shortcut_filename.value().c_str();
+  if (path[0] != '/')
+    path = strcat((char*)desktop_path.value().c_str(), path);
+
+  int fd = open(path,
+#else
   int fd = openat(desktop_fd, shortcut_filename.value().c_str(),
+#endif
                   O_CREAT | O_EXCL | O_WRONLY,
                   S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
   if (fd < 0) {
@@ -140,7 +152,15 @@ void CreateShortcutOnDesktop(const FileP
     // to make sure we're deleting the file in the directory we think we are.
     // Even if an attacker manager to put something other at
     // |shortcut_filename| we'll just undo his action.
+#if defined(OS_BSD)
+    path = shortcut_filename.value().c_str();
+    if (path[0] != '/')
+      path = strcat((char*)desktop_path.value().c_str(), path);
+
+    unlink(path);
+#else
     unlinkat(desktop_fd, shortcut_filename.value().c_str(), 0);
+#endif
   }
 
   if (HANDLE_EINTR(close(desktop_fd)) < 0)
