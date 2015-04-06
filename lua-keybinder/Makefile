# $NetBSD: Makefile,v 1.1 2015/04/06 10:26:55 krytarowski Exp $

.include "../../wip/keybinder/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lua bindings for the keybinder library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	--disable-static
CONFIGURE_ARGS+=	--enable-lua
CONFIGURE_ARGS+=	--disable-python
# Don't rebuild the documentation
CONFIGURE_ARGS+=	--disable-gtk-doc

INSTALL_DIRS=	lua-keybinder

LUA_VERSIONS_ACCEPTED=	51

.include "../../wip/keybinder/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
