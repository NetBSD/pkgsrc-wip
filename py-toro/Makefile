# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	toro-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toro/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/ajdavis/toro/
COMMENT=	Synchronization primitives for Tornado coroutines
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
