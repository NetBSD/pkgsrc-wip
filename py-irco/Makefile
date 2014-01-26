# $NetBSD: Makefile,v 1.2 2014/01/26 15:49:55 thomasklausner Exp $

DISTNAME=	irco-0.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/i/irco/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/GaretJax/irco
COMMENT=	International Research Collaboration Graphs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-country>=0.19:../../wip/py-country
DEPENDS+=	${PYPKGPREFIX}-tablib-garetjax>=0.9.12:../../wip/py-tablib-garetjax

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-networkx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
