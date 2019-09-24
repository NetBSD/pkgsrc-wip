# $NetBSD$

DISTNAME=	cannonball-0.3.20190924
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=djyt/}
GITHUB_TAG=	a675d7076e3ca5f7f7777e327ed27b04aae43072
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/djyt/cannonball/wiki
COMMENT=	Enhanced OutRun Engine
LICENSE=	mame-license

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		${WRKSRC}/cmake
CMAKE_ARGS.Linux+=	-DTARGET=debian
CMAKE_ARGS.NetBSD+=	-G "Unix Makefiles"
CMAKE_ARGS.NetBSD+=	-DTARGET=bsd
CMAKE_ARGS.NetBSD+=	-DBSD_PREFIX_PATH:STRING=${PREFIX}

INSTALLATION_DIRS+=	bin libexec share/cannonball share/cannonball/res \
			share/cannonball/conf ${PKGMANDIR}/man6

pre-configure:
	${MKDIR} ${WRKSRC}/build

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/cannonball.sh.in > \
	    ${WRKDIR}/cannonball.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/res/tilemap.bin \
	    ${DESTDIR}${PREFIX}/share/cannonball/res/tilemap.bin
	${INSTALL_DATA} ${WRKSRC}/build/res/tilepatch.bin \
	    ${DESTDIR}${PREFIX}/share/cannonball/res/tilepatch.bin
	${INSTALL_DATA} ${WRKSRC}/build/config.xml \
	    ${DESTDIR}${PREFIX}/share/cannonball/conf/config.xml
	${INSTALL_SCRIPT} ${WRKDIR}/cannonball.sh \
	    ${DESTDIR}${PREFIX}/bin/cannonball
	${INSTALL_PROGRAM} ${WRKSRC}/build/cannonball \
	    ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/docs/cannonball.6 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
