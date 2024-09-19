$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- activation.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ activation.cpp
@@ -35,7 +35,6 @@ along with this program.  If not, see <h
 #include "activities.h"
 #endif
 
-#include <fixx11h.h>
 #include <kstartupinfo.h>
 #include <kstringhandler.h>
 #include <KLocalizedString>
@@ -633,7 +632,7 @@ bool Workspace::allowClientActivation(co
     }
 
     // Low or medium FSP, usertime comparism is possible
-    Time user_time = ac->userTime();
+    const xcb_timestamp_t user_time = ac->userTime();
     qCDebug(KWIN_CORE) << "Activation, compared:" << c << ":" << time << ":" << user_time
                  << ":" << (NET::timestampCompare(time, user_time) >= 0);
     return NET::timestampCompare(time, user_time) >= 0;   // time >= user_time
@@ -842,7 +841,7 @@ void Client::startupIdChanged()
         workspace()->sendClientToDesktop(this, desktop, true);
     if (asn_data.xinerama() != -1)
         workspace()->sendClientToScreen(this, asn_data.xinerama());
-    Time timestamp = asn_id.timestamp();
+    const xcb_timestamp_t timestamp = asn_id.timestamp();
     if (timestamp != 0) {
         bool activate = workspace()->allowClientActivation(this, timestamp);
         if (asn_data.desktop() != 0 && !isOnCurrentDesktop())
