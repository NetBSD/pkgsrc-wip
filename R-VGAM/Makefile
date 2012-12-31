# $NetBSD: Makefile,v 1.3 2012/12/31 20:12:41 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.stat.auckland.ac.nz/~yee/VGAM/
COMMENT=	Vector Generalized Linear and Additive Models

R_PKGNAME=	VGAM
R_PKGVER=	0.9-0

LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.14.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
