# $NetBSD: Makefile,v 1.1 2015/08/18 21:56:49 yhardy Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/Cairo/
COMMENT=	R graphics device using cairo graphics library f
LICENSE=	gnu-gpl-v2

R_PKGNAME=	Cairo
R_PKGVER=	1.5-9

.include "../../math/R/Makefile.extension"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
