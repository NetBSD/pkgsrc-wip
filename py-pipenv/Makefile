# $NetBSD$

DISTNAME=	pipenv-2022.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pipenv/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pypa/pipenv
COMMENT=	Python Development Workflow for Humans
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-towncrier>=19.2.0:../../wip/py-towncrier
TOOL_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.3.2:../../www/py-beautifulsoup4
TOOL_DEPENDS+=	${PYPKGPREFIX}-twine>=1.13.0:../../net/py-twine
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.4.4:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.3.0:../../devel/py-flake8
TOOL_DEPENDS+=	${PYPKGPREFIX}-black>=20.8:../../textproc/py-black
TOOL_DEPENDS+=	${PYPKGPREFIX}-parver>=0.3.1:../../wip/py-parver
TOOL_DEPENDS+=	${PYPKGPREFIX}-invoke>=1.4.1:../../sysutils/py-invoke
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-virtualenv-clone>=0.2.5:../../wip/py-virtualenv-clone
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=0:../../devel/py-virtualenv

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
