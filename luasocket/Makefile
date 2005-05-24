# $NetBSD: Makefile,v 1.9 2005/05/24 10:31:00 rillig Exp $
#

DISTNAME=		luasocket-2.0-beta2
PKGNAME=		lua-socket-2.0b
CATEGORIES=		net
MASTER_SITES=		http://www.tecgraf.puc-rio.br/luasocket/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/luasocket/
COMMENT=		Gives socket capabilities to lua50

MAKEFILE=		${WRKSRC}/makefile.Linux
BUILD_TARGET=		all
USE_TOOLS+=		gmake

do-install:
	${INSTALL_LIB} ${WRKSRC}/luasocket.so.2.0 ${PREFIX}/lib/libluasocket.so.2.0
	${LN} -sf ${PREFIX}/lib/libluasocket.so.2.0 ${PREFIX}/lib/libluasocket.so
	${INSTALL_DATA_DIR} ${PREFIX}/lib/lua/
	${INSTALL_DATA} ${WRKSRC}/lua/*.lua ${PREFIX}/lib/lua/

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
