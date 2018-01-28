# $NetBSD: options.mk,v 1.2 2015/02/07 09:43:30 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.firefox
PKG_SUPPORTED_OPTIONS=	official-mozilla-branding
PKG_SUPPORTED_OPTIONS+=	alsa debug debug-info mozilla-jemalloc gnome pulseaudio webrtc
PKG_SUPPORTED_OPTIONS+=	firefox-builtin-nss firefox-builtin-nspr

PLIST_SRC+=	PLIST

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	alsa mozilla-jemalloc
.else
PKG_SUGGESTED_OPTIONS+=	pulseaudio
.endif

PKG_SUGGESTED_OPTIONS+=	webrtc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mfirefox-builtin-nspr)
# do nothing
.else
CONFIGURE_ARGS+=	--with-system-nspr
.include "../../wip/nspr-hg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfirefox-builtin-nss)
# do nothing
.else
CONFIGURE_ARGS+=	--with-system-nss
.include "../../wip/nss-hg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus --enable-gnomeui
CONFIGURE_ARGS+=	--enable-extensions=gnomevfs
PLIST_SRC+=		PLIST.gnome
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-gnomeui
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
.  if ${CC_VERSION:S/gcc-//:S/.//g} >= 480
# Modern gcc does not run any "tracking" passes when compiling with -O0,
# which makes the generated debug info mostly useless. So explicitly
# request them.
O0TRACKING=-fvar-tracking-assignments -fvar-tracking
.  endif
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug="-g -O0 ${O0TRACKING}" --enable-debug-symbols --disable-optimize
CONFIGURE_ARGS+=	--disable-install-strip
.else
.  if !empty(PKG_OPTIONS:Mdebug-info)
CONFIGURE_ARGS+=	--enable-debug-symbols
.  else
CONFIGURE_ARGS+=	--disable-debug-symbols
.  endif
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--enable-install-strip
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
# XXX end

.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
CONFIGURE_ARGS+=	--enable-official-branding
LICENSE=		mozilla-trademark-license
RESTRICTED=		Trademark holder prohibits distribution of modified versions.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.else
PLIST_SRC+=		PLIST.nobranding
.endif

.if !empty(PKG_OPTIONS:Mwebrtc)
.include "../../graphics/libv4l/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-webrtc
.else
CONFIGURE_ARGS+=	--disable-webrtc
.endif
