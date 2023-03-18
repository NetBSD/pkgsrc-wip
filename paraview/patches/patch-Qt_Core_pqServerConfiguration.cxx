$NetBSD$

NetBSD support

--- Qt/Core/pqServerConfiguration.cxx.orig	2023-03-15 15:08:46.823219401 +0000
+++ Qt/Core/pqServerConfiguration.cxx
@@ -229,7 +229,7 @@ vtkPVXMLElement* pqServerConfiguration::
 //-----------------------------------------------------------------------------
 QString pqServerConfiguration::termCommand()
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   // Based on i3 code
   // https://github.com/i3/i3/blob/next/i3-sensible-terminal
   QStringList termNames = { qgetenv("TERMINAL"), "x-terminal-emulator", "urxvt", "rxvt", "termit",
