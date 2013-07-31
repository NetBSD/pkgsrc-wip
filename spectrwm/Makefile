# $NetBSD: Makefile,v 1.1 2013/07/31 19:54:12 shattered Exp $
#

DISTNAME=	spectrwm-2.3.0
CATEGORIES=	wm
MASTER_SITES=	https://opensource.conformal.com/snapshots/spectrwm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mike402@users.sourceforge.net
HOMEPAGE=	https://opensource.conformal.com/
COMMENT=	Small dynamic tiling window manager for X11
LICENSE=	isc

DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu

FETCH_USING=	curl
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "OpenBSD"
USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS+=	bin lib ${PKGMANDIR}/man1
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	MANINSTALL=maninstall
# sync with major.minor from ${WRKSRC}/lib/shlib_version.
CFLAGS+=	-DSWM_LIB=\"${PREFIX}/lib/libswmhack.so.0.0\"
.else
USE_TOOLS+=	gmake
CFLAGS+=	-I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
.  if ${OPSYS} == "Darwin"
BUILD_DIRS=	osx
.  else
BUILD_DIRS=	linux
.  endif
.endif

INSTALLATION_DIRS+=	share/examples/spectrwm

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.conf ${DESTDIR}${PREFIX}/share/examples/spectrwm
	${INSTALL_DATA} ${WRKSRC}/*.sh ${DESTDIR}${PREFIX}/share/examples/spectrwm

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
