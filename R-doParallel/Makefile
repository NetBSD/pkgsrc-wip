# $NetBSD: Makefile,v 1.5 2012/08/30 19:03:42 bubuchka Exp $

CATEGORIES=	devel math parallel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/doParallel/index.html
COMMENT=	Foreach parallel adaptor for the parallel package

R_PKGNAME=	doParallel
R_PKGVER=	1.0.1

LICENSE=	gnu-gpl-v2

BUILDLINK_API_DEPENDS.R+=	R>=2.14.0

.include "../../math/R/Makefile.extension"
.include "../../wip/R-foreach/buildlink3.mk"
.include "../../wip/R-iterators/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
