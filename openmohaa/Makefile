# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	openmohaa-0.82.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=openmoh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openmohaa.org/
COMMENT=	Open re-implementation of Medal of Honor: Allied Assault
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		bison flex pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++23 filesystem

INSTALLATION_DIRS+=	bin
CMAKE_CONFIGURE_ARGS+=	-DUSE_INTERNAL_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_INTERNAL_MAD=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_INTERNAL_JPEG=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_INTERNAL_ZLIB=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LIBS=ON
PKGCONFIG_OVERRIDE+=	code/libmad/packaging/mad.pc.in
PLIST_SUBST+=		MACHINE_GNU_ARCH=${MACHINE_GNU_ARCH:Q}

SUBST_CLASSES+=		scripts
SUBST_STAGE.scripts=	pre-configure
SUBST_FILES.scripts=	omohaaded.sh openmohaa.sh
SUBST_VARS.scripts+=	PREFIX

post-extract:
	${CP} ${FILESDIR}/omohaaded.sh ${WRKSRC}/
	${CP} ${FILESDIR}/openmohaa.sh ${WRKSRC}/

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/omohaaded.sh ${DESTDIR}${PREFIX}/bin/omohaaded
	${INSTALL_SCRIPT} ${WRKSRC}/openmohaa.sh ${DESTDIR}${PREFIX}/bin/openmohaa

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
