# $NetBSD$

DISTNAME=	queuelib-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=q/queuelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/queuelib
COMMENT=	Collection of persistent (disk-based) queues
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	35 # not yet portes as of 1.4.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
