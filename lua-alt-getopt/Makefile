# $NetBSD: Makefile,v 1.1.1.1 2009/01/11 20:48:46 cheusov Exp $
#

PKGNAME=	${DISTNAME:S/lua_/lua-/:S/_/-/}
DISTNAME=	lua_alt_getopt-0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://mova.org/~cheusov/pub/lua_alt_getopt/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/lua_alt_getopt/
COMMENT=	getopt API for Lua similar to getopt_long(3)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

NO_BUILD=		yes
NO_CONFIGURE=		yes

LUAMODDIR=		${PREFIX}/share/lua/5.1

INSTALLATION_DIRS+=	${LUAMODDIR}

INSTALL_MAKE_FLAGS+=	LUAMODDIR=${LUAMODDIR}

.include "../../mk/bsd.pkg.mk"
