# $NetBSD$

DISTNAME=	sauerbraten_2013_04_04_collect_edition_linux
PKGNAME=	sauerbraten-2013_04_04
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sauerbraten/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sauerbraten.org/
COMMENT=	First-person shooter game based on Cube 2
LICENSE=	zlib AND cc-by-nc-sa-v3.0-license

USE_TOOLS+=	gmake pkg-config pax
USE_LANGUAGES=	c c++03

WRKSRC=		${WRKDIR}/sauerbraten
BUILD_DIRS+=	src

LDFLAGS.NetBSD+=	-lrt

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/doc/sauerbraten
INSTALLATION_DIRS+=	share/sauerbraten/data
INSTALLATION_DIRS+=	share/sauerbraten/packages

pre-configure:
	${SED}	-e 's,@PREFIX@,${PREFIX},g' \
		< ${FILESDIR}/sauerbraten.sh.in > \
		${WRKDIR}/sauer_client
	${SED}	-e 's,@PREFIX@,${PREFIX},g' \
		< ${FILESDIR}/sauerbraten.sh.in > \
		${WRKDIR}/sauer_server

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sauer_client \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/sauer_server \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sauer_client \
	    ${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/src/sauer_server \
	    ${DESTDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${FILESDIR}/sauerbraten.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/xcode/help/sauer16.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/16x16/apps/sauerbraten.png
	${INSTALL_DATA} ${WRKSRC}/src/xcode/help/sauer32.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/sauerbraten.png
	cd ${WRKSRC}/docs && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/doc/sauerbraten
	cd ${WRKSRC}/data && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/sauerbraten/data
	cd ${WRKSRC}/packages && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/sauerbraten/packages

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
