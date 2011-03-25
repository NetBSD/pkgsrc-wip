# $NetBSD: Makefile,v 1.2 2011/03/25 18:44:18 moubctez Exp $

DISTNAME=	CherryPy-3.2.0
PKGNAME=	${PYPKGPREFIX}-CherryPy-3.2.0
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none
EGG_NAME=		${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
