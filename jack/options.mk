# $NetBSD: options.mk,v 1.2 2007/03/23 21:35:23 bsadewitz Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.jack
PKG_SUPPORTED_OPTIONS=	sndfile portaudio readline
PKG_SUGGESTED_OPTIONS=	sndfile portaudio	# this will be changed when
						# the package is ready.

CHECK_BUILTIN.readline:= yes
.include "../../devel/readline/builtin.mk"
CHECK_BUILTIN.readline:= no

.if defined(USE_BUILTIN.readline) && !empty(USE_BUILTIN.readline:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS+=	readline
.endif

CHECK_BUILTIN.oss:= yes
.include "../../mk/oss.builtin.mk"
CHECK_BUILTIN.oss:= no

.if defined(USE_BUILTIN.oss)
PKG_SUPPORTED_OPTIONS+= oss
PKG_SUGGESTED_OPTIONS+= oss
.endif

.include "../../mk/bsd.options.mk"

.if (PKG_SUPPORTED_OPTIONS:Moss) && !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+= --enable-oss
LIBS+=		${LIBOSSAUDIO}
PLIST_SUBST+=	OSS=""
CPPFLAGS+= -DOSS_DRIVER_DEF_DEV="\"${DEVOSSAUDIO}\""

.include "../../mk/oss.buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-oss
PLIST_SUBST+=	OSS="@comment "
.endif

.if !empty(PKG_OPTIONS:Msndfile)
CONFIGURE_ARGS+= --enable-sndfile
PLIST_SUBST+=	SNDFILE=""

.include "../../audio/libsndfile/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-sndfile
PLIST_SUBST+=	SNDFILE="@comment "
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CONFIGURE_ARGS+= --enable-portaudio
PLIST_SUBST+=	PORTAUDIO=""

.include "../../audio/portaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-portaudio
PLIST_SUBST+=	PORTAUDIO="@comment "
.endif

.if !empty(PKG_OPTIONS:Mreadline)
PLIST_SUBST+=	JACK_TRANS=""
BROKEN_READLINE_DETECTION=	yes

.include "../../devel/readline/buildlink3.mk"
.else
PLIST_SUBST+=	JACK_TRANS="@comment "
.endif

#.if !empty(PKG_OPTIONS:Mfreebob)
#CONFIGURE_ARGS+= --enable-freebob

#.include "../../audio/freebob/buildlink3.mk"
#.else
CONFIGURE_ARGS+= --disable-freebob	# XXX disable for now
#.endif

#.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+= --enable-alsa

#.include "../../audio/alsa/buildlink3.mk"
#.else
CONFIGURE_ARGS+= --disable-alsa		# XXX disable for now
#.endif
