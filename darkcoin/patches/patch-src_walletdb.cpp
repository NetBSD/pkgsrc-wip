$NetBSD$

--- src/walletdb.cpp.orig	2015-09-28 15:49:30.000000000 +0000
+++ src/walletdb.cpp
@@ -872,11 +872,7 @@ bool BackupWallet(const CWallet& wallet,
                     pathDest /= wallet.strWalletFile;
 
                 try {
-#if BOOST_VERSION >= 104000
-                    filesystem::copy_file(pathSrc, pathDest, filesystem::copy_option::overwrite_if_exists);
-#else
-                    filesystem::copy_file(pathSrc, pathDest);
-#endif
+                    filesystem::copy(pathSrc, pathDest);
                     LogPrintf("copied wallet.dat to %s\n", pathDest.string());
                     return true;
                 } catch(const filesystem::filesystem_error &e) {
