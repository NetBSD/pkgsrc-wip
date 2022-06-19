# $NetBSD$

DISTNAME=	json-stream-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/json-stream/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/daggaz/json-stream
COMMENT=	Streaming JSON decoder
LICENSE=	mit

USE_LANGUAGES=	# none

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
