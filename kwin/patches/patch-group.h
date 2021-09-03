$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- group.h.orig	2018-05-01 12:52:19.000000000 +0000
+++ group.h
@@ -23,8 +23,6 @@ along with this program.  If not, see <h
 #define KWIN_GROUP_H
 
 #include "utils.h"
-#include <X11/X.h>
-#include <fixx11h.h>
 #include <netwm.h>
 
 namespace KWin
@@ -36,9 +34,9 @@ class EffectWindowGroupImpl;
 class Group
 {
 public:
-    Group(Window leader);
+    Group(xcb_window_t leader);
     ~Group();
-    Window leader() const;
+    xcb_window_t leader() const;
     const Client* leaderClient() const;
     Client* leaderClient();
     const ClientList& members() const;
@@ -56,14 +54,14 @@ private:
     void startupIdChanged();
     ClientList _members;
     Client* leader_client;
-    Window leader_wid;
+    xcb_window_t leader_wid;
     NETWinInfo* leader_info;
     xcb_timestamp_t user_time;
     int refcount;
     EffectWindowGroupImpl* effect_group;
 };
 
-inline Window Group::leader() const
+inline xcb_window_t Group::leader() const
 {
     return leader_wid;
 }
