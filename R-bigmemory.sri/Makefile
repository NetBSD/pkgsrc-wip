# $NetBSD: Makefile,v 1.2 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Shared resource interface for Bigmemory Project packages
LICENSE=	gnu-lgpl-v3

R_PKGNAME=	bigmemory.sri
R_PKGVER=	0.1.3

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
