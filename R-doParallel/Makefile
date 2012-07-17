# $NetBSD: Makefile,v 1.2 2012/07/17 23:43:44 bubuchka Exp $

CATEGORIES=	math devel parallel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/doParallel/index.html
COMMENT=	Foreach parallel adaptor for the parallel package

R_PKGNAME=	doParallel
R_PKGVER=	1.0.1

BUILDLINK_API_DEPENDS.R+=	R>=2.14.0

LICENSE=	gnu-gpl-v2

.include "../../wip/R-foreach/buildlink3.mk"
.include "../../wip/R-iterators/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
