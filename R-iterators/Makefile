# $NetBSD: Makefile,v 1.5 2012/08/30 19:03:42 bubuchka Exp $

CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/iterators/index.html
COMMENT=	Iterator construct for R

R_PKGNAME=	iterators
R_PKGVER=	1.0.6

LICENSE=	apache-2.0

BUILDLINK_API_DEPENDS.R+=	R>=2.5.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
