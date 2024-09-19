# $NetBSD$

DISTNAME=	srsly-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/srsly/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/explosion/srsly
COMMENT=	Modern high-performance serialization utilities for Python
LICENSE=	mit

USE_LANGUAGES=	c c++

DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-test>=5.3.1:../../devel/py-test
DEPENDS+=	
${PYPKGPREFIX}-test-timeout>=1.4.2:../../devel/py-test-timeout
DEPENDS+=	${PYPKGPREFIX}-catalogue>=2.0.1:../../wip/py-catalogue

BUILDLINK_API_DEPENDS.py-cython+=       ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
