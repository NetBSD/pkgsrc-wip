# $NetBSD: Makefile,v 1.1 2014/03/19 22:17:19 jihbed Exp $

DISTNAME=	mplh5canvas-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mplh5canvas/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/mplh5canvas/
COMMENT=	Matplotlib backend based on HTML5 Canvas
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGRPEFIX}-websocket>=0.7.9:../../wip/py-websocket

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
