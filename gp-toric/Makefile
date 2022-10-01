# $NetBSD$

GITHUB_PROJECT=	toric
GITHUB_TAG=	v1.9.5
DISTNAME=	Toric-1.9.5
PKGNAME=	gp-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=gap-packages/}
GITHUB_RELEASE=	v1.9.5
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.gap-system.org/Packages/toric.html
COMMENT=	Toric varieties and some combinatorial geometry
LICENSE=	mit

WRKSRC=		${WRKDIR}/toric
NO_BUILD=	YES
GAP_PKG_NAME=	${DISTNAME}

USE_LANGUAGES=	c
USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GAP_PKG_ROOT}
	cd ${WRKDIR} && pax -rw ${GAP_PKG_NAME} ${DESTDIR}${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
