# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	greenlet-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/g/greenlet/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://undefined.org/python/#greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED= 27 26 25
USE_LANGUAGES=	c 

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
