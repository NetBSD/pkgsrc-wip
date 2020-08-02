$NetBSD$

Use latest stable azure-pipeline-go (and azure-storage-blob-go) to support
Solaris / illumos builds.

--- go.mod.orig	2020-07-27 16:03:38.000000000 +0000
+++ go.mod
@@ -5,8 +5,8 @@ go 1.13
 require (
 	cloud.google.com/go v0.39.0
 	git.apache.org/thrift.git v0.13.0
-	github.com/Azure/azure-pipeline-go v0.2.1
-	github.com/Azure/azure-storage-blob-go v0.8.0
+	github.com/Azure/azure-pipeline-go v0.2.2
+	github.com/Azure/azure-storage-blob-go v0.10.0
 	github.com/Azure/go-autorest/autorest/adal v0.9.0 // indirect
 	github.com/Shopify/sarama v1.24.1
 	github.com/StackExchange/wmi v0.0.0-20190523213315-cbe66965904d // indirect
