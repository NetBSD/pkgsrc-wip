# $NetBSD: Makefile,v 1.3 2012/09/10 11:22:44 jihbed Exp $
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
PYTHON_VERSIONS_ACCEPTED= 27 26 25

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
