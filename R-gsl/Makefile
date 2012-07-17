# $NetBSD: Makefile,v 1.2 2012/07/17 23:43:44 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/gsl/
COMMENT=	R wrapper for the Gnu Scientific Library

LICENSE=	gnu-gpl-v2

R_PKGNAME=	gsl
R_PKGVER=	1.9-9

BUILDLINK_API_DEPENDS.gsl+=	gsl>=1.12

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
