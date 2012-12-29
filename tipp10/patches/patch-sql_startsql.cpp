$NetBSD: patch-sql_startsql.cpp,v 1.1 2012/12/29 14:51:33 othyro Exp $

Remove unnecessary function qualifier.

--- sql/startsql.cpp.orig	2011-03-12 20:14:24.000000000 +0000
+++ sql/startsql.cpp
@@ -344,7 +344,7 @@ bool StartSql::updateOwnLesson(QString l
 		for (i = 0; i < content.size(); i++) {
 			//simplifiedContent = QString::QString(
 			//	content.at(i)).replace(QChar(0x27), "''", Qt::CaseSensitive).simplified();
-			simplifiedContent = trim(QString::QString(
+			simplifiedContent = trim(QString(
 				content.at(i)).replace(QChar(0x27), "''", Qt::CaseSensitive));
 
 			if (!query.exec("INSERT INTO own_content VALUES(NULL,'" +
