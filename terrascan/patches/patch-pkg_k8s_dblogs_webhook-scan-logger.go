$NetBSD$

Use github.com/mattn/go-sqlite3 instead of modernc.org/sqlite to avoid possible
modernc.org/libc dependency (still not ported on NetBSD).

Via <https://github.com/accurics/terrascan/pull/906/>.

--- pkg/k8s/dblogs/webhook-scan-logger.go.orig	2021-10-07 15:14:21.000000000 +0000
+++ pkg/k8s/dblogs/webhook-scan-logger.go
@@ -25,7 +25,7 @@ import (
 	"go.uber.org/zap"
 
 	// importing sqlite driver
-	_ "modernc.org/sqlite"
+	_ "github.com/mattn/go-sqlite3"
 )
 
 // WebhookScanLogger handles the logic to push scan logs to db
@@ -181,7 +181,7 @@ func (g *WebhookScanLogger) initDBIfNeed
 		}
 		file.Close()
 
-		db, err := sql.Open("sqlite", g.dbFilePath())
+		db, err := sql.Open("sqlite3", g.dbFilePath())
 		if err != nil {
 			zap.S().Errorf("failed to open sql file. error: '%v'", err)
 			return err
@@ -215,7 +215,7 @@ func (g *WebhookScanLogger) initDBIfNeed
 func (g *WebhookScanLogger) getDbHandler() (*sql.DB, error) {
 	g.initDBIfNeeded()
 
-	db, err := sql.Open("sqlite", g.dbFilePath())
+	db, err := sql.Open("sqlite3", g.dbFilePath())
 	if err != nil {
 		zap.S().Errorf("failed to open sql file. error: '%v'", err)
 	}
