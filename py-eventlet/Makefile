# $NetBSD: Makefile,v 1.7 2015/01/18 22:09:42 jihbed Exp $

DISTNAME=	eventlet-0.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eventlet/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://eventlet.net/
COMMENT=	High performance network library using coroutines
LICENSE=	mit

WRKSRC=		${WRKDIR}/eventlet-0.16.1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.1:../../devel/py-greenlet
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
