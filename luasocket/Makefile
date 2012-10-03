# $NetBSD: Makefile,v 1.18 2012/10/03 09:10:44 asau Exp $
#

DISTNAME=		luasocket-2.0.2
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
CATEGORIES=		net
MASTER_SITES=		http://luaforge.net/frs/download.php/2664/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.tecgraf.puc-rio.br/~diego/professional/luasocket/
COMMENT=		Gives socket capabilities to lua
LICENSE=		mit

MAKE_FILE=		makefile
USE_TOOLS+=		gmake

LDFLAGS.SunOS=		-lrt -lresolv

INSTALL_MAKE_FLAGS+=	INSTALL_TOP_SHARE=${DESTDIR}${PREFIX}/${LUA_LDIR}
INSTALL_MAKE_FLAGS+=	INSTALL_TOP_LIB=${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
