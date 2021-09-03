$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- toplevel.h.orig	2018-05-01 12:52:19.000000000 +0000
+++ toplevel.h
@@ -31,14 +31,10 @@ along with this program.  If not, see <h
 // Qt
 #include <QObject>
 #include <QMatrix4x4>
+#include <QUuid>
 // xcb
 #include <xcb/damage.h>
 #include <xcb/xfixes.h>
-// XLib
-#include <X11/Xlib.h>
-#include <fixx11h.h>
-// system
-#include <assert.h>
 // c++
 #include <functional>
 
@@ -300,7 +296,7 @@ public:
     QByteArray wmCommand();
     QByteArray wmClientMachine(bool use_localhost) const;
     const ClientMachine *clientMachine() const;
-    Window wmClientLeader() const;
+    xcb_window_t wmClientLeader() const;
     virtual pid_t pid() const;
     static bool resourceMatch(const Toplevel* c1, const Toplevel* c2);
 
@@ -516,7 +512,7 @@ protected Q_SLOTS:
 protected:
     virtual ~Toplevel();
     void setWindowHandles(xcb_window_t client);
-    void detectShape(Window id);
+    void detectShape(xcb_window_t id);
     virtual void propertyNotifyEvent(xcb_property_notify_event_t *e);
     virtual void damageNotifyEvent();
     virtual void clientMessageEvent(xcb_client_message_event_t *e);
@@ -570,7 +566,7 @@ private:
     QByteArray resource_name;
     QByteArray resource_class;
     ClientMachine *m_clientMachine;
-    WId wmClientLeaderWin;
+    xcb_window_t m_wmClientLeader;
     bool m_damageReplyPending;
     QRegion opaque_region;
     xcb_xfixes_fetch_region_cookie_t m_regionCookie;
