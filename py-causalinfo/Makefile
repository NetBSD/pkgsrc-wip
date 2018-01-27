# $NetBSD$

DISTNAME=	causalinfo-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=c/causalinfo/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github/brettc/causalinfo/
COMMENT=	Information Measures on Causal Graphs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 1.1.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
