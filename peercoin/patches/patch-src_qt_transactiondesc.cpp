$NetBSD$

--- src/qt/transactiondesc.cpp.orig	2015-07-27 20:55:24.000000000 +0000
+++ src/qt/transactiondesc.cpp
@@ -8,7 +8,7 @@
 #include "db.h"
 #include "ui_interface.h"
 #include "base58.h"
-
+#include "walletdb.h"
 #include <QString>
 
 using namespace std;
