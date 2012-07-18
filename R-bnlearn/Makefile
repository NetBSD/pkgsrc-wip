# $NetBSD: Makefile,v 1.4 2012/07/18 11:14:48 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bnlearn.com/
COMMENT=	Bayesian network structure learning, parameter learning and inference

R_PKGNAME=	bnlearn
R_PKGVER=	3.0

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0

LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=  c fortran

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
