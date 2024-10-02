$NetBSD$

Disable "intersphinx_mapping" (wants do fetch stuff from network).
pkgsrc-wip package for py-furo is broken (not required for building man pages).

--- docs/conf.py.orig	2024-07-08 11:58:05.000000000 +0000
+++ docs/conf.py
@@ -69,12 +69,12 @@ apidoc_extra_args = ["--maxdepth", "2"]
 
 autodoc_member_order = "bysource"
 
-intersphinx_mapping = {"python": ("https://docs.python.org/3", None)}
+#intersphinx_mapping = {"python": ("https://docs.python.org/3", None)}
 
 # -- Options for HTML output -------------------------------------------------
 # https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output
 
-html_theme = "furo"
+#html_theme = "furo"
 html_logo = "reuse-r-only.svg"
 html_static_path = ["_static"]
 
