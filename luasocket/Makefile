# $NetBSD: Makefile,v 1.12 2006/09/09 02:49:33 obache Exp $
#

DISTNAME=		luasocket-2.0.1
PKGNAME=		lua-socket-2.0.1
CATEGORIES=		net
MASTER_SITES=		http://luaforge.net/frs/download.php/1589/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cs.princeton.edu/~diego/professional/luasocket/
COMMENT=		Gives socket capabilities to lua

MAKE_FILE=		${WRKSRC}/makefile
BUILD_TARGET=		all
USE_TOOLS+=		gmake

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/socket.so.2.0.1 ${PREFIX}/lib/libluasocket.so.2.0.1
	${LN} -sf ${PREFIX}/lib/libluasocket.so.2.0.1 ${PREFIX}/lib/libluasocket.so
	${INSTALL_DATA_DIR} ${PREFIX}/lib/lua
	${INSTALL_DATA} ${WRKSRC}/src/*.lua ${PREFIX}/lib/lua

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
