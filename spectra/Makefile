# $NetBSD$

GITHUB_PROJECT=	spectra
DISTNAME=	v0.7.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=yixuan/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://spectralib.org/
COMMENT=	Header-only C++ library for large scale eigenvalue problems
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/spectra-0.7.0

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	c++ fortran

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/spectra
	cd ${WRKSRC}/include && pax -rw -pe . ${DESTDIR}${PREFIX}/include

.include "../../math/eigen3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
