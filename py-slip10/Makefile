# $NetBSD$

DISTNAME=	slip10-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slip10/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/slip10/
COMMENT=	Reference implementation of the SLIP-0010 specification
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core

DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.9:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-base58>=2.1.0:../../converters/py-base58

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+= cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
