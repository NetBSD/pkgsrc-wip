# $NetBSD: Makefile,v 1.2 2012/07/17 23:43:43 bubuchka Exp $


CATEGORIES=	math devel
MASTER_SITES=	http://www.bioconductor.org/packages/release/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bioconductor.org/
COMMENT=	Generic functions for Bioconductor

R_PKGNAME=	BiocGenerics
R_PKGVER=	0.2.0

BUILDLINK_API_DEPENDS.R+=       R>=2.10.0

LICENSE=	artistic-2.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
