# $NetBSD: Makefile,v 1.3 2012/07/17 23:43:44 bubuchka Exp $

CATEGORIES=	math devel
MASTER_SITES=	http://www.bioconductor.org/packages/release/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bioconductor.org/packages/release/bioc/html/graph.html
COMMENT=	R package to handle graph data structures

R_PKGNAME=	graph
R_PKGVER=	1.34.0

LICENSE=	artistic-2.0

REPLACE_SH+=	inst/unitTests/*.sh

USE_LANGUAGES=	c

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-BiocGenerics/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
