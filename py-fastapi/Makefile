# $NetBSD$

DISTNAME=	fastapi-0.70.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastapi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://fastapi.tiangolo.com/
COMMENT=	High performance, easy to learn, fast to code, ready for production
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dantic>=1.8.0:../../wip/py-dantic
DEPENDS+=	${PYPKGPREFIX}-starlette>=0.13.6:../../wip/py-starlette
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-isort-[0-9]*:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator-[0-9]*:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
TEST_DEPENDS+=	${PYPKGPREFIX}-peewee-[0-9]*:../../databases/py-peewee
#TEST_DEPENDS+=	${PYPKGPREFIX}-databases-[0-9]*:../../databases/py-databases
#TEST_DEPENDS+=	${PYPKGPREFIX}-orjson-[0-9]*:../../wip/py-orjson
TEST_DEPENDS+=	${PYPKGPREFIX}-ujson-[0-9]*:../../textproc/py-ujson
TEST_DEPENDS+=	${PYPKGPREFIX}-python-multipart-[0-9]*:../../www/py-python-multipart
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-anyio-[0-9]*:../../devel/py-anyio
#TEST_DEPENDS+=	${PYPKGPREFIX}-types-ujson-[0-9]*:../../devel/py-types-ujson
#TEST_DEPENDS+=	${PYPKGPREFIX}-types-orjson-[0-9]*:../../devel/py-types-orjson
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
#TEST_DEPENDS+=	${PYPKGPREFIX}-jose-[0-9]*:../../devel/py-jose

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
