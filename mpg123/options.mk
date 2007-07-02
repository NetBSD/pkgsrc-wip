PKG_OPTIONS_VAR+=	PKG_OPTIONS.mpg123
PKG_SUPPORTED_OPTIONS+= jack portaudio esound nas sdl

CHECK_BUILTIN.oss:=	yes
. include "../../mk/oss.builtin.mk"
CHECK_BUILTIN.oss:=	no

.if !empty(IS_BUILTIN.oss:M[Yy][Ee][Ss])
PKG_SUPPORTED_OPTIONS+= oss
PKG_SUGGESTED_OPTIONS+= oss
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS+=	mpg123-macosx
PKG_SUGGESTED_OPTIONS+= mpg123-macosx

.  elif ${OPSYS} == "HPUX"
PKG_SUPPORTED_OPTIONS+=	mpg123-hpux
PKG_SUGGESTED_OPTIONS+= alib

.  elif ${OPSYS} == "IRIX"
PKG_SUPPORTED_OPTIONS+=	mpg123-irix
PKG_SUGGESTED_OPTIONS+= mpg123-irix

.  elif ${OPSYS} == "Solaris"		# Doesn't work with NetBSD (yet)
PKG_SUPPORTED_OPTIONS+=	sun
PKG_SUGGESTED_OPTIONS+= sun
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	--with-audio=oss

SUBST_CLASSES+=		ossdev
SUBST_FILES.ossdev=	src/audio_oss.c
SUBST_STAGE.ossdev=	pre-build
SUBST_MESSAGE.ossdev=	Setting OSS device.
SUBST_VARS.ossdev=	DEVOSSAUDIO DEVOSSSOUND

.  include "../../mk/oss.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--with-audio=jack

.  include "../../wip/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-audio=sdl

.  include "../../devel/SDL/buildlink3.mk
.endif

.if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=	--with-audio=nas

.  include "../../audio/nas/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CONFIGURE_ARGS+=	--with-audio=portaudio

.  include "../../audio/portaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--with-esd

.  include "../../audio/esound/buildlink3.mk"
.endif

.for _opt in ${PKG_OPTIONS}
CONFIGURE_ARGS+=	--with-audio=${_opt:Q}
SUBST_VARS.options+=	${_opt:C/mpg123-//:tu}
.endfor

.for _opt in ${PKG_SUPPORT

.endfor
