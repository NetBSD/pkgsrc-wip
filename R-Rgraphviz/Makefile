# $NetBSD: Makefile,v 1.8 2012/11/16 01:34:38 bubuchka Exp $

CATEGORIES=	graphics math
MASTER_SITES=	http://www.bioconductor.org/packages/2.10/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bioconductor.org/packages/release/bioc/html/Rgraphviz.html
COMMENT=	Plotting capabilities for R graph objects

R_PKGNAME=	Rgraphviz
R_PKGVER=	1.34.2

LICENSE=	artistic-2.0

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.6.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
