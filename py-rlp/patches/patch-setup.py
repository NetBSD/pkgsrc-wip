$NetBSD$

Remove dependency on py-setuptools-markdown

--- setup.py.orig	2019-12-02 17:00:58.000000000 +0000
+++ setup.py
@@ -44,13 +44,12 @@ setup(
     # *IMPORTANT*: Don't manually change the version here. See README for more.
     version='1.2.0',
     description="A package for Recursive Length Prefix encoding and decoding",
-    long_description_markdown_filename='README.md',
+    long_description_content_type='text/markdown',
     author="jnnk",
     author_email='jnnknnj@gmail.com',
     url='https://github.com/ethereum/pyrlp',
     packages=find_packages(exclude=["tests", "tests.*"]),
     include_package_data=True,
-    setup_requires=['setuptools-markdown'],
     install_requires=[
         "eth-utils>=1.0.2,<2",
     ],
