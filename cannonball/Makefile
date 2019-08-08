# $NetBSD$

DISTNAME=	cannonball-0.3.20171201
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=djyt/}
GITHUB_TAG=	0c0814d8233ee4e5be7beb309b8e16e0eecbb2e6
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/djyt/cannonball/wiki
COMMENT=	Enhanced OutRun Engine
LICENSE=	mame-license

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		..
BUILD_MAKE_FLAGS+=	VERBOSE=1

INSTALLATION_DIRS+=	bin libexec share/cannonball share/cannonball/res \
			share/cannonball/conf

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Set correct prefix in bsd.cmake
SUBST_FILES.prefix=	${WRKSRC}/cmake/bsd.cmake
SUBST_VARS.prefix=	PREFIX

pre-configure:
	${MKDIR} ${WRKSRC}/build

do-configure:
	cd ${WRKSRC}/build && cmake -G "Unix Makefiles" -DTARGET=bsd ${WRKSRC}/cmake

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

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
