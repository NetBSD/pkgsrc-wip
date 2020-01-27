# $NetBSD: Makefile,v 1.9 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	http://bioconductor.org/packages/release/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://www.bioconductor.org/packages/release/bioc/html/graph.html
COMMENT=	R package to handle graph data structures
LICENSE=	artistic-2.0

R_PKGNAME=	graph
R_PKGVER=	1.46.0
DISTNAME=	biocGraph_${R_PKGVER}

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-BiocGenerics/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
