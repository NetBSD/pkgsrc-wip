# $NetBSD$

DISTNAME=	datamodel_code_generator-0.75.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datamodel_code_generator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://datamodel-code-generator.koxudaxi.dev/
COMMENT=	Generate datamodels from OpenAPI, JSON Schema and more
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=2.10.1:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-black>=19.10:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-genson>=1.2.1:../../wip/py-genson
DEPENDS+=	${PYPKGPREFIX}-inflect>=4.1:../../lang/py-inflect
DEPENDS+=	${PYPKGPREFIX}-isort>=4.3.21:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.12:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.2.1:../../textproc/py-tomli
.endif

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/datamodel-codegen ${DESTDIR}${PREFIX}/bin/datamodel-codegen${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
