$NetBSD$

--- main.go.orig	2024-02-12 13:41:17.183451591 +0000
+++ main.go
@@ -68,7 +68,7 @@ func (d *SerialDiscovery) Stop() error {
 
 // StartSync is the handler for the pluggable-discovery START_SYNC command
 func (d *SerialDiscovery) StartSync(eventCB discovery.EventCallback, errorCB discovery.ErrorCallback) error {
-	close, err := sync.Start(eventCB, errorCB)
+	close, err := sync.Start()
 	if err != nil {
 		return err
 	}
