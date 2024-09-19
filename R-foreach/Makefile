# $NetBSD: Makefile,v 1.7 2013/03/19 01:22:55 bubuchka Exp $

MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkg-users@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/web/packages/foreach/index.html
COMMENT=	Foreach looping construct for R
LICENSE=	apache-2.0

R_PKGNAME=	foreach
R_PKGVER=	1.5.1

DEPENDS+=	R-iterators-[0-9]*:../../devel/R-iterators

# Packages suggested but not available: 'doMC', 'doParallel'
TEST_DEPENDS+=	R-randomForest-[0-9]*:../../math/R-randomForest

BUILDLINK_API_DEPENDS.R+=	R>=2.5.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
