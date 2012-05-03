# $NetBSD: Makefile,v 1.1.1.1 2012/05/03 22:37:49 bubuchka Exp $

CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/foreach/index.html
COMMENT=	Foreach looping construct for R

R_PKGNAME=	foreach
R_PKGVER=	1.4.0

LICENSE=	apache-2.0

.include "../../wip/R-iterators/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
