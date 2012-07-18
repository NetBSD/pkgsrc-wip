# $NetBSD: Makefile,v 1.6 2012/07/18 11:34:49 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	http://www.bioconductor.org/packages/release/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bioconductor.org/packages/release/bioc/html/graph.html
COMMENT=	R package to handle graph data structures

R_PKGNAME=	graph
R_PKGVER=	1.34.0

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0

LICENSE=	artistic-2.0

REPLACE_SH+=	inst/unitTests/*.sh

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-BiocGenerics/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
