# $NetBSD: Makefile,v 1.4 2012/07/18 11:34:48 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Manage massive matrices with shared memory and memory-mapped files

R_PKGNAME=	bigmemory
R_PKGVER=	4.2.11

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=  c++ #fortran77

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
