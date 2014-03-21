# $NetBSD: Makefile,v 1.1 2014/03/21 21:08:35 jihbed Exp $

DISTNAME=	toro-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://pypi.python.org/packages/source/t/toro/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/ajdavis/toro/
COMMENT=	Synchronization primitives for Tornado coroutines
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}- pygments>=1.6:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
