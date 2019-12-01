$NetBSD$

16-bit linear is more likely to work on more platforms, so default to it.

--- libs/ardour/ardour/session_configuration_vars.h.orig	2017-09-15 20:56:23.000000000 +0000
+++ libs/ardour/ardour/session_configuration_vars.h
@@ -29,7 +29,7 @@ CONFIG_VARIABLE (uint32_t, destructive_x
 CONFIG_VARIABLE (bool, use_region_fades, "use-region-fades", true)
 CONFIG_VARIABLE (bool, use_transport_fades, "use-transport-fades", true)
 CONFIG_VARIABLE (bool, use_monitor_fades, "use-monitor-fades", true)
-CONFIG_VARIABLE (SampleFormat, native_file_data_format,  "native-file-data-format", ARDOUR::FormatFloat)
+CONFIG_VARIABLE (SampleFormat, native_file_data_format,  "native-file-data-format", ARDOUR::FormatInt16)
 CONFIG_VARIABLE (HeaderFormat, native_file_header_format,  "native-file-header-format", ARDOUR::WAVE)
 CONFIG_VARIABLE (bool, auto_play, "auto-play", false)
 CONFIG_VARIABLE (bool, auto_return, "auto-return", false)
