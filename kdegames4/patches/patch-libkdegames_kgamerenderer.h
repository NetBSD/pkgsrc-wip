$NetBSD: patch-libkdegames_kgamerenderer.h,v 1.1 2011/05/13 23:25:15 mwdavies Exp $

Build with gcc4.1

--- libkdegames/kgamerenderer.h.orig	2011-05-02 03:11:15.000000000 +0000
+++ libkdegames/kgamerenderer.h
@@ -208,7 +208,7 @@ class KDEGAMES_EXPORT KGameRenderer : pu
 		///@note  For non-animated frames, set @a frame to -1 or omit it.
 		///@note  Custom colors increase the rendering time considerably, so use
 		///       this feature only if you really need its flexibility.
-		QPixmap spritePixmap(const QString& key, const QSize& size, int frame = -1, const QHash<QColor, QColor>& customColors = QHash<QColor, QColor>()) const;
+		QPixmap spritePixmap(const QString& key, const QSize& size, int frame = -1, const QHash<QColor, QColor>& customColors = (QHash<QColor, QColor>())) const;
 	public Q_SLOTS:
 		///Load the given theme and update the pixmaps of all associated
 		///KGameRendererClient instances.
