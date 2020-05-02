# $NetBSD$

GITHUB_PROJECT=	endless-sky
PKGNAME=	${GITHUB_PROJECT}-0.9.12
DISTNAME=	${GITHUB_TAG}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=endless-sky/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://endless-sky.github.io/
COMMENT=	Space exploration and combat game similar to Escape Velocity
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v4.0 AND cc-by-sa-v3.0 AND public-domain

WRKSRC=		${WRKDIR}/endless-sky-${PKGVERSION_NOREV}
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=		${PYPKGPREFIX}-scons-[0-9]*:../../devel/scons
SCONS=			${PREFIX}/bin/scons
SCONS_ARGS+=		-C ${WRKSRC} DESTDIR=${DESTDIR} PREFIX=${PREFIX}

SUBST_CLASSES+=			fix-png
SUBST_STAGE.fix-png=		pre-configure
SUBST_MESSAGE.fix-png=		Fixing -lpng
SUBST_FILES.fix-png=		SConstruct
SUBST_SED.fix-png=		-e 's,"png","png16",g'

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing installation paths
SUBST_FILES.fix-paths=		SConstruct source/Files.cpp
SUBST_SED.fix-paths=		-e 's@/share/games/@/share/@g'
SUBST_SED.fix-paths+=		-e 's@/games@/bin@g'
SUBST_SED.fix-paths+=		-e 's@/share/man/@/${PKGMANDIR}/@g'
SUBST_VARS.fix-paths=		PREFIX

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS} install

JPEG_ACCEPTED=	libjpeg-turbo

.include "../../lang/python/pyversion.mk"

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
