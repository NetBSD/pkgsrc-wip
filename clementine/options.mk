# $NetBSD$
PKG_OPTIONS_VAR=	PKG_OPTIONS.clementine
PKG_SUPPORTED_OPTIONS=	wiimote \
			devicekit \
			libmtp \
			gio \
			libgpod \
			audiocd \
			visualisations \
			moodbar \
			lastfm \
			box \
			dropbox \
			google-drive \
			amazon-cloud-drive \
			skydrive \
			pulseaudio
PKG_SUGGESTED_OPTIONS=	devicekit libmtp libgpod moodbar visualisations box dropbox google-drive amazon-cloud-drive skydrive
ARCH=			`uname -m`


.if  ${ARCH} == "x86"  ||  ${ARCH} == "x86_64"
PKG_SUGGESTED_OPTIONS+=	lastfm
.endif

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Options

###
### wiimote
###

.if !empty(PKG_OPTIONS:Mwiimote)
CMAKE_ARGS+=	-DENABLE_WIIMOTEDEV=ON
.else
CMAKE_ARGS+=	-DENABLE_WIIMOTEDEV=OFF
.endif

###
### devicekit
###

.if !empty(PKG_OPTIONS:Mdevicekit)
CMAKE_ARGS+=	-DENABLE_DEVICEKIT=ON
.else
CMAKE_ARGS+=	-DENABLE_DEVICEKIT=OFF
.endif

###
### libmtp
###

.if !empty(PKG_OPTIONS:Mlibmtp)
.	include "../../devel/libmtp/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_LIBMTP=ON
.else
CMAKE_ARGS+=	-DENABLE_LIBMTP=OFF
.endif

###
### gio
###

.if !empty(PKG_OPTIONS:Mgio)
CMAKE_ARGS+=	-DENABLE_GIO=ON
.else
CMAKE_ARGS+=	-DENABLE_GIO=OFF
.endif

###
### libgpod
###

.if !empty(PKG_OPTIONS:Mlibgpod)
.	include "../../audio/libgpod/buildlink3.mk"
.	include "../libusbmuxd/buildlink3.mk" # Will be moved to comms/
.	include "../../textproc/libplist/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_LIBGPOD=ON
.else
CMAKE_ARGS+=	-DENABLE_LIBGPOD=OFF
.endif

###
### audiocd
###

.if !empty(PKG_OPTIONS:Maudiocd)
.	include "../../misc/libcdio/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_AUDIOCD=ON
.else
CMAKE_ARGS+=	-DENABLE_AUDIOCD=OFF
.endif

###
### visualisations
###

.if !empty(PKG_OPTIONS:Mvisualisations)
CMAKE_ARGS+=	-DENABLE_VISUALISATIONS=ON
.else
CMAKE_ARGS+=	-DENABLE_VISUALISATIONS=OFF
.endif

###
### moodbar
###

.if !empty(PKG_OPTIONS:Mmoodbar)
CMAKE_ARGS+=	-DENABLE_MOODBAR=ON
.else
CMAKE_ARGS+=	-DENABLE_MOODBAR=OFF
.endif

###
### lastfm
###

.if !empty(PKG_OPTIONS:Mlastfm)
.	include "../../audio/liblastfm/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_LIBLASTFM=ON
.else
CMAKE_ARGS+=	-DENABLE_LIBLASTFM=OFF
.endif

###
### box
###

.if !empty(PKG_OPTIONS:Mbox)
CMAKE_ARGS+=	-DENABLE_BOX=ON
.else
CMAKE_ARGS+=	-DENABLE_BOX=OFF
.endif

###
### dropbox
###

.if !empty(PKG_OPTIONS:Mdropbox)
CMAKE_ARGS+=	-DENABLE_DROPBOX=ON
.else
CMAKE_ARGS+=	-DENABLE_DROPBOX=OFF
.endif

###
### google-drive
###

.if !empty(PKG_OPTIONS:Mgoogle-drive)
CMAKE_ARGS+=	-DENABLE_GOOGLE_DRIVE=ON
.else
CMAKE_ARGS+=	-DENABLE_GOOGLE_DRIVE=OFF
.endif

###
### amazon-cloud-drive
###

.if !empty(PKG_OPTIONS:Mamazon-cloud-drive)
CMAKE_ARGS+=	-DENABLE_AMAZON_CLOUD_DRIVE=ON
.else
CMAKE_ARGS+=	-DENABLE_AMAZON_CLOUD_DRIVE=OFF
.endif

###
### skydrive
###

.if !empty(PKG_OPTIONS:Mskydrive)
CMAKE_ARGS+=	-DENABLE_SKYDRIVE=ON
.else
CMAKE_ARGS+=	-DENABLE_SKYDRIVE=OFF
.endif

###
### pulseaudio
###

.if !empty(PKG_OPTIONS:Mpulseaudio)
.	include "../../audio/pulseaudio/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_PULSEAUDIO=ON
.else
CMAKE_ARGS+=	-DENABLE_PULSEAUDIO=OFF
.endif
