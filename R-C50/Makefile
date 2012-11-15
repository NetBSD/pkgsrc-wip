# $NetBSD: Makefile,v 1.1 2012/11/15 23:41:06 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://cran.r-project.org/web/packages/C50/index.html
COMMENT=	C5.0 decision trees and rule-based models

R_PKGNAME=	C50
R_PKGVER=	0.1.0-013

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
