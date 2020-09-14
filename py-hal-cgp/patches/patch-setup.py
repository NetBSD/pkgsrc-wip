$NetBSD$

--- setup.py.orig	2020-07-01 13:01:38.000000000 +0000
+++ setup.py
@@ -14,29 +14,6 @@ def read_version():
         return match[0]
 
 
-def read_requirements():
-    requirements = []
-    with open("./requirements.txt") as f:
-        for req in f:
-            req = req.replace("\n", " ")
-            requirements.append(req)
-    return requirements
-
-
-def read_extra_requirements():
-
-    extra_requirements = {}
-    extra_requirements["all"] = []
-    with open("./extra-requirements.txt") as f:
-        for req in f:
-            req = req.replace("\n", " ")
-            extra_requirements[_cut_version_number_from_requirement(req)] = [req]
-            extra_requirements["all"].append(req)
-
-    extra_requirements[":python_version == '3.6'"] = ["dataclasses"]
-    return extra_requirements
-
-
 setup(
     name="hal-cgp",
     version=read_version(),
@@ -46,11 +23,7 @@ setup(
     keywords="genetic programming",
     url="https://github.com/Happy-Algorithms-League/hal-cgp",
     python_requires=">=3.6, <4",
-    install_requires=read_requirements(),
-    extras_require=read_extra_requirements(),
     packages=["cgp", "cgp.ea", "cgp.local_search"],
-    long_description=open("long_description.md").read(),
-    long_description_content_type="text/markdown",
     classifiers=[
         "Development Status :: 4 - Beta",
         "License :: OSI Approved :: GNU General Public License v3 (GPLv3)",
