# $NetBSD$
#

DISTNAME=	memory_profiler-0.47
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/memory_profiler/}

MAINTAINER=	mike.volokhov@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/memory_profiler
COMMENT=	Module for monitoring memory usage of a python program
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-psutil>=2.1.3:../../sysutils/py-psutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
