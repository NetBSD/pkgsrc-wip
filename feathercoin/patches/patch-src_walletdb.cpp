--- src/walletdb.cpp~	2014-06-19 00:51:15.000000000 -0700
+++ src/walletdb.cpp	2014-08-19 03:50:42.757367359 -0700
--- src/walletdb.cpp.orig	2014-10-31 15:32:32.000000000 +0000
+++ src/walletdb.cpp
@@ -550,11 +550,7 @@ bool BackupWallet(const CWallet& wallet,
                     pathDest /= wallet.strWalletFile;
 
                 try {
-#if BOOST_VERSION >= 104000
-                    filesystem::copy_file(pathSrc, pathDest, filesystem::copy_option::overwrite_if_exists);
-#else
-                    filesystem::copy_file(pathSrc, pathDest);
-#endif
+                    filesystem::copy(pathSrc, pathDest);
                     printf("copied wallet.dat to %s\n", pathDest.string().c_str());
                     return true;
                 } catch(const filesystem::filesystem_error &e) {
