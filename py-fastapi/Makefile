# $NetBSD$

DISTNAME=	fastapi-0.115.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastapi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://fastapi.tiangolo.com/
COMMENT=	Modern, fast (high-performance), web framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-pydantic>=1.8.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-starlette>=0.13.6:../../www/py-starlette
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals-[0-9]*:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-pydantic-settings-[0-9]*:../../devel/py-pydantic-settings
TEST_DEPENDS+=	${PYPKGPREFIX}-inline-snapshot-[0-9]*:../../devel/py-inline-snapshot
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
#TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-isort-[0-9]*:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator-[0-9]*:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
TEST_DEPENDS+=	${PYPKGPREFIX}-peewee-[0-9]*:../../databases/py-peewee
TEST_DEPENDS+=	${PYPKGPREFIX}-multipart-[0-9]*:../../www/py-multipart
#TEST_DEPENDS+=	${PYPKGPREFIX}-databases-[0-9]*:../../databases/py-databases
TEST_DEPENDS+=	${PYPKGPREFIX}-orjson-[0-9]*:../../textproc/py-orjson
TEST_DEPENDS+=	${PYPKGPREFIX}-JWT-[0-9]*:../../textproc/py-JWT
TEST_DEPENDS+=	${PYPKGPREFIX}-python-multipart-[0-9]*:../../www/py-python-multipart
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
TEST_DEPENDS+=	${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib
TEST_DEPENDS+=	${PYPKGPREFIX}-anyio-[0-9]*:../../devel/py-anyio
#TEST_DEPENDS+=	${PYPKGPREFIX}-types-ujson-[0-9]*:../../devel/py-types-ujson
#TEST_DEPENDS+=	${PYPKGPREFIX}-types-orjson-[0-9]*:../../devel/py-types-orjson
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
#TEST_DEPENDS+=	${PYPKGPREFIX}-jose-[0-9]*:../../devel/py-jose

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} fastapi fastapi-${PYVERSSUFFIX}

# as of 0.115.6
# 22 failed, 2234 passed, 130 skipped, 1 error

# TODO: needs unpackaged sqlmodel
pre-test:
	${RM} -f ${WRKSRC}/tests/test_tutorial/test_sql_databases/test_tutori*

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
