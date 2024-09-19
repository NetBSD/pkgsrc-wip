$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- toplevel.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ toplevel.cpp
@@ -45,11 +45,11 @@ Toplevel::Toplevel()
     , ready_for_painting(true)
     , m_isDamaged(false)
     , m_client()
-    , damage_handle(None)
+    , damage_handle(XCB_NONE)
     , is_shape(false)
     , effect_window(NULL)
     , m_clientMachine(new ClientMachine(this))
-    , wmClientLeaderWin(0)
+    , m_wmClientLeader(XCB_WINDOW_NONE)
     , m_damageReplyPending(false)
     , m_screen(0)
     , m_skipCloseAnimation(false)
@@ -62,7 +62,7 @@ Toplevel::Toplevel()
 
 Toplevel::~Toplevel()
 {
-    assert(damage_handle == None);
+    assert(damage_handle == XCB_NONE);
     delete info;
 }
 
@@ -95,7 +95,7 @@ QRect Toplevel::decorationRect() const
     return rect();
 }
 
-void Toplevel::detectShape(Window id)
+void Toplevel::detectShape(xcb_window_t id)
 {
     const bool wasShape = is_shape;
     is_shape = Xcb::Extensions::self()->hasShape(id);
@@ -113,7 +113,7 @@ void Toplevel::copyToDeleted(Toplevel* c
     info = c->info;
     m_client.reset(c->m_client, false);
     ready_for_painting = c->ready_for_painting;
-    damage_handle = None;
+    damage_handle = XCB_NONE;
     damage_region = c->damage_region;
     repaints_region = c->repaints_region;
     is_shape = c->is_shape;
@@ -124,7 +124,7 @@ void Toplevel::copyToDeleted(Toplevel* c
     resource_class = c->resourceClass();
     m_clientMachine = c->m_clientMachine;
     m_clientMachine->setParent(this);
-    wmClientLeaderWin = c->wmClientLeader();
+    m_wmClientLeader = c->wmClientLeader();
     opaque_region = c->opaqueRegion();
     m_screen = c->m_screen;
     m_skipCloseAnimation = c->m_skipCloseAnimation;
@@ -154,7 +154,7 @@ Xcb::Property Toplevel::fetchWmClientLea
 
 void Toplevel::readWmClientLeader(Xcb::Property &prop)
 {
-    wmClientLeaderWin = prop.value<xcb_window_t>(window());
+    m_wmClientLeader = prop.value<xcb_window_t>(window());
 }
 
 void Toplevel::getWmClientLeader()
@@ -170,8 +170,9 @@ void Toplevel::getWmClientLeader()
 QByteArray Toplevel::sessionId() const
 {
     QByteArray result = Xcb::StringProperty(window(), atoms->sm_client_id);
-    if (result.isEmpty() && wmClientLeaderWin && wmClientLeaderWin != window())
-        result = Xcb::StringProperty(wmClientLeaderWin, atoms->sm_client_id);
+    if (result.isEmpty() && m_wmClientLeader && m_wmClientLeader != window()) {
+        result = Xcb::StringProperty(m_wmClientLeader, atoms->sm_client_id);
+    }
     return result;
 }
 
@@ -182,8 +183,9 @@ QByteArray Toplevel::sessionId() const
 QByteArray Toplevel::wmCommand()
 {
     QByteArray result = Xcb::StringProperty(window(), XCB_ATOM_WM_COMMAND);
-    if (result.isEmpty() && wmClientLeaderWin && wmClientLeaderWin != window())
-        result = Xcb::StringProperty(wmClientLeaderWin, XCB_ATOM_WM_COMMAND);
+    if (result.isEmpty() && m_wmClientLeader && m_wmClientLeader != window()) {
+        result = Xcb::StringProperty(m_wmClientLeader, XCB_ATOM_WM_COMMAND);
+    }
     result.replace(0, ' ');
     return result;
 }
@@ -214,10 +216,11 @@ QByteArray Toplevel::wmClientMachine(boo
   Returns client leader window for this client.
   Returns the client window itself if no leader window is defined.
 */
-Window Toplevel::wmClientLeader() const
+xcb_window_t Toplevel::wmClientLeader() const
 {
-    if (wmClientLeaderWin)
-        return wmClientLeaderWin;
+    if (m_wmClientLeader != XCB_WINDOW_NONE) {
+        return m_wmClientLeader;
+    }
     return window();
 }
 
