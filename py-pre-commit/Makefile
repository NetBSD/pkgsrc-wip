# $NetBSD$

DISTNAME=	pre_commit-3.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pre_commit/}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://pre-commit.com/
COMMENT=	Framework for managing and maintaining multi-language pre-commit hook
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 # upstream dropped support

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cfgv>=2.0.0:../../wip/py-cfgv
DEPENDS+=	${PYPKGPREFIX}-identify>=1.0.0:../../wip/py-identify
DEPENDS+=	${PYPKGPREFIX}-nodeenv>=0.11.1:../../wip/py-nodeenv
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.10.0:../../devel/py-virtualenv

USE_LANGUAGES=	# none
USE_TOOLS+=	bash

REPLACE_PYTHON=	pre-commit.py
REPLACE_BASH=	pre_commit/resources/hook-tmpl

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
