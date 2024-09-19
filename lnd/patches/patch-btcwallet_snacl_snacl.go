--- vendor/github.com/btcsuite/btcwallet/snacl/snacl.go.orig	2019-09-10 07:13:33.291657578 +0000
+++ vendor/github.com/btcsuite/btcwallet/snacl/snacl.go	2019-09-10 07:13:50.869459789 +0000
@@ -14,8 +14,8 @@
 	"runtime/debug"
 
 	"github.com/btcsuite/btcwallet/internal/zero"
-	"github.com/btcsuite/golangcrypto/nacl/secretbox"
-	"github.com/btcsuite/golangcrypto/scrypt"
+	"golang.org/x/crypto/nacl/secretbox"
+	"golang.org/x/crypto/scrypt"
 )
 
 var (
