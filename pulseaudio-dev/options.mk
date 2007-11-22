PKG_OPTIONS_VAR=	PKG_OPTIONS.pulseaudio
PKG_SUPPORTED_OPTIONS=	dbus gnome samplerate threads x11
PKG_SUGGESTED_OPTIONS=	threads samplerate

.include "../../mk/oss.buildlink3.mk"

.if !empty(OSS_TYPE:Mnative)
PKG_SUPPORTED_OPTIONS+= oss
PKG_SUGGESTED_OPTIONS+=	oss
.endif

.if ${OPSYS} == "Solaris" # XXXbjs: only works on solaris for now AFAIK.
PKG_SUPPORTED_OPTIONS+= sun
PKG_SUGGESTED_OPTIONS+=	sun
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.  if empty(PKG_OPTIONS:Mx11)
PKG_OPTIONS+=		x11
.  endif
CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-glib2
.  include "../../devel/GConf/buildlink3.mk"
.  include "../../devel/glib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gconf
CONFIGURE_ARGS+=	--disable-glib2
.endif

.if !empty(PKG_SUPPORTED_OPTIONS:Moss) && !empty(PKG_OPTIONS:Moss)
BUILDLINK_AUTO_VARS.oss=yes
CONFIGURE_ARGS+=	--enable-oss
USE_FEATURES.pulseaudio+=	oss-dsp
.  if ${OPSYS} == "NetBSD" # XXXbjs: others?  Is there a better way to do this?
MISSING_FEATURES+=		oss-dsp
PULSE_CPPFLAGS+=	-DDEVOSSSNDSTAT="\"/dev/audioctl\""
.  endif
PULSE_CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
PULSE_CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""
.else
BUILDLINK_AUTO_VARS.oss=no
CONFIGURE+ARGS+=	--disable-oss
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
.  if ${OPSYS} == "Linux" && ${OPSYS} == "FreeBSD" && ${OPSYS} == "DragonFly"
HAVE_TLS_BUILTIN=		yes
.  endif
DLOPEN_REQUIRE_PTHREADS=yes
RESOLV_AUTO_VARS=	yes
.  include "../../mk/resolv.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
CONFIGURE_ARGS+=	--enable-samplerate
.  include "../../audio/libsamplerate/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libsamplerate
.endif


.if !empty(PKG_SUPPORTED_OPTIONS:Msun) && !empty(PKG_OPTIONS:Msun)
CONFIGURE_ARGS+=	--enable-solaris
DEVSUNAUDIO=		${"${DEVOSSAUDIO}" != "":?${DEVOSSAUDIO}:/dev/audio}
PULSE_CPPFLAGS+=	-DDEVSUNAUDIO="\"${DEVSUNAUDIO}\""
.else
CONFIGURE_ARGS+=	--disable-solaris
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
LDFLAGS+=		${X11_LDFLAGS}
USE_DIRS+=		xdg-1.1
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../x11/libSM/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
