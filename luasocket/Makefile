# $NetBSD: Makefile,v 1.4 2004/05/09 19:38:37 blef Exp $
#

DISTNAME=		luasocket-2.0-alpha
PKGNAME=		luasocket-2.0alpha
CATEGORIES=		wip
MASTER_SITES=		http://www.tecgraf.puc-rio.br/~diego/luasocket/new/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~diego/luasocket/new/
COMMENT=		Gives socket capabilities to lua50

MAKEFILE=		${WRKSRC}/makefile
ALL_TARGET=		dyn
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/lua/
	${INSTALL_DATA} ${WRKSRC}/*.lua ${PREFIX}/lib/lua/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
