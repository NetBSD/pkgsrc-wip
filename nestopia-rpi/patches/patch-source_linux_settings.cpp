$NetBSD: patch-source_linux_settings.cpp,v 1.1 2014/11/02 08:36:13 nsloss Exp $

Add SDL_HWSURFACE enable flag.
Add flags for speed frame skip scanlines sound sample skip and native display 
mode conversion.
Binary -> Plain text settings file
--- source/linux/settings.cpp.orig	2008-10-23 03:45:58.000000000 +0000
+++ source/linux/settings.cpp
@@ -9,16 +9,168 @@
 #include <fstream>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include "settings.h"
 
 using namespace LinuxNst;
 
-#define READ_SETTING(x) fread(&x, sizeof(x), 1, f)
-#define WRITE_SETTING(x) if (fwrite(&x, sizeof(x), 1, f) != sizeof(x)) std::cout << "Error writing setting!\n"
+void READ_SETTING_STRING(FILE *f, const char *desc, int *variable, const char **arrayvalues, int numElements) {
+	char *linebuf = NULL;
+	char valbuf[256];
+	char stringbuf[256];
+	int i;
+	size_t linesize = 0;
+
+	fseek(f, 0L, SEEK_SET);
+
+	while (!feof(f)) {
+		getline(&linebuf, &linesize, f);
+		if (linesize > 0) {
+			if (*linebuf == '#')
+				continue;
+			sscanf(linebuf, "%s = %s", stringbuf, valbuf);
+		}
+		if (strcmp(stringbuf, desc) == 0)
+			break;
+	}
+	if (strcmp(stringbuf, desc) != 0) {
+		printf("Setting - %s NOT FOUND\n",desc);
+		goto string_setting_done;
+	}
+
+	for (i = 0; i < numElements; i++) {
+		if (strcmp(arrayvalues[i], valbuf) == 0) {
+			*variable = i; 
+			break;
+		}
+	}
+string_setting_done:
+
+	return;
+}
+
+void WRITE_SETTING_STRING(FILE *f, const char *desc, int variable, const char **arrayvalues, int numElements) {
+	char stringbuf[256];
+	int i;
+	
+	snprintf(stringbuf, sizeof(stringbuf), "#Possible values are:");
+	for (i = 0; i < numElements; i++)
+		snprintf(stringbuf + strlen(stringbuf), sizeof(stringbuf) - strlen(stringbuf), " %s", arrayvalues[i]);
+
+	snprintf(stringbuf + strlen(stringbuf), sizeof(stringbuf) - strlen(stringbuf), "\n");
+
+	fwrite(stringbuf, strlen(stringbuf), 1,f);
+
+	snprintf(stringbuf, sizeof(stringbuf), "%s = %s\n", desc, arrayvalues[variable]);
+	fwrite(stringbuf, strlen(stringbuf), 1,f);
+
+	return;
+}
+
+void READ_SETTING_NUM(FILE *f, const char *desc, int *variable, const int *arrayrange) {
+	char *linebuf = NULL;
+	int valbuf;
+	char stringbuf[256];
+	int i;
+	size_t linesize;
+
+	fseek(f, 0L, SEEK_SET);
+
+	while (!feof(f)) {
+		getline(&linebuf, &linesize, f);
+		if (linesize > 0) {
+			if (*linebuf == '#')
+				continue;
+			sscanf(linebuf, "%s = %d", stringbuf, &valbuf);
+		}
+		if (strcmp(stringbuf, desc) == 0)
+			break;
+	}
+	if (strcmp(stringbuf, desc) != 0) {
+		printf("Setting - %s NOT FOUND\n",desc);
+		goto string_setting_done;
+	}
+
+	if (valbuf >= arrayrange[0] && valbuf <= arrayrange[1])
+		*variable = valbuf; 
+
+string_setting_done:
+
+	return;
+}
+
+void WRITE_SETTING_NUM(FILE *f, const char *desc, int variable, const int *arrayrange) {
+	char stringbuf[256];
+
+	snprintf(stringbuf, sizeof(stringbuf), "#Value number from %d - %d (decimal)\n", arrayrange[0], arrayrange[1]);
+	fwrite(stringbuf, strlen(stringbuf), 1,f);
+
+	snprintf(stringbuf, sizeof(stringbuf), "%s = %d\n", desc, variable);
+	fwrite(stringbuf, strlen(stringbuf), 1,f);
+
+	return;
+}
+
+void READ_SETTING_NUMHEX(FILE *f, const char *desc, unsigned int *variable, const int *arrayrange) {
+	char *linebuf = NULL;
+	unsigned int valbuf;
+	char stringbuf[256];
+	int i;
+	size_t linesize;
+
+	fseek(f, 0L, SEEK_SET);
+
+	while (!feof(f)) {
+		getline(&linebuf, &linesize, f);
+		if (linesize > 0) {
+			if (*linebuf == '#')
+				continue;
+			sscanf(linebuf, "%s = %x", stringbuf, &valbuf);
+		}
+		if (strcmp(stringbuf, desc) == 0)
+			break;
+	}
+	if (strcmp(stringbuf, desc) != 0) {
+		printf("Setting - %s NOT FOUND\n",desc);
+		goto string_setting_done;
+	}
+
+	if (valbuf >= arrayrange[0] && valbuf <= arrayrange[1])
+		*variable = valbuf; 
+
+string_setting_done:
+
+	return;
+}
+
+void WRITE_SETTING_NUMHEX(FILE *f, const char *desc, unsigned int variable, const int *arrayrange) {
+	char stringbuf[256];
+
+	snprintf(stringbuf, sizeof(stringbuf), "#Value number from 0x%x - 0x%x (decimal)\n", arrayrange[0], arrayrange[1]);
+	fwrite(stringbuf, strlen(stringbuf), 1,f);
+
+	snprintf(stringbuf, sizeof(stringbuf), "%s = 0x%x\n", desc, variable);
+	fwrite(stringbuf, strlen(stringbuf), 1,f);
+
+	return;
+}
+
 
 static int rates[4] = { 11025, 22050, 44100, 48000 };
+static int scalenframeskip[2] = { 0, 10 };
+static int percentage[2] = { 0, 100 };
+static int signatureRange[2] = {0, 0xfffffffe};
+
+const char *ratesString[4] = {"11025", "22050", "44100", "48000"};
+const char *binaryChoice[2] = {"disabled", "enabled"};
+const char *audioDrivers[3] = {"sdl", "oss", "alsa"};
+const char *videomodeStrings[3] = {"auto", "ntsc", "pal"};
+const char *ntscmodeStrings[3] = {"composite", "svideo", "rgb"};
+const char *rendertypeStrings[3] = {"soft", "opengl", "opengl-bilinear"};
+const char *scalerStrings[4] = {"none", "ntsc", "scalex", "scalex-hq"};
+const char *prefsysStrings[4] = {"nes-ntsc", "nes-pal", "famicom", "dendy"};
 
 // constructor
 Settings::Settings()
@@ -27,6 +179,7 @@ Settings::Settings()
 	unsigned int signature;
 	char dirname[1024], *home;
 
+	char stringbuf[256];
 	// default settings
 	videomode = 0;
 	fullscreen = 0;
@@ -46,6 +199,13 @@ Settings::Settings()
 	litesurr = 0;
 	surmult = 40;
 	sndapi = 0;
+	scanlines = 0;
+	frameskip = 0;
+	bgr = 0;
+	speed = 2;
+	hwblit = 0;
+	soundskip = 0;
+	soundnowait = 0;
 
 	// try the recommended place for settings
 	home = getenv("HOME");
@@ -55,36 +215,45 @@ Settings::Settings()
 	if (f == NULL)
 	{
 		std::cout << "Settings file missing, using defaults\n";
+		writeSettings();
 		return;
 	}
 
 	// verify the file's magic number & version
-	READ_SETTING(signature);
+	READ_SETTING_NUMHEX(f, "NestopiaSettings", &signature, signatureRange);
 	if (signature != 0xaa550003)
 	{
 		std::cout << "Settings file invalid, using defaults\n";
 		fclose(f);
+		writeSettings();
 		return;
 	}
 
-	READ_SETTING(ntscmode);
-	READ_SETTING(videomode);
-	READ_SETTING(fullscreen);
-	READ_SETTING(scaler);
-	READ_SETTING(sprlimit);
-	READ_SETTING(rendertype);
-	READ_SETTING(scaleamt);
-	READ_SETTING(prefsys);
-	READ_SETTING(controls);
-	READ_SETTING(stereo);
-	READ_SETTING(sndapi);
-	READ_SETTING(volume);
-	READ_SETTING(rate);
-	READ_SETTING(configitem);
-	READ_SETTING(spatch);
-	READ_SETTING(exciter);
-	READ_SETTING(litesurr);
-	READ_SETTING(surmult);
+	READ_SETTING_STRING(f, "ntscmode", &ntscmode, ntscmodeStrings, __arraycount(ntscmodeStrings));
+	READ_SETTING_STRING(f, "videomode", &videomode, videomodeStrings, __arraycount(videomodeStrings));
+	READ_SETTING_STRING(f, "fullscreen", &fullscreen, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_STRING(f, "scaler", &scaler, scalerStrings, __arraycount(scalerStrings));
+	READ_SETTING_STRING(f, "sprlimit", &sprlimit, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_STRING(f, "rendertype", &rendertype, rendertypeStrings, __arraycount(rendertypeStrings));
+	READ_SETTING_NUM(f, "scaleamt", &scaleamt, scalenframeskip);
+	READ_SETTING_STRING(f, "prefsys", &prefsys, prefsysStrings, __arraycount(prefsysStrings));
+	READ_SETTING_STRING(f, "controls", &controls, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_STRING(f, "stereo", &stereo, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_STRING(f, "sndapi", &sndapi, audioDrivers, __arraycount(audioDrivers));
+	READ_SETTING_NUM(f, "volume", &volume, percentage);
+	READ_SETTING_STRING(f,"rate", &rate, ratesString, __arraycount(ratesString));
+	READ_SETTING_NUM(f, "configitem", &configitem, scalenframeskip);
+	READ_SETTING_STRING(f, "spatch", &spatch, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_STRING(f, "exciter", &exciter, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_STRING(f, "litesurr", &litesurr, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_NUM(f, "surmult", &surmult, percentage);
+	READ_SETTING_STRING(f, "scanlines", &scanlines, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_NUM(f, "frameskip", &frameskip, percentage);
+	READ_SETTING_STRING(f, "bgr", &bgr, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_NUM(f, "speed", &speed, scalenframeskip);
+	READ_SETTING_STRING(f, "hwsurfaceblit", &hwblit, binaryChoice, __arraycount(binaryChoice));
+	READ_SETTING_NUM(f, "soundskip", &soundskip, scalenframeskip);
+	READ_SETTING_STRING(f, "soundnowait", &soundnowait, binaryChoice, __arraycount(binaryChoice));
 
 	fclose(f);
 }
@@ -92,9 +261,14 @@ Settings::Settings()
 // destructor
 Settings::~Settings()
 {
+}
+
+void Settings::writeSettings()
+{
 	FILE *f;
 	unsigned int signature = 0xaa550003;	// magic number/version
 	char dirname[1024], *home;
+	char stringbuf[256];
 
 	// make sure the output directory exists
 	home = getenv("HOME");
@@ -109,25 +283,32 @@ Settings::~Settings()
 		return;
 	}
 
-	WRITE_SETTING(signature);
-	WRITE_SETTING(ntscmode);
-	WRITE_SETTING(videomode);
-	WRITE_SETTING(fullscreen);
-	WRITE_SETTING(scaler);
-	WRITE_SETTING(sprlimit);
-	WRITE_SETTING(rendertype);
-	WRITE_SETTING(scaleamt);
-	WRITE_SETTING(prefsys);
-	WRITE_SETTING(controls);
-	WRITE_SETTING(stereo);
-	WRITE_SETTING(sndapi);
-	WRITE_SETTING(volume);
-	WRITE_SETTING(rate);
-	WRITE_SETTING(configitem);
-	WRITE_SETTING(spatch);
-	WRITE_SETTING(exciter);
-	WRITE_SETTING(litesurr);
-	WRITE_SETTING(surmult);
+	WRITE_SETTING_NUMHEX(f, "NestopiaSettings", signature, signatureRange);
+	WRITE_SETTING_STRING(f, "ntscmode", ntscmode, ntscmodeStrings, __arraycount(ntscmodeStrings));
+	WRITE_SETTING_STRING(f, "videomode", videomode, videomodeStrings, __arraycount(videomodeStrings));
+	WRITE_SETTING_STRING(f, "fullscreen", fullscreen, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_STRING(f, "scaler", scaler, scalerStrings, __arraycount(scalerStrings));
+	WRITE_SETTING_STRING(f, "sprlimit", sprlimit, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_STRING(f, "rendertype", rendertype, rendertypeStrings, __arraycount(rendertypeStrings));
+	WRITE_SETTING_NUM(f, "scaleamt", scaleamt, scalenframeskip);
+	WRITE_SETTING_STRING(f, "prefsys", prefsys, prefsysStrings, __arraycount(prefsysStrings));
+	WRITE_SETTING_STRING(f, "controls", controls, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_STRING(f, "stereo", stereo, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_STRING(f, "sndapi", sndapi, audioDrivers, __arraycount(audioDrivers));
+	WRITE_SETTING_NUM(f, "volume", volume, percentage);
+	WRITE_SETTING_STRING(f, "rate", rate, ratesString, __arraycount(ratesString));
+	WRITE_SETTING_NUM(f, "configitem", configitem, scalenframeskip);
+	WRITE_SETTING_STRING(f, "spatch", spatch, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_STRING(f, "exciter", exciter, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_STRING(f, "litesurr", litesurr, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_NUM(f, "surmult", surmult, percentage);
+	WRITE_SETTING_STRING(f, "scanlines", scanlines, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_NUM(f, "frameskip", frameskip, percentage);
+	WRITE_SETTING_STRING(f, "bgr", bgr, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_NUM(f, "speed", speed, scalenframeskip);
+	WRITE_SETTING_STRING(f, "hwsurfaceblit", hwblit, binaryChoice, __arraycount(binaryChoice));
+	WRITE_SETTING_NUM(f, "soundskip", soundskip, scalenframeskip);
+	WRITE_SETTING_STRING(f, "soundnowait", soundnowait, binaryChoice, __arraycount(binaryChoice));
 
 	fclose(f);
 }
