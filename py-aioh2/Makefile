# $NetBSD$

DISTNAME=	aioh2-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioh2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/decentfox/aioh2
COMMENT=	HTTP/2 implementation with hyper-h2 on Python 3 asyncio
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-h2>=3:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-priority>=1.3.0:../../www/py-priority

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
