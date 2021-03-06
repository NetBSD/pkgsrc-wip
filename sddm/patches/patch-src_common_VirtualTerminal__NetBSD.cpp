$NetBSD$

NetBSD VirtualTerminal support.

--- src/common/VirtualTerminal_NetBSD.cpp.orig	2020-11-28 06:19:36.308310491 +0000
+++ src/common/VirtualTerminal_NetBSD.cpp
@@ -0,0 +1,37 @@
+/***************************************************************************
+* Copyright (c) 2015 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
+*
+* This program is free software; you can redistribute it and/or modify
+* it under the terms of the GNU General Public License as published by
+* the Free Software Foundation; either version 2 of the License, or
+* (at your option) any later version.
+*
+* This program is distributed in the hope that it will be useful,
+* but WITHOUT ANY WARRANTY; without even the implied warranty of
+* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
+* GNU General Public License for more details.
+*
+* You should have received a copy of the GNU General Public License
+* along with this program; if not, write to the
+* Free Software Foundation, Inc.,
+* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
+***************************************************************************/
+
+#include <QDebug>
+#include <QString>
+
+#include "VirtualTerminal.h"
+
+
+namespace SDDM {
+    namespace VirtualTerminal {
+        int setUpNewVt() {
+            qDebug() << "New VT is unsupported on NetBSD";
+            return -1;
+        }
+
+        void jumpToVt(int vt, bool vt_auto) {
+            qDebug() << "Jumping to VT" << vt << "is unsupported on NetBSD";
+        }
+    }
+}
