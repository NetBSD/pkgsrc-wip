# $NetBSD: Makefile,v 1.11 2013/03/19 01:38:40 bubuchka Exp $

CATEGORIES=	graphics math
MASTER_SITES=	http://www.bioconductor.org/packages/2.10/bioc/src/contrib/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://www.bioconductor.org/packages/release/bioc/html/Rgraphviz.html
COMMENT=	Plotting capabilities for R graph objects
LICENSE=	artistic-2.0

R_PKGNAME=	Rgraphviz
R_PKGVER=	1.34.2

USE_LANGUAGES=	c

CONFIGURE_ARGS+=		--with-graphviz=${BUILDLINK_PREFIX.graphviz}

BUILDLINK_API_DEPENDS.R+=	R>=2.6.0

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
