# $NetBSD: options.mk,v 1.5 2007/11/02 17:36:04 bsadewitz Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.mpg123
PKG_OPTIONS_SET.audio= jack portaudio esound nas sdl sun

.include "../../mk/oss.buildlink3.mk"

.if !empty(OSS_TYPE:Mnative)
PKG_OPTIONS_SET.audio+=	oss
PKG_SUGGESTED_OPTIONS+= mpg123-default-oss
.endif

PKG_OPTIONS_SET.default=	${PKG_OPTIONS_SET.audio:@.o.@mpg123-default-${.o.}@}

#
# !!! REDUCTIO AD ABSURDUM WARNING !!!
#
# XXX This can result in a duplicate option; this build system should be fixed.
# As of now, we must provide defaults for every scenario.
#
PKG_OPTIONS_NONEMPTY_SETS=	audio default

.include "../../mk/bsd.fast.prefs.mk"

#
# XXX notyet
#
#.if ${OPSYS} == "Darwin"
#PKG_SUPPORTED_OPTIONS+=	mpg123-macosx
#PKG_SUGGESTED_OPTIONS+= mpg123-macosx
#
#.  elif ${OPSYS} == "HPUX"
#PKG_SUPPORTED_OPTIONS+=	mpg123-hpux
#PKG_SUGGESTED_OPTIONS+= alib
#
#.  elif ${OPSYS} == "IRIX"
#PKG_SUPPORTED_OPTIONS+=	mpg123-irix
#PKG_SUGGESTED_OPTIONS+= mpg123-irix
#
#.  elif ${OPSYS} == "Solaris"		# Doesn't work with NetBSD (yet)
#PKG_SUPPORTED_OPTIONS+=	sun
#PKG_SUGGESTED_OPTIONS+= sun
#.endif

.include "../../mk/bsd.options.mk"

MPG123_DFLT_OUTPUT=	${PKG_OPTIONS:Mmpg123-default-*:S/mpg123-default-//}

CONFIGURE_ARGS+=	--with-default-audio=${MPG123_DFLT_OUTPUT}

.if !empty(PKG_OPTIONS:Moss) && ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--with-default-audio=oss
PLIST_SUBST+=		OSS=""
CONFIGURE_ENV=		HAVE_OSS=""

SUBST_CLASSES+=		oss
SUBST_FILES.oss=	configure.ac src/output/oss.c src/output/Makefile.am
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Setting OSS device.
SUBST_VARS.oss=		DEVOSSAUDIO DEVOSSSOUND
CONFIGURE_ENV+=		OSS_LIBS=${LIBOSSAUDIO:Q}
.else
PLIST_SUBST+=		OSS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mjack)
PLIST_SUBST+=		JACK=""
CONFIGURE_ENV+=		HAVE_JACK="yes"
.  include "../../wip/jack/buildlink3.mk"
.else
CONFIGURE_ENV+=		HAVE_JACK="no"
PLIST_SUBST+=		JACK="@comment "
.endif

.if !empty(PKG_OPTIONS:Msdl)
PLIST_SUBST+=		SDL=""
CONFIGURE_ENV+=		HAVE_SDL="yes"
.  include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ENV+=		HAVE_SDL="no"
PLIST_SUBST+=		SDL="@comment "
.endif

.if !empty(PKG_OPTIONS:Mnas)
PLIST_SUBST+=		NAS=""
CONFIGURE_ENV+=		HAVE_NAS="yes"
.  include "../../audio/nas/buildlink3.mk"
.else
CONFIGURE_ENV+=		HAVE_NAS="no"
PLIST_SUBST+=		NAS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
PLIST_SUBST+=		PORTAUDIO=""
CONFIGURE_ENV+=		HAVE_PORTAUDIO="yes"
.  include "../../audio/portaudio/buildlink3.mk"
.else
CONFIGURE_ENV+=		HAVE_PORTAUDIO="no"
PLIST_SUBST+=		PORTAUDIO="@comment "
.endif

.if !empty(PKG_OPTIONS:Mesound)
PLIST_SUBST+=		ESD=""
CONFIGURE_ENV+=		HAVE_ESD="yes"
.  include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ENV+=		HAVE_ESD="no"
PLIST_SUBST+=		ESD="@comment "
.endif

.if !empty(PKG_OPTIONS:Msun)
PLIST_SUBST+=		SUN=""
CONFIGURE_ENV+=		HAVE_SUN="yes"
.else
CONFIGURE_ENV+=		HAVE_SUN="no"
PLIST_SUBST+=		SUN="@comment "
.endif
