# $NetBSD$

DISTNAME=	electrum_ecc-0.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=e/electrum_ecc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/electrum_ecc/
COMMENT=	Pure python ctypes wrapper for libsecp256k1
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE= 27
USE_LANGUAGES=	c
USE_TOOLS+=	automake autoconf gmake
USE_LIBTOOL=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
