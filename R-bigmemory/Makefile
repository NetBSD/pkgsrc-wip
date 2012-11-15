# $NetBSD: Makefile,v 1.7 2012/11/15 23:16:08 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Manage massive matrices with shared memory and memory-mapped files

R_PKGNAME=	bigmemory
R_PKGVER=	4.3.0

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-bigmemory.sri/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
