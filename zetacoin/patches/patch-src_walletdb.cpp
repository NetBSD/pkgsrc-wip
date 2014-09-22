--- src/walletdb.cpp~	2014-06-19 00:51:15.000000000 -0700
+++ src/walletdb.cpp	2014-08-19 03:50:42.757367359 -0700
@@ -844,11 +844,7 @@
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
