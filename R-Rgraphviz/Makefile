# $NetBSD: Makefile,v 1.1.1.1 2012/05/10 10:54:15 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	http://www.bioconductor.org/packages/release/bioc/src/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bioconductor.org/packages/release/bioc/html/Rgraphviz.html
COMMENT=	Plotting capabilities for R graph objects

R_PKGNAME=	Rgraphviz
R_PKGVER=	1.34.0

LICENSE=	artistic-2.0

USE_LANGUAGES=  c

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
