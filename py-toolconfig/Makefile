# $NetBSD$

DISTNAME=	pytoolconfig-1.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytoolconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bageljrkhanofemus/pytoolconfig
COMMENT=	Python tool configuration
LICENSE=	gnu-lgpl-v3

# needs py-pdm to build

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
