# $NetBSD: Makefile,v 1.1.1.1 2009/11/05 07:24:16 ondratu Exp $
#

DISTNAME=	CherryPy-3.1.2
PKGNAME=        ${PYPKGPREFIX}-CherryPy-3.1.2

CATEGORIES=	python www
MASTER_SITES=	http://download.cherrypy.org/cherrypy/3.1.2/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PY_PATCHPLIST=  yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
