# $NetBSD: Makefile,v 1.8 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Manage massive matrices with shared memory and memory-mapped files
LICENSE=	gnu-lgpl-v3

R_PKGNAME=	bigmemory
R_PKGVER=	4.5.33

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-bigmemory.sri/buildlink3.mk"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-BH/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
