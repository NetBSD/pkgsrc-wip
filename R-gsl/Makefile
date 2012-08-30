# $NetBSD: Makefile,v 1.5 2012/08/30 19:03:42 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/gsl/
COMMENT=	R wrapper for the Gnu Scientific Library

R_PKGNAME=	gsl
R_PKGVER=	1.9-9

LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0
BUILDLINK_API_DEPENDS.gsl+=	gsl>=1.12

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
