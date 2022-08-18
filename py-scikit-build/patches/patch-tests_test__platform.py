$NetBSD$

--- tests/test_platform.py.orig	2022-05-18 17:52:53.000000000 +0000
+++ tests/test_platform.py
@@ -84,11 +84,12 @@ def test_generator_cleanup():
     assert not os.path.exists(test_folder)
 
 
-@pytest.mark.parametrize("supported_platform", ["darwin", "freebsd", "openbsd", "linux", "windows", "os400", "cygwin"])
+@pytest.mark.parametrize("supported_platform", ["darwin", "freebsd", "netbsd", "openbsd", "linux", "windows", "os400", "cygwin"])
 def test_known_platform(supported_platform, mocker):
     mocker.patch("platform.system", return_value=supported_platform)
     platforms = {
         "freebsd": "BSD",
+        "netbsd": "BSD",
         "openbsd": "BSD",
         "linux": "Linux",
         "darwin": "OSX",
