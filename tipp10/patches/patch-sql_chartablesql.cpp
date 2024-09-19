$NetBSD$

Remove unnecessary function qualifier

--- sql/chartablesql.cpp
+++ sql/chartablesql.cpp
@@ -57,7 +57,7 @@ QVariant CharSqlModel::data(const QModelIndex &index, int role) const {
 			// Read the unicode value
 			unicode = value.toInt();
 			// Convert unicode to a char
-			unicodeToChar = QString::QString(QChar(unicode)); //"\'" + QString::QString(QChar(unicode)) + "\'";
+			unicodeToChar = QString(QChar(unicode)); //"\'" + QString::QString(QChar(unicode)) + "\'";
 			return unicodeToChar;
 		} else {
 			// Last column (error weight)
