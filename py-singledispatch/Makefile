# $NetBSD: Makefile,v 1.1 2014/12/07 00:16:18 jonthn Exp $

DISTNAME=	singledispatch-3.4.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/s/singledispatch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/singledispatch
COMMENT=	Library brings functools.singledispatch from Python 3.4
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	33 27 26  # included in 3.4+
PYTHON_VERSIONS_INCOMPATIBLE=	34

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
