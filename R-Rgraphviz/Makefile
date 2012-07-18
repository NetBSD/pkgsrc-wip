# $NetBSD: Makefile,v 1.5 2012/07/18 11:34:48 bubuchka Exp $

CATEGORIES=	graphics math
MASTER_SITES=	http://www.bioconductor.org/packages/release/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.bioconductor.org/packages/release/bioc/html/Rgraphviz.html
COMMENT=	Plotting capabilities for R graph objects

R_PKGNAME=	Rgraphviz
R_PKGVER=	1.34.0

BUILDLINK_API_DEPENDS.R+=	R>=2.6.0

LICENSE=	artistic-2.0

USE_LANGUAGES=  c

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
