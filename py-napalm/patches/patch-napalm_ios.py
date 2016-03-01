$NetBSD$

Optionally use "enable" to enter privileged mode, not everyone have
their AAA set up to log directly in as privileged.

--- napalm/ios.py.orig	2016-02-08 08:22:24.000000000 +0000
+++ napalm/ios.py
@@ -21,7 +21,7 @@ from datetime import datetime
 
 from netmiko import ConnectHandler, FileTransfer
 from napalm.base import NetworkDriver
-from napalm.exceptions import ReplaceConfigException, MergeConfigException
+from napalm.exceptions import ReplaceConfigException, MergeConfigException, EnableModeException
 
 # Easier to store these as constants
 HOUR_SECONDS = 3600
@@ -47,6 +47,7 @@ class IOSDriver(NetworkDriver):
         self.global_delay_factor = optional_args.get('global_delay_factor', .5)
         self.port = optional_args.get('port', 22)
         self.auto_rollback_on_error = optional_args.get('auto_rollback_on_error', True)
+        self.secret = optional_args.get('secret', '')
         self.device = None
         self.config_replace = False
 
@@ -58,7 +59,13 @@ class IOSDriver(NetworkDriver):
                                      username=self.username,
                                      password=self.password,
                                      global_delay_factor=self.global_delay_factor,
+                                     secret=self.secret,
                                      verbose=False)
+        if self.secret:
+          self.device.enable()
+          if not self.device.check_enable_mode():
+            raise EnableModeException('not in enable, Wrong password?')
+
 
     def close(self):
         """Closes the connection to the device."""
