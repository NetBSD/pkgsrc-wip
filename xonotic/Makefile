# $NetBSD: Makefile,v 1.15 2022/09/11 12:51:50 wiz Exp $

DISTNAME=	xonotic-0.8.5
CATEGORIES=	games
MASTER_SITES=	https://dl.xonotic.org/
EXTRACT_SUFX=	.zip

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://xonotic.org/
COMMENT=	Fast arena-style FPS
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake gsed 7za bash zip pax perl:run
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

WRKSRC=			${WRKDIR}/Xonotic
BUILD_TARGET=		both
MAKE_ENV+=		MAKEFLAGS="-j ${_MAKE_JOBS_N:U1}"

REPLACE_PERL+=		server/rcon.pl
REPLACE_PERL+=		server/rcon2irc/rcon2irc.pl

ICON_SIZES=	16 24 32 64 128 256 512

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-msse
.endif

INSTALLATION_DIRS+=	share/applications
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/xonotic
INSTALLATION_DIRS+=	share/xonotic/data

do-install:
	${INSTALL_DATA} ${WRKSRC}/data/*.pk3 ${DESTDIR}${PREFIX}/share/xonotic/data
	${INSTALL_DATA} ${WRKSRC}/key_0.d0pk ${DESTDIR}${PREFIX}/share/xonotic
	${INSTALL_PROGRAM} ${WRKSRC}/source/darkplaces/darkplaces-sdl \
		${DESTDIR}${PREFIX}/bin/xonotic-sdl
	${INSTALL_PROGRAM} ${WRKSRC}/source/darkplaces/darkplaces-dedicated \
		${DESTDIR}${PREFIX}/bin/xonotic-dedicated
	cd ${WRKSRC} && ${PAX} -rw server ${DESTDIR}${PREFIX}/share/xonotic
.for f in xonotic-linux-dedicated.sh xonotic-linux-glx.sh xonotic-linux-sdl.sh
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/xonotic
.endfor
.for f in xonotic-linux64-dedicated xonotic-linux64-glx xonotic-linux64-sdl
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/xonotic
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/xonotic.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for s in ${ICON_SIZES}
	${INSTALL_DATA}	${WRKSRC}/misc/logos/icons_png/xonotic_${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/xonotic.png
.endfor

.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
