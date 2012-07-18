# $NetBSD: Makefile,v 1.3 2012/07/18 11:14:48 bubuchka Exp $

CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/foreach/index.html
COMMENT=	Foreach looping construct for R

R_PKGNAME=	foreach
R_PKGVER=	1.4.0

BUILDLINK_API_DEPENDS.R+=	R>=2.5.0

LICENSE=	apache-2.0

.include "../../wip/R-iterators/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
