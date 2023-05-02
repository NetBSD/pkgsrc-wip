# $NetBSD$

DISTNAME=	json5-0.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/json5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dpranke/pyjson5
COMMENT=	Python implementation of the JSON5 data format
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
