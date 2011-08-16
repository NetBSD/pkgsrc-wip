# $NetBSD: Makefile,v 1.1.1.1 2011/08/16 02:50:08 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bigmemory.org/
COMMENT=	Manipulation of massive matrices

R_PKGNAME=	bigmemory
R_PKGVER=	4.2.11

LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=  c++ #fortran77

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
