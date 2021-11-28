$NetBSD$

Use setuptools for setup.py

--- setup.py.orig	2021-03-31 23:53:33.000000000 +0000
+++ setup.py
@@ -18,7 +18,7 @@
 # along with this program. If not, see <http://www.gnu.org/licenses/>.
 # -----------------------------------------------------------------------------
 
-from distutils.core import setup
+from setuptools import setup
 
 setup(
     version='3.1.0',
