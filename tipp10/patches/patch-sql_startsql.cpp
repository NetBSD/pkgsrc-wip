$NetBSD$

Remove unnecessary function qualifier

--- sql/startsql.cpp
+++ sql/startsql.cpp
@@ -344,7 +344,7 @@ bool StartSql::updateOwnLesson(QString lessonnumber, QString lessonname,
 		for (i = 0; i < content.size(); i++) {
 			//simplifiedContent = QString::QString(
 			//	content.at(i)).replace(QChar(0x27), "''", Qt::CaseSensitive).simplified();
-			simplifiedContent = trim(QString::QString(
+			simplifiedContent = trim(QString(
 				content.at(i)).replace(QChar(0x27), "''", Qt::CaseSensitive));
 
 			if (!query.exec("INSERT INTO own_content VALUES(NULL,'" +
