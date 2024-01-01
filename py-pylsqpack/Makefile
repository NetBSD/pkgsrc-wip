# $NetBSD$

DISTNAME=	pylsqpack-0.3.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylsqpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aiortc/pylsqpack
COMMENT=	Python wrapper for the ls-qpack QPACK library
LICENSE=	modified-bsd

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
