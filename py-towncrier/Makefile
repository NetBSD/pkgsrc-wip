# $NetBSD$

DISTNAME=	towncrier-22.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/towncrier/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hawkowl/towncrier
COMMENT=	Building newsfiles for your project
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-default-group>=0:../../devel/py-click-default-group
DEPENDS+=	${PYPKGPREFIX}-incremental>=0:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-jinja2>=0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
