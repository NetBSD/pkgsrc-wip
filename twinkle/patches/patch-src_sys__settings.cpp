$NetBSD$

* use /dev/audio as standard device on NetBSD

--- src/sys_settings.cpp.orig	2022-02-19 05:05:00.000000000 +0000
+++ src/sys_settings.cpp
@@ -1839,7 +1839,7 @@ list<t_audio_device> t_sys_settings::get
 	list<t_audio_device> l;
 	
 	for (int i = -1; i <= 15; i ++) {
-		string dev = "/dev/dsp";
+		string dev = DEV_DSP;
 		if (i >= 0) dev += int2str(i);
 		t_audio_device oss_dev;
 		oss_dev.type = t_audio_device::OSS;
@@ -1893,7 +1893,7 @@ list<t_audio_device> t_sys_settings::get
 	// just add /dev/dsp as the default device.
 	if (l.empty()) {
 		t_audio_device oss_dev;
-		oss_dev.device = "/dev/dsp";
+		oss_dev.device = DEV_DSP;
 		oss_dev.type = t_audio_device::OSS;
 		l.push_back(oss_dev);
 	}
