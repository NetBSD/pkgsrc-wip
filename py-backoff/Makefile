# $NetBSD$

DISTNAME=	backoff-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backoff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/litl/backoff
COMMENT=	Function decoration for backoff and retry
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# only for Python 3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
