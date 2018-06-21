$NetBSD$

Pick up `cvss' module from the parent directory in order to properly
run the tests without having the cvss module installed.

--- tests/test_cvss3.py.orig	2017-01-11 09:11:40.000000000 +0000
+++ tests/test_cvss3.py
@@ -2,6 +2,8 @@ from os import path
 import sys
 import unittest
 
+sys.path.insert(0, path.dirname(path.dirname(path.abspath(__file__))))
+
 from cvss import CVSS3
 from cvss.exceptions import CVSS3MalformedError, CVSS3MandatoryError, CVSS3RHScoreDoesNotMatch, \
     CVSS3RHMalformedError
