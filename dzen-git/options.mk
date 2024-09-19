# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.dzen

PKG_SUPPORTED_OPTIONS=	xft xpm xinerama
PKG_SUGGESTED_OPTIONS=	xpm xinerama

.include "../../mk/bsd.options.mk"

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-build
SUBST_MESSAGE.config=	Adapting config.mk to pkgsrc, according to package options
SUBST_FILES.config=	config.mk
SUBST_SED.config=	-e '/^CFLAGS =/	s|$$|'${DZEN_CFLAGS:Q}'|'
SUBST_SED.config+=	-e '/^LIBS =/	s|$$|'${DZEN_LIBS:Q}'|'

DZEN_CFLAGS=		# none
DZEN_LIBS=		# none

###
### Enable XFT support
###
.if !empty(PKG_OPTIONS:Mxft)

DZEN_CFLAGS+=		-DDZEN_XFT
.  if ${OPSYS} == "NetBSD"
DZEN_CFLAGS+=		-I${X11BASE}/include/freetype2
.  endif

# append to LIBS line
DZEN_LIBS+=		-lXft
.include "../../x11/libXft/buildlink3.mk"
.endif

###
### Enable XPM support
###
.if !empty(PKG_OPTIONS:Mxpm)
DZEN_CFLAGS+=		-DDZEN_XPM
DZEN_LIBS+=		-lXpm
.include "../../x11/libXpm/buildlink3.mk"
.endif

###
### Enable XINERAMA support
###
.if !empty(PKG_OPTIONS:Mxpm)
DZEN_CFLAGS+=		-DDZEN_XINERAMA
DZEN_LIBS+=		-lXinerama
.include "../../x11/libXinerama/buildlink3.mk"
.endif
