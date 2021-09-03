$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- group.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ group.cpp
@@ -52,14 +52,14 @@ namespace KWin
 // Group
 //********************************************
 
-Group::Group(Window leader_P)
+Group::Group(xcb_window_t leader_P)
     :   leader_client(NULL),
         leader_wid(leader_P),
         leader_info(NULL),
         user_time(-1U),
         refcount(0)
 {
-    if (leader_P != None) {
+    if (leader_P != XCB_WINDOW_NONE) {
         leader_client = workspace()->findClient(Predicate::WindowMatch, leader_P);
         leader_info = new NETWinInfo(connection(), leader_P, rootWindow(),
                                       0, NET::WM2StartupId);
@@ -78,7 +78,7 @@ QIcon Group::icon() const
 {
     if (leader_client != NULL)
         return leader_client->icon();
-    else if (leader_wid != None) {
+    else if (leader_wid != XCB_WINDOW_NONE) {
         QIcon ic;
         NETWinInfo info(connection(), leader_wid, rootWindow(), NET::WMIcon, NET::WM2IconPixmap);
         auto readIcon = [&ic, &info, this](int size, bool scale = true) {
@@ -155,7 +155,7 @@ void Group::lostLeader()
 
 Group* Workspace::findGroup(xcb_window_t leader) const
 {
-    assert(leader != None);
+    assert(leader != XCB_WINDOW_NONE);
     for (GroupList::ConstIterator it = groups.constBegin();
             it != groups.constEnd();
             ++it)
@@ -811,7 +811,7 @@ void Client::checkGroup(Group* set_group
             // try creating group with other windows with the same client leader
             Group* new_group = workspace()->findClientLeaderGroup(this);
             if (new_group == NULL)
-                new_group = new Group(None);
+                new_group = new Group(XCB_WINDOW_NONE);
             if (new_group != in_group) {
                 if (in_group != NULL)
                     in_group->removeMember(this);
@@ -828,7 +828,7 @@ void Client::checkGroup(Group* set_group
                 in_group = NULL;
             }
             if (new_group == NULL)
-                new_group = new Group(None);
+                new_group = new Group(XCB_WINDOW_NONE);
             if (in_group != new_group) {
                 in_group = new_group;
                 in_group->addMember(this);
