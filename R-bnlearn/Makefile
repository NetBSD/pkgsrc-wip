# $NetBSD: Makefile,v 1.7 2012/08/30 19:03:42 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bnlearn.com/
COMMENT=	Bayesian network structure learning, parameter learning and inference

R_PKGNAME=	bnlearn
R_PKGVER=	3.0

LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
