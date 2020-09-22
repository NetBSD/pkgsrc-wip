# $NetBSD$

DISTNAME=	hiq-projectq-0.6.4.post2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/4c/9f/1e7014d3e23fd7ab15e423025af134b723b34b2a33bc2dc726cdc81fcd46/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projectq.ch/
COMMENT=	Open source software framework for quantum computing
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-pybind11>=2.5.0:../../devel/py-pybind11
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.4:../../math/py-networkx
#DEPENDS+=	${PYPKGPREFIX}-scipy>=1.0.1:../../math/py-scipy

BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
