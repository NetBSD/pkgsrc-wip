$NetBSD: patch-plugins_chartshape_kdchart_src_KDChartBackgroundAttributes.cpp,v 1.1 2012/03/28 09:04:13 mwdavies Exp $

From accabfeac22e869e5a248a764a64096d107e4c7c Mon Sep 17 00:00:00 2001
From: Michael Jansen <kde@michael-jansen.biz>
Date: Mon, 11 Jul 2011 00:27:38 +0200
Subject: [PATCH] Fix build with QT 4.8.

KDChartBackgroundAttributes.cpp:153:26: error: ambiguous overload for 'operator<<' in '((QDebug*)((QDebug*)operator<<(QDebug, const QBrush&)(((const QBrush&)((const QBrush*)(& KDChart::BackgroundAttributes::brush() const())))).QDebug::operator<<(((const char*)"pixmapmode=")))->QDebug::operator<<(((int)((const KDChart::BackgroundAttributes*)ba)->KDChart::BackgroundAttributes::pixmapMode())))->QDebug::operator<<(((const char*)"pixmap=")) << KDChart::BackgroundAttributes::pixmap() const()'

It does not know if it should convert QPixmap to QVariant or QBrush before dumping it into
qDebug(). It happens because with qt4.8 qvariant is included implictely with klocale.h over
qlocale.h. Which was not the case before qt4.8.

Related:     QTBUG-19764: Please add QDebug operator for QPixmap
---
 .../kdchart/src/KDChartBackgroundAttributes.cpp    |    5 ++++-
 1 files changed, 4 insertions(+), 1 deletions(-)

diff --git a/plugins/chartshape/kdchart/src/KDChartBackgroundAttributes.cpp b/plugins/chartshape/kdchart/src/KDChartBackgroundAttributes.cpp
index 2dc4974..9f2990a 100644
--- plugins/chartshape/kdchart/src/KDChartBackgroundAttributes.cpp
+++ plugins/chartshape/kdchart/src/KDChartBackgroundAttributes.cpp
@@ -22,6 +22,9 @@
 
 #include "KDChartBackgroundAttributes.h"
 #include <QPixmap>
+#if !defined(QT_NO_DEBUG_STREAM)
+#include <QVariant>
+#endif
 
 #include <KDABLibFakes>
 
@@ -150,7 +153,7 @@ QDebug operator<<(QDebug dbg, const KDChart::BackgroundAttributes& ba)
 	<< "visible="<<ba.isVisible()
 	<< "brush="<<ba.brush()
 	<< "pixmapmode="<<ba.pixmapMode()
-	<< "pixmap="<<ba.pixmap()
+	<< "pixmap="<<QVariant(ba.pixmap())
 	<< ")";
     return dbg;
 }
-- 
1.7.3.4

