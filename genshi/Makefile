# $NetBSD: Makefile,v 1.1.1.1 2008/01/23 07:54:50 obache Exp $
#

DISTNAME=	Genshi-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://ftp.edgewall.com/pub/genshi/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../wip/babel

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
