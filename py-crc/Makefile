# $NetBSD$

DISTNAME=	crc-7.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nicoretti/crc
COMMENT=	Pure Python CRC library
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
