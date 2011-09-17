# $NetBSD: Makefile,v 1.1.1.1 2011/09/17 21:35:06 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Library of utilities for big.matrix objects of package bigmemory

R_PKGNAME=	biganalytics
R_PKGVER=	1.0.14

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=  c++

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../wip/R-bigmemory/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
