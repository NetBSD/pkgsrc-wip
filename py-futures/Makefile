# $NetBSD: Makefile,v 1.3 2015/04/14 11:56:21 thomasklausner Exp $

DISTNAME=	futures-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/f/futures/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/pythonfutures/
COMMENT=	Library brings asynchronous computations from Python 3.x
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # included in 3+

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
