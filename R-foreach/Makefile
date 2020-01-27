# $NetBSD: Makefile,v 1.7 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/web/packages/foreach/index.html
COMMENT=	Foreach looping construct for R
LICENSE=	apache-2.0

R_PKGNAME=	foreach
R_PKGVER=	1.4.3

DEPENDS+=	R-iterators-[0-9]*:../../devel/R-iterators

BUILDLINK_API_DEPENDS.R+=	R>=2.5.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
