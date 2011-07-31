$NetBSD: patch-Swift_QtUI_ChatList_ChatListDelegate.cpp,v 1.1.1.1 2011/07/31 22:28:23 schnoebe Exp $

--- Swift/QtUI/ChatList/ChatListDelegate.cpp.orig	2011-04-22 21:07:47.000000000 +0000
+++ Swift/QtUI/ChatList/ChatListDelegate.cpp
@@ -4,8 +4,8 @@
  * See Documentation/Licenses/GPLv3.txt for more information.
  */
 
-#include <QPen>
-#include <QPainter>
+#include <QtGui/QPen>
+#include <QtGui/QPainter>
 
 #include "Swift/QtUI/ChatList/ChatListDelegate.h"
 #include "Swift/QtUI/Roster/GroupItemDelegate.h"
