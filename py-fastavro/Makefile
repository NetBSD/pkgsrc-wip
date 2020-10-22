# $NetBSD$

DISTNAME=	fastavro-1.0.0.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/bd/bb/be327ed421ec063418ca2e328871f6b28f4efaeeef1bed5e3215c0140110/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/fastavro/fastavro
COMMENT=	Fast read/write of AVRO files
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=0:../../devel/py-flake8
#TEST_DEPENDS+=	${PYPKGPREFIX}-check-manifest>=0:../../wip/py-check-manifest
#TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0:../../lang/py-mypy

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
