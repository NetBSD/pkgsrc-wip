$NetBSD: patch-libkdegames_kgamerenderer_p.h,v 1.1 2011/05/13 23:25:15 mwdavies Exp $

Build with gcc4.1

--- libkdegames/kgamerenderer_p.h.orig	2011-05-02 03:17:58.000000000 +0000
+++ libkdegames/kgamerenderer_p.h
@@ -33,7 +33,7 @@ namespace KGRInternal
 	//Describes the state of a KGameRendererClient.
 	struct ClientSpec
 	{
-		inline ClientSpec(const QString& spriteKey = QString(), int frame = -1, const QSize& size = QSize(), const QHash<QColor, QColor>& customColors = QHash<QColor, QColor>());
+		inline ClientSpec(const QString& spriteKey = QString(), int frame = -1, const QSize& size = QSize(), const QHash<QColor, QColor>& customColors = (QHash<QColor, QColor>()));
 		QString spriteKey;
 		int frame;
 		QSize size;
