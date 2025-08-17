$NetBSD$

--- docutils/writers/html5_polyglot/__init__.py.orig	2025-07-29 14:37:37.693464500 +0000
+++ docutils/writers/html5_polyglot/__init__.py
@@ -93,7 +93,7 @@ class Writer(_html_base.Writer):
          ('Suggest at which point images should be loaded: '
           '"embed", "link" (default), or "lazy".',
           ['--image-loading'],
-          {'choices': ('embed', 'link', 'lazy'),
+          {'metavar': '<strategy>', 'choices': ('embed', 'link', 'lazy'),
            # 'default': 'link'  # default set in _html_base.py
            }),
          ('Append a self-link to section headings.',
