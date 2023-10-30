# $NetBSD$

DISTNAME=	nethsm-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nethsm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nitrokey/nethsm-sdk-py
COMMENT=	Python Library to manage NetHSM(s)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

IGNORE_INFO_DIRS=	${PYSITELIB}/nethsm/client/paths/info

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
