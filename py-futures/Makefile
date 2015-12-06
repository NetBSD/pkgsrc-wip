# $NetBSD: Makefile,v 1.4 2015/05/03 13:32:58 jonthn Exp $

DISTNAME=	futures-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/f/futures/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/pythonfutures
COMMENT=	Library brings asynchronous computations from Python 3.x
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # included in 3+

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
