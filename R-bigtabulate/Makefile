# $NetBSD: Makefile,v 1.3 2012/07/18 11:34:49 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	R table, tapply, and split-like functionality for (big.)matrix objects

R_PKGNAME=	bigtabulate
R_PKGVER=	1.0.13

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=  c++

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-bigmemory/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
