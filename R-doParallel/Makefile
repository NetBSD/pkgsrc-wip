# $NetBSD: Makefile,v 1.4 2012/07/18 11:34:49 bubuchka Exp $

CATEGORIES=	devel math parallel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/doParallel/index.html
COMMENT=	Foreach parallel adaptor for the parallel package

R_PKGNAME=	doParallel
R_PKGVER=	1.0.1

BUILDLINK_API_DEPENDS.R+=	R>=2.14.0

LICENSE=	gnu-gpl-v2

.include "../../math/R/Makefile.extension"
.include "../../wip/R-foreach/buildlink3.mk"
.include "../../wip/R-iterators/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
