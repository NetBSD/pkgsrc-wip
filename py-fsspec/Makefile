# $NetBSD$

DISTNAME=	fsspec-2022.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
GITHUB_PROJECT=	filesystem_spec
MASTER_SITES=	${MASTER_SITE_GITHUB:=fsspec/}
MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/fsspec/filesystem_spec
COMMENT=	Specifications for pythonic filesystems
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-2022.7.1

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.6.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.18.3:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-vcr>=1.0.2:../../wip/py-test-vcr

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
