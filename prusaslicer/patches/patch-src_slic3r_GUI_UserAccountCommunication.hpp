$NetBSD$

Add missing include.

--- src/slic3r/GUI/UserAccountCommunication.hpp.orig	2024-06-19 22:16:43.632775046 +0000
+++ src/slic3r/GUI/UserAccountCommunication.hpp
@@ -5,6 +5,8 @@
 #include "Event.hpp"
 #include "libslic3r/AppConfig.hpp"
 
+#include <wx/timer.h>
+
 #include <queue>
 #include <condition_variable>
 #include <map>
