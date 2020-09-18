$NetBSD$

Remove dependency on py-setuptools-markdown

--- setup.py.orig	2018-09-05 22:42:35.000000000 +0000
+++ setup.py
@@ -46,14 +46,13 @@ setup(
     # *IMPORTANT*: Don't manually change the version here. Use `make bump`, as described in readme
     version='0.2.0',
     description="""eth-hash: The Ethereum hashing function, keccak256, sometimes (erroneously) called sha3""",
-    long_description_markdown_filename='README.md',
+    long_description_content_type='text/markdown',
     author='Jason Carver',
     author_email='ethcalibur+pip@gmail.com',
     url='https://github.com/ethereum/eth-hash',
     include_package_data=True,
     install_requires=[
     ],
-    setup_requires=['setuptools-markdown'],
     python_requires='>=3.5, <4',
     extras_require=extras_require,
     py_modules=['eth_hash'],
