# $NetBSD: Makefile,v 1.3 2015/04/07 16:14:35 krytarowski Exp $

.include "../../wip/keybinder/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lua bindings for the keybinder library
LICENSE=	gnu-gpl-v2

# --enable-lua is broken
CONFIGURE_ARGS+=	--disable-python

INSTALL_DIRS=	lua-keybinder

LUA_VERSIONS_ACCEPTED=	51

.include "../../wip/keybinder/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
