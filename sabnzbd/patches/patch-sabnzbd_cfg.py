$NetBSD$

Default the phone-home for a version check to OFF.

--- sabnzbd/cfg.py.orig	2023-02-05 21:17:20.000000000 +0000
+++ sabnzbd/cfg.py
@@ -266,7 +266,7 @@ direct_unpack_tested = OptionBool("misc"
 ##############################################################################
 # Config - General
 ##############################################################################
-version_check = OptionNumber("misc", "check_new_rel", 1)
+version_check = OptionNumber("misc", "check_new_rel", 0)
 autobrowser = OptionBool("misc", "auto_browser", True)
 language = OptionStr("misc", "language", "en")
 enable_https_verification = OptionBool("misc", "enable_https_verification", True)
