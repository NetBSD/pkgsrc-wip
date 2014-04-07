# $NetBSD: options.mk,v 1.1 2014/04/07 22:05:22 rhialto Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.unnethack
PKG_SUPPORTED_OPTIONS=  x11
PKG_SUGGESTED_OPTIONS=

# Support for the x11 option seems unreliable. 
# For instance, the configure script hardcodes references to /usr/X11R6,
# and Makefile.src needs patching for proper dependencies.
# In fact the below stuff *nearly* works... but somehow the configure
# script overrides our explicit settings for LIBXAW_CFLAGS and LIBXAW_LIBS.

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
CONFIGURE_ARGS+=	--enable-x11-graphics
CONFIGURE_ARGS+=	LIBXAW_CFLAGS=-I${X11BASE:Q}/include
CONFIGURE_ARGS+=	LIBXAW_LIBS=${X11_LDFLAGS:Q}" -lXaw"

BUILD_TARGET+=		x11tiles
BUILD_TARGET+=		rip.xpm
FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc
INSTALLATION_DIRS+=	lib/X11/app-defaults lib/X11/fonts/misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/dat/x11tiles \
	    ${DESTDIR}${GAMEDIR}
#	${INSTALL_DATA} ${WRKSRC}/win/X11/UnNetHack.ad \
#	    ${DESTDIR}${PREFIX}/lib/X11/app-defaults/UnNetHack
	${INSTALL_DATA} ${WRKSRC}/win/X11/nh10.bdf \
	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/ibm.bdf \
	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc \
	    ${DESTDIR}${GAMEDIR}/unnethack.x11.rc

.include "../../x11/libXaw/buildlink3.mk"
#.include "../../x11/libXpm/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"

.else
.endif

