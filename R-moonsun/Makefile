# $NetBSD: Makefile,v 1.1 2013/12/03 00:00:43 hubertf Exp $

CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/moonsun/index.html
COMMENT=	Basic astronomical routines
LICENSE=	gnu-gpl-v2

R_PKGNAME=	moonsun
R_PKGVER=	0.1.2

BUILDLINK_API_DEPENDS.R+=	R>=2.5.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
