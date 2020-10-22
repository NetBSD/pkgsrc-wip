# $NetBSD$

DISTNAME=	compyle-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/compyle/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pypr/compyle
COMMENT=	Execute a subset of Python on HPC platforms
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8.5:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-mako>=1.1.3:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-pytools-[0-9]*:../../wip/py-pytools
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.5:../../devel/py-test

USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-cython+=	${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.19.2
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
