$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- client.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ client.cpp
@@ -48,9 +48,7 @@ along with this program.  If not, see <h
 #include <QFile>
 #include <QMouseEvent>
 #include <QProcess>
-// XLib
-#include <X11/Xutil.h>
-#include <fixx11h.h>
+// xcb
 #include <xcb/xcb_icccm.h>
 // system
 #include <unistd.h>
@@ -225,7 +223,7 @@ void Client::releaseWindow(bool on_shutd
     // Grab X during the release to make removing of properties, setting to withdrawn state
     // and repareting to root an atomic operation (http://lists.kde.org/?l=kde-devel&m=116448102901184&w=2)
     grabXServer();
-    exportMappingState(WithdrawnState);
+    exportMappingState(XCB_ICCCM_WM_STATE_WITHDRAWN);
     setModal(false);   // Otherwise its mainwindow wouldn't get focus
     hidden = true; // So that it's not considered visible anymore (can't use hideClient(), it would set flags)
     if (!on_shutdown)
@@ -789,7 +787,7 @@ void Client::setShade(ShadeMode mode)
         m_wrapper.unmap();
         m_client.unmap();
         m_wrapper.selectInput(ClientWinMask | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY);
-        exportMappingState(IconicState);
+        exportMappingState(XCB_ICCCM_WM_STATE_ICONIC);
         plainResize(s);
         shade_geometry_change = false;
         if (was_shade_mode == ShadeHover) {
@@ -828,7 +826,7 @@ void Client::setShade(ShadeMode mode)
         }
         m_wrapper.map();
         m_client.map();
-        exportMappingState(NormalState);
+        exportMappingState(XCB_ICCCM_WM_STATE_NORMAL);
         if (isActive())
             workspace()->requestFocus(this);
     }
@@ -917,12 +915,12 @@ void Client::updateVisibility()
 void Client::exportMappingState(int s)
 {
     assert(m_client != XCB_WINDOW_NONE);
-    assert(!deleting || s == WithdrawnState);
-    if (s == WithdrawnState) {
+    assert(!deleting || s == XCB_ICCCM_WM_STATE_WITHDRAWN);
+    if (s == XCB_ICCCM_WM_STATE_WITHDRAWN) {
         m_client.deleteProperty(atoms->wm_state);
         return;
     }
-    assert(s == NormalState || s == IconicState);
+    assert(s == XCB_ICCCM_WM_STATE_NORMAL || s == XCB_ICCCM_WM_STATE_ICONIC);
 
     int32_t data[2];
     data[0] = s;
@@ -994,9 +992,9 @@ void Client::map()
         m_wrapper.map();
         m_client.map();
         m_decoInputExtent.map();
-        exportMappingState(NormalState);
+        exportMappingState(XCB_ICCCM_WM_STATE_NORMAL);
     } else
-        exportMappingState(IconicState);
+        exportMappingState(XCB_ICCCM_WM_STATE_ICONIC);
     addLayerRepaint(visibleRect());
 }
 
@@ -1017,7 +1015,7 @@ void Client::unmap()
     m_client.unmap();
     m_decoInputExtent.unmap();
     m_wrapper.selectInput(ClientWinMask | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY);
-    exportMappingState(IconicState);
+    exportMappingState(XCB_ICCCM_WM_STATE_ICONIC);
 }
 
 /**
