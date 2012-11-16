# $NetBSD: Makefile,v 1.8 2012/11/16 00:15:30 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	http://www.bioconductor.org/packages/release/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bioconductor.org/packages/release/bioc/html/graph.html
COMMENT=	R package to handle graph data structures

R_PKGNAME=	graph
R_PKGVER=	1.36.1

LICENSE=	artistic-2.0

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-BiocGenerics/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
