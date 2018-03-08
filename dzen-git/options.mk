# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.dzen

PKG_SUPPORTED_OPTIONS=	xft xpm xinerama
PKG_SUGGESTED_OPTIONS=	xpm xinerama

.include "../../mk/bsd.options.mk"

SUBST_CLASSES+=	config
SUBST_STAGE.config=	pre-build
SUBST_MESSAGE.config= Adapting config.mk to pkgsrc, according to package options
SUBST_FILES.config=	config.mk

###
### Enable XFT support
###
.if !empty(PKG_OPTIONS:Mxft)

# append to CFLAGS line
SUBST_SED.config+=	-e '22 s|$$| -DDZEN_XFT|'

# NetBSD-specific thing
.if ${OPSYS} == "NetBSD"
SUBST_SED.config+=	-e '22 s|$$| -I${X11BASE}/include/freetype2|'
.endif

# append to LIBS line
SUBST_SED.config+=	-e '21 s|$$| -lXft|'
.include "../../x11/libXft/buildlink3.mk"
.endif

###
### Enable XPM support
###
.if !empty(PKG_OPTIONS:Mxpm)
# append to CFLAGS line
SUBST_SED.config+=	-e '22 s|$$| -DDZEN_XPM|'
# append to LIBS line
SUBST_SED.config+=	-e '21 s|$$| -lXpm|'
.include "../../x11/libXpm/buildlink3.mk"
.endif

###
### Enable XINERAMA support
###
.if !empty(PKG_OPTIONS:Mxpm)
# append to CFLAGS line
SUBST_SED.config+=	-e '22 s|$$| -DDZEN_XINERAMA|'
# append to LIBS line
SUBST_SED.config+=	-e '21 s|$$| -lXinerama|'
.include "../../x11/libXinerama/buildlink3.mk"
.endif
