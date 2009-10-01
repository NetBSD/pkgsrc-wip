# $NetBSD: Makefile,v 1.15 2009/10/01 20:28:24 fhajny Exp $
#

DISTNAME=		luasocket-2.0.2
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
CATEGORIES=		net
MASTER_SITES=		http://luaforge.net/frs/download.php/2664/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~diego/professional/luasocket/
COMMENT=		Gives socket capabilities to lua
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=		${WRKSRC}/makefile
BUILD_TARGET=		all
USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/mime.so.1.0.2 ${DESTDIR}${PREFIX}/${LUA_CDIR}/mime.so
	${INSTALL_LIB} ${WRKSRC}/src/socket.so.2.0.2 ${DESTDIR}${PREFIX}/${LUA_CDIR}/socket.so
	${INSTALL_DATA} ${WRKSRC}/src/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
