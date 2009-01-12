# $NetBSD: Makefile,v 1.2 2009/01/12 18:46:38 cheusov Exp $
#

PKGNAME=	${DISTNAME:S/lua_/${LUA_PKGPREFIX}-/:S/_/-/}
DISTNAME=	lua_alt_getopt-0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://mova.org/~cheusov/pub/lua_alt_getopt/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/lua_alt_getopt/
COMMENT=	getopt API for Lua similar to getopt_long(3) function

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_LDIR}

INSTALL_MAKE_FLAGS+=	LUAMODDIR=${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
