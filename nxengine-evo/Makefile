# $NetBSD$

PKGNAME=	nxengine-evo-2.6.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=nxengine/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	nxengine-evo.tar.gz
DISTFILES+=	cavestoryen.zip
SITES.nxengine-evo.tar.gz=\
	-https://github.com/nxengine/nxengine-evo/archive/v${PKGVERSION_NOREV}.tar.gz
SITES.cavestoryen.zip=\
	-https://www.cavestory.org/downloads/cavestoryen.zip

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/nxengine/nxengine-evo
COMMENT=	Complete rewrite of the platform-adventure game Cave Story
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps
INSTALLATION_DIRS+=	share/nxengine-evo/data

pre-configure:
	${SED}  -e 's,@PREFIX@,${PREFIX},g' \
	    < ${FILESDIR}/nxengine-evo.sh.in > \
	    ${WRKDIR}/nx-evo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/nx \
	    ${DESTDIR}${PREFIX}/share/nxengine-evo/nx-evo
	${INSTALL_PROGRAM} ${WRKDIR}/nx-evo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vita/sce_sys/icon0.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/128x128/apps/nxengine-evo.png
	${INSTALL_DATA} ${FILESDIR}/nxengine-evo.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	cd ${WRKDIR}/CaveStory && ${PAX} -rw -pp . \
	    ${DESTDIR}${PREFIX}/share/nxengine-evo
	cd ${WRKSRC}/data && ${PAX} -rw -pp . \
	    ${DESTDIR}${PREFIX}/share/nxengine-evo/data
	cd ${DESTDIR}${PREFIX}/share/nxengine-evo && ${WRKSRC}/bin/extract

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
