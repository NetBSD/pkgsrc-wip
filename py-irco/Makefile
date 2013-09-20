# $NetBSD: Makefile,v 1.1 2013/09/20 10:48:16 jihbed Exp $

DISTNAME=	irco-0.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/i/irco/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/GaretJax/irco
COMMENT=	International Research Collaboration Graphs
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-country>=0.19:../../wip/py-country
DEPENDS+=	${PYPKGPREFIX}-tablib-garetjax>=0.9.12:../../wip/py-tablib-garetjax
.include "../../mk/bsd.pkg.mk"
