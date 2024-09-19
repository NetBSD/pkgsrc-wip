--- vendor/github.com/btcsuite/btcwallet/internal/prompt/prompt.go.orig	2019-09-10 07:13:06.101605935 +0000
+++ vendor/github.com/btcsuite/btcwallet/internal/prompt/prompt.go	2019-09-10 07:13:24.013671552 +0000
@@ -14,7 +14,7 @@
 
 	"github.com/btcsuite/btcutil/hdkeychain"
 	"github.com/btcsuite/btcwallet/internal/legacy/keystore"
-	"github.com/btcsuite/golangcrypto/ssh/terminal"
+	"golang.org/x/crypto/ssh/terminal"
 )
 
 // ProvideSeed is used to prompt for the wallet seed which maybe required during
