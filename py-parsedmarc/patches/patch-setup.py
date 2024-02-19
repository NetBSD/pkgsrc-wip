$NetBSD$

Remove bounds.

--- setup.py.orig	2022-06-20 14:35:57.000000000 +0000
+++ setup.py
@@ -98,14 +98,14 @@ setup(
                       'requests>=2.22.0', 'imapclient>=2.1.0',
                       'dateparser>=1.1.1',
                       'mailsuite>=1.6.1',
-                      'elasticsearch<7.14.0',
-                      'elasticsearch-dsl==7.4.0',
+                      'elasticsearch',
+                      'elasticsearch-dsl',
                       'kafka-python>=1.4.4',
                       'tqdm>=4.31.1',
                       'lxml>=4.4.0',
                       'boto3>=1.16.63',
                       'msgraph-core>=0.2.2',
-                      'azure-identity>=1.8.0'
+                      'azure-identity>=1.8.0',
                       'google-api-core>=2.4.0',
                       'google-api-python-client>=2.35.0',
                       'google-auth>=2.3.3',
