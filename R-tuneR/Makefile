# $NetBSD$

CATEGORIES=	math audio
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/package=tuneR
COMMENT=	Analysis of Music and Speech
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	tuneR
R_PKGVER=	1.3.1

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.0.0

.include "../../math/R/Makefile.extension"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-signal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
