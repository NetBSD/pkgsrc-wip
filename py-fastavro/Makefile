# $NetBSD$

VERS=		1.0.0.post1
DISTNAME=	fastavro-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/${DISTNAME:S/${VERS}//}/}

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
