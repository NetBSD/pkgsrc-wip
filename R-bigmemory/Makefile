# $NetBSD: Makefile,v 1.3 2012/07/17 23:43:43 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Manage massive matrices with shared memory and memory-mapped files

R_PKGNAME=	bigmemory
R_PKGVER=	4.2.11

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=  c++ #fortran77

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
