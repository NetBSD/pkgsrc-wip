# $NetBSD$

CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://www.rforge.net/png/
COMMENT=	Read and write PNG images
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	png
R_PKGVER=	0.1-7

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.9.0

.include "../../math/R/Makefile.extension"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
