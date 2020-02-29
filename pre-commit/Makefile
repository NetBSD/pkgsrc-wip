# $NetBSD$

DISTNAME=	pre_commit-2.1.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pre_commit/}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://pre-commit.com/
COMMENT=	Framework for managing and maintaining multi-language pre-commit hook
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	38 37 36 # Only supports 3.6+ since pre-commit v2.0.0

DEPENDS+=	${PYPKGPREFIX}-aspy.yaml-[0-9]*:../../wip/py-aspy.yaml
DEPENDS+=	${PYPKGPREFIX}-cfgv>=2.0.0:../../wip/py-cfgv
DEPENDS+=	${PYPKGPREFIX}-conda-[0-9]*:../../wip/py-conda
DEPENDS+=	${PYPKGPREFIX}-identify>=1.0.0:../../wip/py-identify
DEPENDS+=	${PYPKGPREFIX}-nodeenv>=0.11.1:../../wip/py-nodeenv
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=15.2:../../devel/py-virtualenv

USE_LANGUAGES=	# none

REPLACE_PYTHON=	pre-commit.py pre_commit/resources/hook-tmpl

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
