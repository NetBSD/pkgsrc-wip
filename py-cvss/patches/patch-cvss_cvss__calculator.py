$NetBSD$

Gracefully handle possible ^D and treat it like a ^C.

Merged upstream as part of https://github.com/skontar/cvss/pull/14

--- cvss/cvss_calculator.py.orig	2017-01-11 09:11:40.000000000 +0000
+++ cvss/cvss_calculator.py
@@ -66,7 +66,7 @@ def main():
                     print(scores[i])
             print('Cleaned vector:       ', cvss_vector.clean_vector())
             print('Red Hat vector:       ', cvss_vector.rh_vector())
-    except KeyboardInterrupt:
+    except (KeyboardInterrupt, EOFError):
         print()
 
 
