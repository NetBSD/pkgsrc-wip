$NetBSD: patch-Engine_libsrc_libcda-0.5_linux.c,v 1.1 2015/08/18 18:47:58 yhardy Exp $

Add CD support for NetBSD.

--- Engine/libsrc/libcda-0.5/linux.c.orig	2019-12-29 17:06:00.000000000 +0000
+++ Engine/libsrc/libcda-0.5/linux.c
@@ -3,14 +3,28 @@
  * Peter Wang <tjaden@users.sf.net>
  */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
+#ifdef __NetBSD__
+#include <sys/cdio.h>
+#define CDROMEJECT	CDIOCEJECT
+#define CDROMCLOSE	CDIOCCLOSE
+#define CDROMSTOP	CDIOCSTOP
+#define CDROMRESUME	CDIOCRESUME
+#define CDROMPAUSE	CDIOCPAUSE
+#define CDROMSUBCHNL	CDIOCREADSUBCHANNEL
+#define CDROMCLOSETRAY	CDIOCCLOSE
+#define CDROMREADTOCENTRY	CDIOREADTOCENTRIES
+#define cdrom_tocentry	cd_toc_entry
+#define cdrom_subchnl	cd_sub_channel_info
+#else
 #include <linux/cdrom.h>
+#endif
 #include <errno.h>
 #include "libcda.h"
 
@@ -42,8 +56,13 @@ static void copy_cd_error(void)
 static int get_tocentry(int track, struct cdrom_tocentry *e)
 {
     memset(e, 0, sizeof(struct cdrom_tocentry));
+#ifdef __NetBSD__
+    e->track = track;
+#endif
+#ifdef __linux__
     e->cdte_track = track;
     e->cdte_format = CDROM_MSF;
+#endif
     
     if (ioctl(fd, CDROMREADTOCENTRY, e) < 0) {
 	copy_cd_error();
@@ -57,11 +76,24 @@ static int get_tocentry(int track, struc
 static int get_subchnl(struct cdrom_subchnl *s)
 {
     memset(s, 0, sizeof(struct cdrom_subchnl));
+#ifdef __NetBSD__
+    struct ioc_read_subchannel rs;
+    rs.address_format = CD_MSF_FORMAT;
+    rs.data = s;
+    rs.data_len = sizeof(*s);
+    rs.data_format = CD_TRACK_INFO;
+    if (ioctl(fd, CDIOCREADSUBCHANNEL, &rs) < 0) {
+	copy_cd_error();
+	return -1;
+    }
+#endif
+#ifdef __linux__
     s->cdsc_format = CDROM_MSF;
     if (ioctl(fd, CDROMSUBCHNL, s) < 0) {
 	copy_cd_error();
 	return -1;
     }
+#endif
    
     return 0;
 }
@@ -103,6 +135,21 @@ void cd_exit()
 
 static int play(int t1, int t2)
 {
+#ifdef __NetBSD__
+    struct ioc_play_track pt;
+
+    pt.start_track = t1;
+    pt.start_index = 0;
+    pt.end_track = t1;
+    pt.end_index = 0;
+
+    if (ioctl(fd, CDIOCPLAYTRACKS, &pt) < 0) {
+	copy_cd_error();
+	return -1;
+    }
+
+    return 0;
+#else
 #ifdef USE_PLAYMSF
     struct cdrom_tocentry e0, e1;
     struct cdrom_msf msf;
@@ -148,6 +195,7 @@ static int play(int t1, int t2)
 
     return 0;
 #endif
+#endif
 }
 
 
@@ -191,8 +239,13 @@ int cd_current_track()
     struct cdrom_subchnl s;
 
     get_subchnl(&s);
+#ifdef __NetBSD__
+    if (s.header.audio_status == CD_AS_PLAY_IN_PROGRESS)
+	return s.what.track_info.track_number;
+#else
     if (s.cdsc_audiostatus == CDROM_AUDIO_PLAY)
 	return s.cdsc_trk;
+#endif
     else
 	return 0;
 }
@@ -225,7 +278,11 @@ int cd_is_paused()
     struct cdrom_subchnl s;
 
     get_subchnl(&s);
+#ifdef __NetBSD__
+    return (s.header.audio_status == CD_AS_PLAY_PAUSED);
+#else
     return (s.cdsc_audiostatus == CDROM_AUDIO_PAUSED);
+#endif
 }
 
 
@@ -243,6 +300,20 @@ void cd_stop()
  */
 int cd_get_tracks(int *first, int *last)
 {
+#ifdef __NetBSD__
+    struct ioc_toc_header toc;
+
+    if (ioctl(fd, CDIOREADTOCHEADER, &toc) < 0) {
+	copy_cd_error();
+	if (first) *first = 0;
+	if (last) *last = 0;
+	return -1;
+    }
+
+    if (first) *first = toc.starting_track;
+    if (last)  *last  = toc.ending_track;
+    return 0;
+#else
     struct cdrom_tochdr toc;
 
     if (ioctl(fd, CDROMREADTOCHDR, &toc) < 0) {
@@ -255,6 +326,7 @@ int cd_get_tracks(int *first, int *last)
     if (first) *first = toc.cdth_trk0;
     if (last)  *last  = toc.cdth_trk1;
     return 0;
+#endif
 }
 
 
@@ -264,11 +336,21 @@ int cd_get_tracks(int *first, int *last)
  */
 int cd_is_audio(int track)
 {
+#ifdef __NetBSD__
+    struct cd_toc_entry e;
+
+    if ((cd_get_tracks(0, 0) < 0) || (get_tocentry(track, &e) < 0))
+	return -1;
+    return (e.control & 4) ? 0 : 1;
+
+    return 0;
+#else
     struct cdrom_tocentry e;
 
     if ((cd_get_tracks(0, 0) < 0) || (get_tocentry(track, &e) < 0))
 	return -1;
     return (e.cdte_ctrl & CDROM_DATA_TRACK) ? 0 : 1;
+#endif
 }
 
 
@@ -277,11 +359,19 @@ int cd_is_audio(int track)
  */
 void cd_get_volume(int *c0, int *c1)
 {
+#ifdef __NetBSD__
+    struct ioc_vol vol;
+
+    ioctl(fd, CDIOCSETVOL, &vol);
+    if (c0) *c0 = vol.vol[0];
+    if (c1) *c1 = vol.vol[1];
+#else
     struct cdrom_volctrl vol;
 
     ioctl(fd, CDROMVOLREAD, &vol);
     if (c0) *c0 = vol.channel0;
     if (c1) *c1 = vol.channel1;
+#endif
 }
 
 
@@ -290,6 +380,15 @@ void cd_get_volume(int *c0, int *c1)
  */
 void cd_set_volume(int c0, int c1)
 {
+#ifdef __NetBSD__
+    struct ioc_vol vol;
+
+    vol.vol[0] = MID(0, c0, 255);
+    vol.vol[1] = MID(0, c1, 255);
+    vol.vol[2] = 0;
+    vol.vol[3] = 0;
+    ioctl(fd, CDIOCSETVOL, &vol);
+#else
     struct cdrom_volctrl vol;
 
     vol.channel0 = MID(0, c0, 255);
@@ -297,6 +396,7 @@ void cd_set_volume(int c0, int c1)
     vol.channel2 = 0;
     vol.channel3 = 0;
     ioctl(fd, CDROMVOLCTRL, &vol);
+#endif
 }
 
 
@@ -317,4 +417,4 @@ void cd_close()
     ioctl(fd, CDROMCLOSETRAY);
 }
 
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
