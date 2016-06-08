# $NetBSD: Makefile,v 1.3 2015/06/23 21:19:12 jonthn Exp $

DISTNAME=	trollius-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trollius/}

HOMEPAGE=	https://bitbucket.org/enovance/trollius/
COMMENT=	Module asyncio, for writing single-threaded concurrent code
LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME}
PLIST_VARS+=	pre33

.include "../../lang/python/egg.mk"

.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
PLIST.pre33=	yes
.endif

.include "../../mk/bsd.pkg.mk"
