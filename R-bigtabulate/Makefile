# $NetBSD: Makefile,v 1.5 2012/11/15 23:19:50 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	R table, tapply, and split-like functionality for (big.)matrix objects

R_PKGNAME=	bigtabulate
R_PKGVER=	1.1.0

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-bigmemory/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
