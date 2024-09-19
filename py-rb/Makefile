# $NetBSD$

DISTNAME=	rb-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rb/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/getsentry/rb
COMMENT=	The redis blaster
LICENSE=	apache-2.0


DEPENDS+=	redis>=4.0.9:../../databases/redis

.include "../../lang/python/egg.mk"
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
