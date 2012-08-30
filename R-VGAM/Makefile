# $NetBSD: Makefile,v 1.1 2012/08/30 18:51:22 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.stat.auckland.ac.nz/~yee/VGAM/
COMMENT=	Vector Generalized Linear and Additive Models

R_PKGNAME=	VGAM
R_PKGVER=	0.8-7

BUILDLINK_API_DEPENDS.R+=	R>=2.14.0

LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
