# $NetBSD$

DISTNAME=	jeepney-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jeepney/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://gitlab.com/takluyver/jeepney
COMMENT=	Low-level pure Python DBus protocol wrapper
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
# not packaged: trio
# not packaged: testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
