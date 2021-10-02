# $NetBSD: options.mk,v 1.8 2021/07/16 13:33:02 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qt6-qtmultimedia
PKG_OPTIONS_OPTIONAL_GROUPS=	platform
PKG_OPTIONS_GROUP.platform=	gstreamer pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		gstreamer
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	-gstreamer
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-no-gstreamer
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
MAKE_ENV+=	LFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib/pulseaudio
CONFIGURE_ARGS+=	-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-no-pulseaudio
.endif

PLIST_VARS+=		audioengine
.if ${OPSYS} == "QNX" || ${OPSYS} == "Darwin" || empty(PKG_OPTIONS:Mgstreamer)
PLIST.audioengine=	yes
.endif
