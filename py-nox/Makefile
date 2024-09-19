# $NetBSD$

DISTNAME=	nox-2020.8.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nox/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://nox.thea.codes
COMMENT=	Flexible test automation
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.9.4:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-py>=1.4.0:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-tox>=3.20.1:../../devel/py-tox
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=14.0.0:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=2.0.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-colorlog>=4.6.2:../../wip/py-colorlog

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
