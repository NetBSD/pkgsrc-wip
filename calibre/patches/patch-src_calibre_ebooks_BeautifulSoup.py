$NetBSD$

/usr/pkg/lib/calibre/calibre/ebooks/BeautifulSoup.py imports bs4,
which imports this:

  File "/usr/pkg/lib/python2.7/site-packages/bs4/dammit.py", line 13, in <module>
    from html.entities import codepoint2name
ImportError: No module named html.entities

According to https://stackoverflow.com/questions/27372347/beautifulsoup-importerror-no-module-named-html-entities this module only exists for Python 3.
There is the package /www/py-beautifulsoup, py27-beautifulsoup-3.2.2 for Python2, 

But:
calibre requires python >= 2.7.9 and < 3. Current python version: 3.9.9
*** Error code 1

Why would calibre import a Py3-specific version of BeautifulSoup???

--- src/calibre/ebooks/BeautifulSoup.py.orig	2020-02-21 03:27:12.000000000 +0000
+++ src/calibre/ebooks/BeautifulSoup.py
@@ -4,8 +4,8 @@
 
 from __future__ import absolute_import, division, print_function, unicode_literals
 
-import bs4
-from bs4 import (  # noqa
+import BeautifulSoup
+from BeautifulSoup import (  # noqa
     CData, Comment, Declaration, NavigableString, ProcessingInstruction,
     SoupStrainer, Tag, __version__
 )
