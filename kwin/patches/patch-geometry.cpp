$NetBSD$

Use XCB wherever possible
commit a035401b55c55773bfaf5f279929c32977053562

--- geometry.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ geometry.cpp
@@ -1621,47 +1621,47 @@ const QPoint Client::calculateGravitatio
 
 // dx, dy specify how the client window moves to make space for the frame
     switch(gravity) {
-    case NorthWestGravity: // move down right
+    case XCB_GRAVITY_NORTH_WEST: // move down right
     default:
         dx = borderLeft();
         dy = borderTop();
         break;
-    case NorthGravity: // move right
+    case XCB_GRAVITY_NORTH: // move right
         dx = 0;
         dy = borderTop();
         break;
-    case NorthEastGravity: // move down left
+    case XCB_GRAVITY_NORTH_EAST: // move down left
         dx = -borderRight();
         dy = borderTop();
         break;
-    case WestGravity: // move right
+    case XCB_GRAVITY_WEST: // move right
         dx = borderLeft();
         dy = 0;
         break;
-    case CenterGravity:
+    case XCB_GRAVITY_CENTER:
         break; // will be handled specially
-    case StaticGravity: // don't move
+    case XCB_GRAVITY_STATIC: // don't move
         dx = 0;
         dy = 0;
         break;
-    case EastGravity: // move left
+    case XCB_GRAVITY_EAST: // move left
         dx = -borderRight();
         dy = 0;
         break;
-    case SouthWestGravity: // move up right
+    case XCB_GRAVITY_SOUTH_WEST: // move up right
         dx = borderLeft() ;
         dy = -borderBottom();
         break;
-    case SouthGravity: // move up
+    case XCB_GRAVITY_SOUTH: // move up
         dx = 0;
         dy = -borderBottom();
         break;
-    case SouthEastGravity: // move up left
+    case XCB_GRAVITY_SOUTH_EAST: // move up left
         dx = -borderRight();
         dy = -borderBottom();
         break;
     }
-    if (gravity != CenterGravity) {
+    if (gravity != XCB_GRAVITY_CENTER) {
         // translate from client movement to frame movement
         dx -= borderLeft();
         dy -= borderTop();
@@ -1678,9 +1678,13 @@ const QPoint Client::calculateGravitatio
 
 void Client::configureRequest(int value_mask, int rx, int ry, int rw, int rh, int gravity, bool from_tool)
 {
+    const int configurePositionMask = XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y;
+    const int configureSizeMask = XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT;
+    const int configureGeometryMask = configurePositionMask | configureSizeMask;
+
     // "maximized" is a user setting -> we do not allow the client to resize itself
     // away from this & against the users explicit wish
-    qCDebug(KWIN_CORE) << this << bool(value_mask & (CWX|CWWidth|CWY|CWHeight)) <<
+    qCDebug(KWIN_CORE) << this << bool(value_mask & configureGeometryMask) <<
                             bool(maximizeMode() & MaximizeVertical) <<
                             bool(maximizeMode() & MaximizeHorizontal);
 
@@ -1702,10 +1706,10 @@ void Client::configureRequest(int value_
         ignore = rules()->checkIgnoreGeometry(false);
         if (!ignore) { // the user is not interested, so we fix up dimensions
             if (maximizeMode() == MaximizeVertical)
-                value_mask &= ~(CWY|CWHeight);
+                value_mask &= ~(XCB_CONFIG_WINDOW_Y | XCB_CONFIG_WINDOW_HEIGHT);
             if (maximizeMode() == MaximizeHorizontal)
-                value_mask &= ~(CWX|CWWidth);
-            if (!(value_mask & (CWX|CWWidth|CWY|CWHeight))) {
+                value_mask &= ~(XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_WIDTH);
+            if (!(value_mask & configureGeometryMask)) {
                 ignore = true; // the modification turned the request void
             }
         }
@@ -1716,15 +1720,15 @@ void Client::configureRequest(int value_
         return; // nothing to (left) to do for use - bugs #158974, #252314, #321491
     }
 
-    qCDebug(KWIN_CORE) << "PERMITTED" << this << bool(value_mask & (CWX|CWWidth|CWY|CWHeight));
+    qCDebug(KWIN_CORE) << "PERMITTED" << this << bool(value_mask & configureGeometryMask);
 
     if (gravity == 0)   // default (nonsense) value for the argument
         gravity = m_geometryHints.windowGravity();
-    if (value_mask & (CWX | CWY)) {
+    if (value_mask & configurePositionMask) {
         QPoint new_pos = calculateGravitation(true, gravity);   // undo gravitation
-        if (value_mask & CWX)
+        if (value_mask & XCB_CONFIG_WINDOW_X)
             new_pos.setX(rx);
-        if (value_mask & CWY)
+        if (value_mask & XCB_CONFIG_WINDOW_Y)
             new_pos.setY(ry);
 
         // clever(?) workaround for applications like xv that want to set
@@ -1732,16 +1736,16 @@ void Client::configureRequest(int value_
         // frame size due to kwin being a double-reparenting window
         // manager
         if (new_pos.x() == x() + clientPos().x() && new_pos.y() == y() + clientPos().y()
-                && gravity == NorthWestGravity && !from_tool) {
+                && gravity == XCB_GRAVITY_NORTH_WEST && !from_tool) {
             new_pos.setX(x());
             new_pos.setY(y());
         }
 
         int nw = clientSize().width();
         int nh = clientSize().height();
-        if (value_mask & CWWidth)
+        if (value_mask & XCB_CONFIG_WINDOW_WIDTH)
             nw = rw;
-        if (value_mask & CWHeight)
+        if (value_mask & XCB_CONFIG_WINDOW_HEIGHT)
             nh = rh;
         QSize ns = sizeForClientSize(QSize(nw, nh));     // enforces size if needed
         new_pos = rules()->checkPosition(new_pos);
@@ -1768,13 +1772,12 @@ void Client::configureRequest(int value_
             workspace() -> updateClientArea();
     }
 
-    if (value_mask & (CWWidth | CWHeight)
-            && !(value_mask & (CWX | CWY))) {     // pure resize
+    if (value_mask & configureSizeMask && !(value_mask & configurePositionMask)) {     // pure resize
         int nw = clientSize().width();
         int nh = clientSize().height();
-        if (value_mask & CWWidth)
+        if (value_mask & XCB_CONFIG_WINDOW_WIDTH)
             nw = rw;
-        if (value_mask & CWHeight)
+        if (value_mask & XCB_CONFIG_WINDOW_HEIGHT)
             nh = rh;
         QSize ns = sizeForClientSize(QSize(nw, nh));
 
@@ -1824,37 +1827,37 @@ void Client::resizeWithChecks(int w, int
         gravity = m_geometryHints.windowGravity();
     }
     switch(gravity) {
-    case NorthWestGravity: // top left corner doesn't move
+    case XCB_GRAVITY_NORTH_WEST: // top left corner doesn't move
     default:
         break;
-    case NorthGravity: // middle of top border doesn't move
+    case XCB_GRAVITY_NORTH: // middle of top border doesn't move
         newx = (newx + width() / 2) - (w / 2);
         break;
-    case NorthEastGravity: // top right corner doesn't move
+    case XCB_GRAVITY_NORTH_EAST: // top right corner doesn't move
         newx = newx + width() - w;
         break;
-    case WestGravity: // middle of left border doesn't move
+    case XCB_GRAVITY_WEST: // middle of left border doesn't move
         newy = (newy + height() / 2) - (h / 2);
         break;
-    case CenterGravity: // middle point doesn't move
+    case XCB_GRAVITY_CENTER: // middle point doesn't move
         newx = (newx + width() / 2) - (w / 2);
         newy = (newy + height() / 2) - (h / 2);
         break;
-    case StaticGravity: // top left corner of _client_ window doesn't move
+    case XCB_GRAVITY_STATIC: // top left corner of _client_ window doesn't move
         // since decoration doesn't change, equal to NorthWestGravity
         break;
-    case EastGravity: // // middle of right border doesn't move
+    case XCB_GRAVITY_EAST: // // middle of right border doesn't move
         newx = newx + width() - w;
         newy = (newy + height() / 2) - (h / 2);
         break;
-    case SouthWestGravity: // bottom left corner doesn't move
+    case XCB_GRAVITY_SOUTH_WEST: // bottom left corner doesn't move
         newy = newy + height() - h;
         break;
-    case SouthGravity: // middle of bottom border doesn't move
+    case XCB_GRAVITY_SOUTH: // middle of bottom border doesn't move
         newx = (newx + width() / 2) - (w / 2);
         newy = newy + height() - h;
         break;
-    case SouthEastGravity: // bottom right corner doesn't move
+    case XCB_GRAVITY_SOUTH_EAST: // bottom right corner doesn't move
         newx = newx + width() - w;
         newy = newy + height() - h;
         break;
@@ -1868,13 +1871,13 @@ void Client::NETMoveResizeWindow(int fla
     int gravity = flags & 0xff;
     int value_mask = 0;
     if (flags & (1 << 8))
-        value_mask |= CWX;
+        value_mask |= XCB_CONFIG_WINDOW_X;
     if (flags & (1 << 9))
-        value_mask |= CWY;
+        value_mask |= XCB_CONFIG_WINDOW_Y;
     if (flags & (1 << 10))
-        value_mask |= CWWidth;
+        value_mask |= XCB_CONFIG_WINDOW_WIDTH;
     if (flags & (1 << 11))
-        value_mask |= CWHeight;
+        value_mask |= XCB_CONFIG_WINDOW_HEIGHT;
     configureRequest(value_mask, x, y, width, height, gravity, true);
 }
 
