# $NetBSD$

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/iterators/
COMMENT=	Provides Iterator Construct for R
LICENSE=	apache-2.0

R_PKGNAME=	iterators
R_PKGVER=	1.0.9

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.5.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
