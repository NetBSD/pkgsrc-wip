$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- netinfo.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ netinfo.cpp
@@ -160,7 +160,7 @@ void RootInfo::changeActiveWindow(xcb_wi
 {
     Workspace *workspace = Workspace::self();
     if (Client* c = workspace->findClient(Predicate::WindowMatch, w)) {
-        if (timestamp == CurrentTime)
+        if (timestamp == XCB_CURRENT_TIME)
             timestamp = c->userTime();
         if (src != NET::FromApplication && src != FromTool)
             src = NET::FromTool;
@@ -173,7 +173,7 @@ void RootInfo::changeActiveWindow(xcb_wi
             if (workspace->allowClientActivation(c, timestamp, false, true))
                 workspace->activateClient(c);
             // if activation of the requestor's window would be allowed, allow activation too
-            else if (active_window != None
+            else if (active_window != XCB_WINDOW_NONE
                     && (c2 = workspace->findClient(Predicate::WindowMatch, active_window)) != NULL
                     && workspace->allowClientActivation(c2,
                             timestampCompare(timestamp, c2->userTime() > 0 ? timestamp : c2->userTime()), false, true)) {
@@ -187,7 +187,7 @@ void RootInfo::changeActiveWindow(xcb_wi
 void RootInfo::restackWindow(xcb_window_t w, RequestSource src, xcb_window_t above, int detail, xcb_timestamp_t timestamp)
 {
     if (Client* c = Workspace::self()->findClient(Predicate::WindowMatch, w)) {
-        if (timestamp == CurrentTime)
+        if (timestamp == XCB_WINDOW_NONE)
             timestamp = c->userTime();
         if (src != NET::FromApplication && src != FromTool)
             src = NET::FromTool;
