# $NetBSD: Makefile,v 1.4 2012/10/03 22:14:53 thomasklausner Exp $
#

DISTNAME=	rpyc-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/r/rpyc/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://rpyc.sourceforge.net/
COMMENT= Remote Python Call (RPyC), a transparent and symmetric RPC library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/rpyc-3.2.2

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
