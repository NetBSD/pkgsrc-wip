# $NetBSD$

DISTNAME=	igraph-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/b3/ae/9d956c334b21f404a512b50abeae018a81e5be939a35c73b8291a31f7e24/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://igraph.org/
COMMENT=	Manipulating Undirected and Directed Graphs for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

USE_TOOLS+=	pkg-config

.include "../../lang/python/egg.mk"
.include "../../wip/igraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
