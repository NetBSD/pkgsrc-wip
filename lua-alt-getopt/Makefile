# $NetBSD: Makefile,v 1.3 2009/01/14 19:49:08 cheusov Exp $
#

PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/}
DISTNAME=	lua-alt-getopt-0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/3915/ \
		http://mova.org/~cheusov/pub/lua_alt_getopt/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://luaforge.net/projects/alt-getopt/
COMMENT=	getopt API for Lua similar to getopt_long(3) function

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_LDIR}

INSTALL_MAKE_FLAGS+=	LUAMODDIR=${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
