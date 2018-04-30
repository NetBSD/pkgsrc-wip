# $NetBSD: Makefile,v 1.1 2014/03/15 19:36:36 jihbed Exp $

DISTNAME=	cocos2d-0.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://los-cocos.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/los-cocos/
COMMENT=	2D framework for games and multimedia
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pyglet>=1.1.4:../../wip/py-pyglet

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
