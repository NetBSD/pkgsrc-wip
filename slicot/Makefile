# $NetBSD$

DISTNAME=	slicot_5.0+20101122.orig
PKGNAME=	slicot-5.0+20101122
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/slicot/}

MAINTAINER=	maya@NetBSD.org
HOMEPAGE=	http://ftp.debian.org/debian/pool/main/s/slicot/
COMMENT=	numerical algorithms from systems and control theory
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/slicot-5.0+20101122
USE_LANGUAGES=	fortran
USE_TOOLS+=	mkstemp

WRKSRC=		${WRKDIR}/${PKGNAME}/src

pre-build:
	cp ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
