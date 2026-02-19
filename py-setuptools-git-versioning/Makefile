# $NetBSD$

DISTNAME=	setuptools_git_versioning-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools-git-versioning/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/dolfinus/setuptools-git-versioning
COMMENT=	Use git repo data for building a version number according PEP-440
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
TOOL_DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml
.endif

USE_LANGUAGES=	# none


.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
