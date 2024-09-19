# $NetBSD$

CATEGORIES=	math audio
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/package=signal
COMMENT=	Signal Processing
LICENSE=	gnu-gpl-v2

R_PKGNAME=	signal
R_PKGVER=	0.7-6

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.14.0

.include "../../math/R/Makefile.extension"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
