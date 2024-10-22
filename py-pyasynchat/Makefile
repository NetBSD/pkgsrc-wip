# $NetBSD$

DISTNAME=	pyasynchat-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyasynchat/}

MAINTAINER=	oskar@fessel.org
HOMEPAGE=	https://github.com/simonrob/pyasynchat
COMMENT=	Make asynchat available for Python 3.12 onwards
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-pyasyncore>=1.0.2:../../wip/py-pyasyncore

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
