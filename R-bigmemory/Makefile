# $NetBSD: Makefile,v 1.2 2011/08/18 21:34:56 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Manage massive matrices with shared memory and memory-mapped files

R_PKGNAME=	bigmemory
R_PKGVER=	4.2.11

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=  c++ #fortran77

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
