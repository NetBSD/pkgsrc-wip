# $NetBSD: Makefile,v 1.5 2012/11/15 23:35:15 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Library of utilities for big.matrix objects of package bigmemory

R_PKGNAME=	biganalytics
R_PKGVER=	1.1.0

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-bigmemory/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
