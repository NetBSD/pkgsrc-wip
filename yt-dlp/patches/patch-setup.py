--- setup.py.orig       2021-09-07 17:47:14.900243528 +0200
+++ setup.py    2021-09-07 17:48:07.902848311 +0200
@@ -29,8 +29,7 @@
     ('share/bash-completion/completions', ['completions/bash/yt-dlp']),
     ('share/zsh/site-functions', ['completions/zsh/_yt-dlp']),
     ('share/fish/vendor_completions.d', ['completions/fish/yt-dlp.fish']),
-    ('share/doc/yt_dlp', ['README.txt']),
-    ('share/man/man1', ['yt-dlp.1'])
+    ('share/doc/yt_dlp', ['README.txt'])
 ]
 root = os.path.dirname(os.path.abspath(__file__))
 data_files = []
