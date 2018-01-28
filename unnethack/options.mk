# $NetBSD: options.mk,v 1.3 2014/04/20 14:53:48 rhialto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unnethack
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=

# Support for the x11 option seems unreliable.
# For instance, the configure script hardcodes references to /usr/X11R6,
# and Makefile.src needs patching for proper dependencies.
# Furthermore when running, I quickly got a segfault.
#
# Unnethack installs 2 font files which conflict with nethack,
# but they are identical, so you could force it without much problem.

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
CONFIGURE_ARGS+=	--enable-x11-graphics
CONFIGURE_ARGS+=	LIBXAW_CFLAGS=-I${X11BASE}/include
CONFIGURE_ARGS+=	LIBXAW_LIBS=${X11_LDFLAGS:Q}" -lXaw"

BUILD_TARGET+=		x11tiles
BUILD_TARGET+=		rip.xpm
FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc
INSTALLATION_DIRS+=	lib/X11/app-defaults lib/X11/fonts/misc

MESSAGE_SRC+=		${.CURDIR}/MESSAGE.x11

post-install:
	${INSTALL_DATA} ${WRKSRC}/dat/x11tiles \
	    ${DESTDIR}${GAMEDIR}
	${INSTALL_DATA} ${WRKSRC}/win/X11/nh10.bdf \
	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/ibm.bdf \
	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc \
	    ${DESTDIR}${GAMEDIR}/unnethack.x11.rc

.include "../../x11/libXaw/buildlink3.mk"
#.include "../../x11/libXpm/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"

.endif
