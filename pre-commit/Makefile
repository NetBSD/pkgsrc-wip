# $NetBSD$

DISTNAME=	pre_commit-2.8.2
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pre_commit/}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://pre-commit.com/
COMMENT=	Framework for managing and maintaining multi-language pre-commit hook
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	39 38 37 36 # Only supports 3.6+ since pre-commit v2.0.0

DEPENDS+=	${PYPKGPREFIX}-cfgv>=2.0.0:../../wip/py-cfgv
DEPENDS+=	${PYPKGPREFIX}-conda-[0-9]*:../../wip/py-conda
DEPENDS+=	${PYPKGPREFIX}-identify>=1.0.0:../../wip/py-identify
DEPENDS+=	${PYPKGPREFIX}-nodeenv>=0.11.1:../../wip/py-nodeenv
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-yaml>5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.0.8:../../wip/py-virtualenv20
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif
.if ${_PYTHON_VERSION} < 37
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
.endif

USE_LANGUAGES=	# none

REPLACE_PYTHON=	pre-commit.py pre_commit/resources/hook-tmpl

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
