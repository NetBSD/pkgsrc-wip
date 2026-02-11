$NetBSD$

Disable "apidoc" (not required for building man pages).
Disable "intersphinx_mapping" (wants do fetch stuff from network).
pkgsrc-wip package for py-furo is broken (not required for building man pages).

--- docs/conf.py.orig	2025-10-27 15:21:36.000000000 +0000
+++ docs/conf.py
@@ -49,35 +49,17 @@ language = "en"
 extensions = [
     "myst_parser",
     "sphinx.ext.autodoc",
-    "sphinx.ext.intersphinx",
     "sphinx.ext.viewcode",
     "sphinx.ext.napoleon",
-    "sphinxcontrib.apidoc",
 ]
 
 templates_path = ["_templates"]
 exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]
 
-# -- Extensions configuration ------------------------------------------------
-
-apidoc_module_dir = str(ROOT_DIR / "src/reuse")
-# apidoc_output_dir = "api"
-apidoc_excluded_paths = ["cli"]
-apidoc_separate_modules = True
-apidoc_toc_file = False
-apidoc_extra_args = ["--maxdepth", "2"]
-
-autodoc_member_order = "bysource"
-
-intersphinx_mapping = {"python": ("https://docs.python.org/3", None)}
-
-# Auto-generate header anchors up to 3 headings deep.
-myst_heading_anchors = 3
-
 # -- Options for HTML output -------------------------------------------------
 # https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output
 
-html_theme = "furo"
+#html_theme = "furo"
 html_logo = "reuse-r-only.svg"
 html_static_path = ["_static"]
 
